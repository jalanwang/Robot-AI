#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>


void show1() { // 다형성에 대한 내용도 담고 있다고 하는데 모르겠다.    
    cv::VideoCapture capture(0, cv::CAP_V4L2);
    if(!capture.isOpened()) {
        std::cerr << "카메라를 열 수 없습니다." << std::endl;
        return;
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
        if(cv::waitKey(10) == 27) break;
    }
    cv::destroyAllWindows();
    cv::waitKey(1); // 윈도우 종료 이벤트를 처리하기 위해 잠시 대기

    return;
}

// bool imwrite(const String& filename, InputArray img, const std::vector<int>& params = std::vector<int>());

void show2() {
    // 1. Vec3b 객체 생성 (B=255, G=0, R=0 - 파란색)
    // t=1이므로 인덱스 하나로 각 채널에 접근
    cv::Vec3b blue(255, 0, 0); 
    
    // 2. 인덱스(축) 하나를 사용하여 데이터 접근
    std::cout << "Blue channel: " << (int)blue[0] << std::endl; // Index 0
    std::cout << "Green channel: " << (int)blue[1] << std::endl; // Index 1
    
    // 3. 연산 (Scalar와 Vector의 곱)
    // 모든 성분에 0.5를 곱해 밝기를 낮춤
    cv::Vec3b half_blue = blue * 0.5; 
    
    // 4. 행렬(Matrix, t=2)의 특정 위치에 벡터(Vector, t=1) 대입
    cv::Mat img(100, 100, CV_8UC3,	cv::Scalar(255, 255, 255)); // 흰색 배경 이미지
    
    // (50, 50) 위치에 blue 벡터 대입
    img.at<cv::Vec3b>(50, 50) = blue; 

    std::cout << "Result Vector: " << half_blue << std::endl;

    return;
}


void show3() {
    cv::VideoCapture capture("stopwatch.avi");
    if(!capture.isOpened()) {
        std::cerr << "동영상이 없습니다." << std::endl;
        return;
    }

    // 동영상 파일 재생 시에는 포맷 설정이 필요하지 않습니다.
    // capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

    std::cout << "Movie Height: " << cvRound(capture.get(cv::CAP_PROP_FRAME_HEIGHT)) << std::endl;
    std::cout << "Movie Width: " << cvRound(capture.get(cv::CAP_PROP_FRAME_WIDTH)) << std::endl;
    std::cout << "Movie FPS: " << cvRound(capture.get(cv::CAP_PROP_FPS)) << std::endl;
    
    double fps = capture.get(cv::CAP_PROP_FPS);
    std::cout << "FPS: " << fps << std::endl;

    int delay=cvRound(1000/fps);
    std::cout << "Delay: " << delay << std::endl;
    
    cv::Mat frame, inversed;
    
    while(true) {
        capture >> frame;
        if(frame.empty()) break;

        inversed = ~frame;
        
        cv::imshow("Inversed", inversed);
        cv::imshow("Video", frame);
        if(cv::waitKey(delay/2) == 27) break;
    }
	//capture.release(); // 소멸자에서 자동 해제되므로 명시적 호출 불필요
	cv::destroyAllWindows();

    return;
}


void show4() {
	cv::VideoCapture capture(0);
	if(!capture.isOpened()) {
		std::cerr << "카메라를 열 수 없습니다." << std::endl;
		return;
	}

	// WSL2 등에서 타임아웃 방지를 위해 MJPG 포맷으로 설정
	capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
	std::cout << "Web CAM Height: " << cvRound(capture.get(cv::CAP_PROP_FRAME_HEIGHT)) << std::endl;
	std::cout << "Web CAM Width: " << cvRound(capture.get(cv::CAP_PROP_FRAME_WIDTH)) << std::endl;
	cv::Mat frame;

	double fps = capture.get(cv::CAP_PROP_FPS);
	if (fps == 0) fps = 30; // 일부 카메라는 FPS 정보를 제공하지 않을 수 있음
	std::cout << "Web CAM FPS: " << fps << std::endl;
	
	int delay = cvRound(1000 / fps);
	std::cout << "Delay: " << delay << std::endl;

	int frame_width = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_WIDTH));
	int frame_height = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_HEIGHT));

	cv::VideoWriter video("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(frame_width, frame_height));
	if (!video.isOpened()) {	
		std::cerr << "동영상 파일을 열 수 없습니다." << std::endl;
		return;
	}
	while(true) {
		capture >> frame;
		if(frame.empty()) break;
		//video.write(frame);	
		video << frame;
    	 
		cv::imshow("VIDEO", frame);
		if(cv::waitKey(10) == 27) break;
	}

	
	video.release();
	cv::destroyAllWindows();
	return;
}

