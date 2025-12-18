// [링커 오류 해결 팁]
// LNK2019 오류가 발생하면 프로젝트 속성에서 라이브러리를 연결해야 합니다.
// 또는 버전을 정확히 안다면 아래 코드를 주석 해제하여 사용할 수 있습니다. (버전 4.10.0)
// #ifdef _DEBUG
// #pragma comment(lib, "opencv_world4100d.lib")
//#else
// #pragma comment(lib, "opencv_world4100.lib")
//#endif

#include "opencv2/opencv.hpp"
#include <iostream>

extern void show1();
extern void show2();

int main()
{
    std::cout << "Hello World!" << CV_VERSION << std::endl;

    // ./lenna.png 파일을 그레이스케일로 읽기
    // 주석의 의도대로 IMREAD_GRAYSCALE 플래그를 추가했습니다.
    //show1();
    show1();
    /*(
    cv::Mat src = cv::imread("./Lenna.png", cv::IMREAD_GRAYSCALE);

    if (src.empty()) {
        std::cerr << "Image load failed!" << std::endl; // 버퍼 없이 스트림 err로 출력한다.
        return -1;
    }

    cv::namedWindow("LENNA");
    
    // 결과 출력
    cv::imshow("LENNA", src);
    cv::waitKey(0);
	cv::destroyWindow("LENNA");
    */
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.