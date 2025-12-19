#include <opencv2/opencv.hpp>
#include <iostream>

int main() { // 다형성에 대한 내용도 담고 있다고 하는데 모르겠다.    
    cv::VideoCapture capture(0, cv::CAP_V4L2);
    if(!capture.isOpened()) {
        std::cerr << "카메라를 열 수 없습니다." << std::endl;
        return -1;
    }

    // WSL2 등에서 타임아웃 방지를 위해 MJPG 포맷으로 설정
    capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

    std::cout << "Web CAM Height: " << cvRound(capture.get(cv::CAP_PROP_FRAME_HEIGHT)) << std::endl;
    std::cout << "Web CAM Width: " << cvRound(capture.get(cv::CAP_PROP_FRAME_WIDTH)) << std::endl;


    cv::Mat frame, inversed;
    while(true) {
        capture >> frame;
        if(frame.empty()) break;

        cv::imshow("Video", frame);
        if(cv::waitKey(30) >= 0) break;
    }
    cv::destroyAllWindows();

    return 0;
}