void show5() {
	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::line(canvas, cv::Point(100, 100), cv::Point(500, 500), cv::Scalar(255, 0, 0), 2);

	imshow("Line Drawing", canvas);
	
	cv::waitKey(0);
	cv::destroyAllWindows();

	return;
}

void show6() { //arrow line
	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::arrowedLine(canvas, cv::Point(100, 100), cv::Point(500, 500), cv::Scalar(255, 0, 0), 2);

	imshow("Line Drawing", canvas);
	
	cv::waitKey(0);
	cv::destroyAllWindows();

	return;
}

void show7() { //marker
	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::drawMarker(canvas, cv::Point(100, 100), cv::Scalar(255, 0, 0), cv::MARKER_CROSS, 40, 2);

	imshow("Line Drawing", canvas);
	
	cv::waitKey(0);
	cv::destroyAllWindows();

	return;
}

// void show8() { //star BY LINE
// 	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
//     double radius=100;
//     double length=2*3.14*radius;
//     double rad=length/5;


    
//     cv::line(canvas, cv::Point(100, 100), cv::Scalar(255, 0, 0), cv::MARKER_CROSS, 40, 2);
//     cv::line(canvas, cv::Point(100, 100), cv::Scalar(255, 0, 0), cv::MARKER_CROSS, 40, 2);
//     cv::line(canvas, cv::Point(100, 100), cv::Scalar(255, 0, 0), cv::MARKER_CROSS, 40, 2);
//     cv::line(canvas, cv::Point(100, 100), cv::Scalar(255, 0, 0), cv::MARKER_CROSS, 40, 2);
//     cv::line(canvas, cv::Point(100, 100), cv::Scalar(255, 0, 0), cv::MARKER_CROSS, 40, 2);

// 	imshow("Line Drawing", canvas);
	
// 	cv::waitKey(0);
// 	cv::destroyAllWindows();

// 	return;
// }

void show9() { //circle, polyline
	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::circle(canvas, cv::Point(100, 100), 30, cv::Scalar(255, 0, 0), 1, 2);

    std::vector<cv::Point> pts;
    pts.push_back(cv::Point(250, 250));
    pts.push_back(cv::Point(300, 250));
    pts.push_back(cv::Point(350, 300));
    pts.push_back(cv::Point(350, 300));
    pts.push_back(cv::Point(350, 350));
    pts.push_back(cv::Point(250, 350));
    
    cv::polylines(canvas, pts, true, cv::Scalar(0,0,255), 2);
	imshow("Line Drawing", canvas);
	
	cv::waitKey(0);
	cv::destroyAllWindows();

	return;
}

void show10() { //text
	cv::Mat canvas(600, 600, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::putText(canvas, "Hello OpenCV", cv::Point(100, 100), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 0), 3);


	imshow("Line Drawing", canvas);
	
	cv::waitKey(0);
	cv::destroyAllWindows();

	return;
}

void show11() { //text
	cv::Mat img = cv::imread("lenna.bmp");

	cv::imshow("Lenna1", img);
    
    while(true)
    {
        int key_value=cv::waitKey(0);
        if(key_value=='i' or key_value == 'I')
        {
            cv::imshow("Lenna2", ~img);
        }
        
        else if(key_value==27 or key_value == 'q' or key_value =='Q') // ESC
        {
            std::cout << "종료" << std::endl;
            break;
        }

    }
	
	cv::destroyAllWindows();

	return;
}

