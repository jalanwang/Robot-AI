#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

//챕터 13. 객체 검출


// 템플릿 매칭
void show1() {
    cv::Mat img=cv::imread("circuit.bmp", cv::IMREAD_COLOR);
    cv::Mat templ=cv::imread("crystal.bmp", cv::IMREAD_COLOR);

    if(img.empty() || templ.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

     img=img+cv::Scalar(50,50,50); // 밝기 증가

     cv::Mat noise(img.size(), CV_32SC3);
     cv::randn(noise, cv::Scalar::all(0), cv::Scalar::all(30));
     cv::add(img, noise, img, cv::Mat(), CV_8UC3); // 가우시안 노이즈 추가

     cv::Mat res, res_norm;
     cv::matchTemplate(img, templ, res, cv::TM_CCOEFF_NORMED);
     cv::normalize(res, res_norm, 0, 255, cv::NORM_MINMAX, CV_8U);

     double maxv;
     cv::Point maxloc;
     cv::minMaxLoc(res, 0, &maxv, 0, &maxloc);

     std::cout << "Max value: " << maxv << std::endl;

     // 매칭 점수가 일정 수준(예: 0.5) 이상일 때만 결과 표시
     if (maxv > 0.5) {
         cv::rectangle(img, cv::Rect(maxloc.x, maxloc.y, templ.cols, templ.rows), cv::Scalar(0, 0, 255), 2);
     } else {
         std::cout << "Template not found!" << std::endl;
     }
    
     cv::imshow("templ", templ);
     cv::imshow("res_norm", res_norm);
     cv::imshow("img", img);
     cv::waitKey(0);
     cv::destroyAllWindows();

    return;
}

// detect faces using Haar Cascade Classifier
void show2() { 
    cv::Mat src=cv::imread("kids.png", cv::IMREAD_COLOR);
    if(src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }
    cv::CascadeClassifier classifier("haarcascade_frontalface_default.xml");
    if(classifier.empty()) {
        std::cerr << "XML load failed!" << std::endl;
        return;
    }

    std::vector<cv::Rect> faces;
    classifier.detectMultiScale(src, faces, 1.5, 5); // scaleFactor=1.5, minNeighbors=5

    for(cv::Rect rc : faces) {
        cv::rectangle(src, rc, cv::Scalar(255,0,255), 2);
    }

    cv::imshow("src", src);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}

// 눈 검출
void show3() {
     cv::Mat src=cv::imread("kids.png", cv::IMREAD_COLOR);
     if(src.empty()) {  
         std::cerr << "Image load failed!" << std::endl;
         return;
     }
     cv::CascadeClassifier face_classifier("haarcascade_frontalface_default.xml");
     cv::CascadeClassifier eye_classifier("haarcascade_eye.xml");
     
    if(eye_classifier.empty() || face_classifier.empty()) {
        std::cerr << "XML load failed!" << std::endl;
        return;
    }

    std::vector<cv::Rect > faces;
    face_classifier.detectMultiScale(src, faces, 1.5, 5); // scaleFactor=1.1, minNeighbors=5

    for(cv::Rect face : faces) {
        cv::rectangle(src, face, cv::Scalar(255,0,255), 2);

        cv::Mat face_roi=src(face);
        std::vector<cv::Rect> eyes;
        eye_classifier.detectMultiScale(face_roi, eyes, 1.1, 5); // scaleFactor=1.1, minNeighbors=5

        for(cv::Rect eye : eyes) {
            cv::Point center(eye.x + eye.width/2, eye.y + eye.height/2);            
            cv::circle(face_roi, center, eye.width/2, cv::Scalar(255,0,0), 2, cv::LINE_AA);
        }
    }

    cv::imshow("src", src);
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    return;
}

// 보행자 검출
void show4() {
     cv::VideoCapture cap("vtest.avi"); // 비디오 파일 열기
        if(!cap.isOpened()) {
            std::cerr << "Video load failed!" << std::endl;
            return;
        }

    cv::HOGDescriptor hog;
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

    cv::Mat frame;
    while(true) {
        cap >> frame;
        if(frame.empty()) break;

        std::vector<cv::Rect> detected;
        hog.detectMultiScale(frame, detected);

        for(cv::Rect r : detected) {
            cv::Scalar c=cv::Scalar(rand() % 256, rand() % 256, rand() % 256);
            cv::rectangle(frame, r, c, 2);
        }
        cv::imshow("frame", frame);
        if(cv::waitKey(10) == 27) break;
    }
    return;
}

// 보행자 검출 실시간
void show5() {
     cv::VideoCapture cap(0, cv::CAP_V4L2); // 카메라 열기
        if(!cap.isOpened()) {
            std::cerr << "Camera open failed!" << std::endl;
            return;
        }

    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

    cv::HOGDescriptor hog;
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

    cv::Mat frame;
    while(true) {
        cap >> frame;
        if(frame.empty()) break;

        std::vector<cv::Rect> detected;
        hog.detectMultiScale(frame, detected);

        for(cv::Rect r : detected) {
            cv::Scalar c=cv::Scalar(rand() % 256, rand() % 256, rand() % 256);
            cv::rectangle(frame, r, c, 2);
        }
        cv::imshow("frame", frame);
        if(cv::waitKey(10) == 27) break;
    }
    return;
}
//qr코드 검출
void show6() {
    cv::VideoCapture cap(0, cv::CAP_V4L2); // 카메라 열기
       if(!cap.isOpened()) {
           std::cerr << "Camera open failed!" << std::endl;
           return;
       }
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
    cv::QRCodeDetector qrDecoder;
    cv::Mat frame;
    while(true) {
        cap>>frame;
        if(frame.empty()) break;

        std::vector<cv::Point> points;

        cv::String info=qrDecoder.detectAndDecode(frame, points);

        if(!info.empty()) {
            std::cout << "QR Code: " << info << std::endl;
            cv::polylines(frame, points, true, cv::Scalar(0,0,255), 2);
            cv::putText(frame, info, cv::Point(10,30), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0,0,255));
        }
        cv::imshow("frame", frame);
        if(cv::waitKey(10) == 27) break;
    }

    return;
}