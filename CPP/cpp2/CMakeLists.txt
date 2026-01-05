cmake_minimum_required(VERSION 3.16)

# 프로젝트 이름과 사용 언어
project(CalculatorProject LANGUAGES CXX)

# 실행 파일이 생성될 경로를 소스 디렉토리 내 bin 폴더로 지정
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# C++ 표준 지정 (원하시는 버전으로 변경 가능: 11, 14, 17, 20 ...)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 실행 파일 생성: main.cpp 안에서 calculator.hpp를 include한다고 가정
add_executable(calculator_app
    main.cpp
    calculator.hpp
)