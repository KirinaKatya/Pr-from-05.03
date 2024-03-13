#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("C:/Users/Катя/Desktop/Python/mem.jpg");
    if (image.empty()) {
        std::cerr << "Unable to load image!" << std::endl;
        return -1;
    }
    int width = image.cols;
    int height = image.rows;
    /*
    cv::putText(image, "Width: " + std::to_string(width) + " pixels", cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1);
    cv::putText(image, "Height: " + std::to_string(height) + " pixels", cv::Point(10, 60), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1);
    
    cv::rectangle(image, cv::Point(50, 100), cv::Point(200, 250), cv::Scalar(0, 255, 0), 2); 
    cv::circle(image, cv::Point(300, 175), 50, cv::Scalar(0, 0, 255), 2);
    cv::rectangle(image, cv::Point(400, 450), cv::Point(250, 300), cv::Scalar(255, 0, 255), cv::FILLED);
    cv::line(image, cv::Point(200, 200), cv::Point(400, 200), cv::Scalar(255, 0, 0), 4);

    cv::imshow("Image", image);
    */

    cv::imshow("1", image(cv::Rect(0, 0, 250, 250)));
    cv::imshow("2", image(cv::Rect(250, 0, 250, 250)));
    cv::imshow("3", image(cv::Rect(0, 250, 250, 250)));
    cv::imshow("4", image(cv::Rect(250, 250, 250, 250)));
    cv::waitKey(0);

    cv::Mat mask = cv::Mat::zeros(image.size(), CV_8U);
    cv::Point center(250, 250);
    cv::circle(mask, center, 150, cv::Scalar(255), cv::FILLED);
    cv::Mat segment;
    image.copyTo(segment, mask);
    cv::imshow("with Mask", segment);
    cv::waitKey(0);

    return 0;
}
