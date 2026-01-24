#include <iostream>
#include <string>
#include <functional> // std::function 사용 시 필수

// 1. 콜백 타입 정의 (작성하신 부분)
// C++11 이상에서는 typedef보다 'using'이 가독성과 템플릿 호환성 면에서 더 권장되지만, typedef도 문제없이 작동합니다.
typedef std::function<void(int, std::string)> ErrorHandler; 
// using ErrorHandler = std::function<void(int, std::string)>; // Modern C++ 스타일

class RobotController {
private:
    ErrorHandler onError; 

public:
    // 외부에서 콜백 함수를 주입받는 세터
    void setErrorCallback(ErrorHandler handler) {
        onError = handler;
    }

    // 로직 수행 중 에러 발생 시뮬레이션
    void detectAnomaly() {
        // 실제 장비 제어 로직...
        bool sensorError = true; // 가정

        if (sensorError && onError) {
            // 등록된 콜백 함수 실행 (Functor 호출)
            onError(500, "Servo Overload: Check Axis-1"); 
        }
    }
};

// --- [연동 예시] ---

// 방식 A: 일반 전역 함수
void globalErrorHandler(int code, std::string msg) {
    std::cout << "[Global Func] Error Code: " << code << " / Msg: " << msg << std::endl;
}

// 방식 B: 함수 객체 (Functor Class) - 상태를 가질 수 있음
class LogFileHandler {
public:
    void operator()(int code, std::string msg) {
        std::cout << "[Functor Class] Writing to log... " << msg << " (Code: " << code << ")" << std::endl;
    }
};

int main() {
    RobotController myRobot;

    // 1. 일반 함수 포인터 연결
    std::cout << "--- Case 1: Global Function ---" << std::endl;
    myRobot.setErrorCallback(globalErrorHandler);
    myRobot.detectAnomaly();

    // 2. 람다(Lambda) 표현식 연결 (가장 간결하고 많이 쓰임)
    std::cout << "\n--- Case 2: Lambda Expression ---" << std::endl;
    myRobot.setErrorCallback([](int code, std::string msg) {
        std::cout << "[Lambda] Emergency Stop triggered! " << msg << std::endl;
    });
    myRobot.detectAnomaly();

    // 3. 함수 객체(Functor) 연결
    std::cout << "\n--- Case 3: Functor Object ---" << std::endl;
    LogFileHandler fileLogger;
    myRobot.setErrorCallback(fileLogger);
    myRobot.detectAnomaly();

    return 0;
}