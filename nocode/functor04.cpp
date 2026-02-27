#include <iostream>

// [전략 1] 단순 데이터 출력
void LogData(int sensorValue) {
    std::cout << "[Info] 데이터 수신: " << sensorValue << "\n";
}

// [전략 2] 경고 전송 (단점: 임계값 100이 하드코딩 되어 있거나 전역변수 써야 함)
void AlertData(int sensorValue) {
    if (sensorValue > 100) {
        std::cout << "[Alert] 위험 수치 감지! (" << sensorValue << ")\n";
    }
}

int main() {
    // 함수 포인터 선언
    void (*Processor)(int);

    // 1. 로깅 모드
    Processor = &LogData;
    Processor(50); 

    // 2. 경고 모드
    Processor = &AlertData;
    Processor(120); 

    return 0;
}