void on_mouse12(int mouse_event, int x, int y, int flags, void* param)
{
    cv::Mat *img = (cv::Mat *)param;

    if (mouse_event == cv::EVENT_LBUTTONDOWN) {
        // 마우스 왼쪽 버튼 클릭 시 빨간색 원 그리기
        cv::circle(*img, cv::Point(x, y), 20, cv::Scalar(0, 0, 255), 2);
        cv::imshow("Lenna1", *img);
        std::cout << "Left Button Clicked at (" << x << ", " << y << ")" << std::endl;
    }
    else if (mouse_event == cv::EVENT_RBUTTONDOWN) {
        // 마우스 오른쪽 버튼 클릭 시 파란색 원 그리기
        cv::circle(*img, cv::Point(x, y), 20, cv::Scalar(255, 0, 0), 2);
        cv::imshow("Lenna1", *img);
        std::cout << "Right Button Clicked at (" << x << ", " << y << ")" << std::endl;
    }
    else if (mouse_event == cv::EVENT_MOUSEMOVE) {
        // 마우스 이동 시 좌표 출력 (너무 많으니 주석 처리 가능)
         std::cout << "Mouse Move: " << x << ", " << y << std::endl;
    }

    return;
}

void show12() { //mouse event
    cv::Mat img = cv::imread("lenna.bmp");
    if (img.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    cv::namedWindow("Lenna1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lenna1", img);
    
    // 콜백 함수에 이미지 포인터를 전달
    // void setMouseCallback(const String& winname, MouseCallback onMouse, void* userdata = 0);
    // 여기서 MouseCallback은 다음과 같은 함수 포인터 타입의 재정의(typedef)입니다:
    // typedef void (*MouseCallback)(int event, int x, int y, int flags, void* userdata);
    //
    // [문법적 설명]
    // 일반적인 typedef는 "typedef 기존타입 새로운이름;" (예: typedef int INT8;) 형태이지만,
    // 함수 포인터는 "변수 선언하는 모양" 앞에 typedef를 붙이는 방식입니다.
    //
    // Q: INT8은 int를 나타내고, (*MouseCallback)은 void를 나타내나요?
    // A: 아니요! MouseCallback이라는 이름이 "void (*)(int, int...)" 전체를 나타냅니다.
    //    - INT8 a;        == int a;
    //    - MouseCallback f; == void (*f)(int, int, int, int, void*);
    //
    // 즉, MouseCallback은 "void를 반환하고 int, int... 인자를 받는 함수 포인터"라는 긴 타입의 별명입니다.
    //
    // [상세 설명]
    // 1. typedef: 새로운 자료형 이름을 정의하겠다는 키워드입니다.
    // 2. void: 이 함수 포인터가 가리키는 함수는 반환값이 없어야 합니다.
    // 3. (*MouseCallback): 정의할 타입의 이름이 'MouseCallback'이며, 이것은 '함수의 주소'를 담는 포인터 변수임을 의미합니다.
    // 4. (int event, ...): 이 함수는 다음과 같은 5개의 인자를 받아야 합니다.
    //    - event: 발생한 마우스 이벤트의 종류 (예: 클릭, 이동 등)
    //    - x, y: 이벤트가 발생한 이미지 상의 좌표
    //    - flags: 이벤트 발생 시 눌린 특수키(Ctrl, Shift, Alt)나 마우스 버튼 상태
    //    - userdata: 사용자가 setMouseCallback 함수를 호출할 때 전달한 데이터의 포인터 (여기서는 &img)
    cv::setMouseCallback("Lenna1", on_mouse12, &img);

    cv::waitKey(0);     
    cv::destroyAllWindows();

    return;
}

static cv::Mat img;
static cv::Point old_pt;

void on_mouse13(int mouse_event, int x, int y, int flags, void* param)
{
//    cv::Mat *img = (cv::Mat *)param;

    switch(mouse_event) {
        case cv::EVENT_LBUTTONDOWN:
            std::cout << "Left Button Clicked at (" << x << ", " << y << ")" << std::endl;
            old_pt=cv::Point(x, y);
            break;
        case cv::EVENT_LBUTTONUP:
            std::cout << "Left Button Released at (" << x << ", " << y << ")" << std::endl;
            //new_pt=cv::Point(x, y);
            break;                    
        case cv::EVENT_MOUSEMOVE:
            std::cout << "Mouse Move: " << x << ", " << y << std::endl;
            if(flags & cv::EVENT_FLAG_LBUTTON) {
                cv::line(img, old_pt, cv::Point(x, y), cv::Scalar(0, 0, 255), 2);
                cv::imshow("Lenna1", img);
                old_pt=cv::Point(x, y);
            }
            break;

        default:
            break;
    }

    return;
}

void show13() { //mouse event
    img = cv::imread("lenna.bmp");
    if (img.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    cv::namedWindow("Lenna1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Lenna1", img);
    
    // 콜백 함수에 이미지 포인터를 전달
    cv::setMouseCallback("Lenna1", on_mouse13, nullptr);

    cv::waitKey(0);     
    cv::destroyAllWindows();

    return;
}

void on_level_changed(int level, void* userdata)
{
    cv::Mat *img = (cv::Mat*)userdata;

    img->setTo(level * 16);
    cv::imshow("Canvas", *img);
    return;
}

void show14() { 
    cv::Mat canvas(800, 800, CV_8UC1, cv::Scalar(0));

    cv::namedWindow("Canvas", cv::WINDOW_AUTOSIZE);
    cv::imshow("Canvas", canvas);

    // int createTrackbar(const String& trackbarname, const String& winname, int* value, int count, TrackbarCallback onChange = 0, void* userdata = 0);
    // 여기서 void* userdata = 0 은 0이라는 숫자가 아니라, Null Pointer(NULL, nullptr)를 의미합니다.
    // 즉, 사용자 데이터를 전달하지 않을 경우 기본값으로 아무것도 가리키지 않는 포인터를 사용한다는 뜻입니다.
    cv::createTrackbar("Level", "Canvas", 0, 16, on_level_changed, (void*)&canvas);
    
    cv::waitKey(0);     
    cv::destroyAllWindows();

    return;
}

void show15() { // 마스크를 이용한 특정 영역 색상 변경 (setTo)
    // 1. 원본 이미지 로드
    cv::Mat src = cv::imread("lenna.bmp");
    if (src.empty()) {          
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    // 2. 마스크 이미지 로드 (그레이스케일로 로드해야 함)
    // 마스크는 보통 0(검은색)과 255(흰색)으로 구성됨
    cv::Mat mask = cv::imread("mask_smile.bmp", cv::IMREAD_GRAYSCALE);
    if (mask.empty()) {          
        std::cerr << "Mask load failed!" << std::endl;
        return;
    }  

    // 3. 마스크 영역에 색상 설정
    // src 이미지에서 mask가 0이 아닌 위치(흰색 영역)의 픽셀 값을 (0, 255, 0) 초록색으로 변경
    src.setTo(cv::Scalar(0, 255, 0), mask); 

    cv::imshow("Masked Image", src);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}


void show16() { // 이미지 합성 (Copy To with Mask)
    // 1. 소스 이미지(비행기) 로드
    cv::Mat src = cv::imread("airplane.bmp");
    if (src.empty()) {          
        std::cerr << "Image load failed!" << std::endl;
        return;
    }

    // 2. 마스크 이미지 로드 (비행기 모양의 흰색 영역, 나머지는 검은색)
    // 마스크 이미지는 0이 아닌 픽셀에 대해서만 연산이 수행되도록 함
    cv::Mat mask = cv::imread("mask_plane.bmp");
    if (mask.empty()) {          
        std::cerr << "Mask load failed!" << std::endl;
        return;
    }  

    // 3. 대상 이미지(들판/배경) 로드
    cv::Mat dst = cv::imread("field.bmp");
    if (dst.empty()) {          
        std::cerr << "Mask load failed!" << std::endl;
        return;
    }

    // (참고) 마스크 이미지의 픽셀 값 합계 출력
    // 마스크가 제대로 로드되었는지, 혹은 마스크 영역(흰색 부분)이 존재하는지 확인하기 위함입니다.
    // 만약 합계가 0이라면 마스크가 완전히 검은색이라는 뜻이므로 합성이 일어나지 않습니다.
    cv::Scalar total_pixel_value = cv::sum(mask);
    std::cout << "Total Pixel Value in Mask: " << total_pixel_value << std::endl;

    cv::imshow("DST1", dst); // 합성 전 배경 이미지 출력
    
    // 4. 이미지 합성
    // src.copyTo(dst, mask)의 동작 원리:
    // 모든 픽셀 (x, y)에 대해, mask(x, y)가 0이 아니면 dst(x, y) = src(x, y)를 수행합니다.
    // mask(x, y)가 0이면(검은색), dst(x, y)는 원래 값을 유지합니다.
    // 결과적으로 마스크의 흰색 영역에 해당하는 src의 이미지만 dst에 합성됩니다.
    src.copyTo(dst, mask);

    cv::imshow("DST2", dst); // 합성 후 결과 이미지 출력
    cv::waitKey(0);
    cv::destroyAllWindows();

    return;
}