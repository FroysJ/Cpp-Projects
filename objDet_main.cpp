//
// Created by Froys on 09/08/2024.
//

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

// int main(int argc, char** argv) {
//     if (argc != 2) {
//         cerr << "Usage: " << argv[0] << " <img1.jpg>" << endl;
//         return -1;
//     }
int main() {
    string imageFile = "../img3.jpg"; // argv[1];
    string modelFile = "mobilenet_iter_73000.caffemodel";
    string configFile = "deploy.prototxt";

    dnn::Net net = dnn::readNetFromCaffe(configFile, modelFile);
    if (net.empty()) {
        cerr << "Failed to load network." << endl;
        return -1;
    }

    Mat frame = imread(imageFile);

    if (frame.empty()) {
        cerr << "Error opening image file." << endl;
        return -1;
    }

    Mat blob;
    dnn::blobFromImage(frame, blob, 1.0, Size(300,300), Scalar(127.5,127.5,127.5), true, false);
    net.setInput(blob);

    Mat output = net.forward();

    vector<String> layerNames = net.getLayerNames();
    for (size_t i = 0; i < layerNames.size(); i++) {
        cout << "Layer " << i << ": " << layerNames[i] << endl;
    }

    cout << "Output dimensions and shape: " << output.size() << " " << output.dims << endl;
    cout << "Output shape: ";
    for (int i = 0; i < output.dims; i++) {
        cout << output.size[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < output.size[2]; i++) {
        float* data = (float*) output.ptr<float>(0,0,i);

        cout << "Data for detection " << i << ": ";
        for (int j = 0; j < 7; j++) {
            cout << data[j] << " ";
        }
        cout << endl;

        float confidence = data[2];

        if (confidence > 0.2) {
            cout << "Object detected" << endl;
            int x1 = static_cast<int>(data[3] * frame.cols);
            int y1 = static_cast<int>(data[4] * frame.rows);
            int x2 = static_cast<int>(data[5] * frame.cols);
            int y2 = static_cast<int>(data[6] * frame.rows);
            rectangle(frame, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2);
        }
    }

    imshow("Object Detection", frame);
    waitKey(0);

    destroyAllWindows();

    return 0;
}