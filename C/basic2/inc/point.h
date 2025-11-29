//point.h
//header 파일 하는 역할: 함수 정의, 구조체 정의

//#ifndef _POINT_H_
//#define _POINT_H_
//..
//..
//#endif

#pragma once //요거 하나면 끝

typedef struct {
    int x;
    int y;
} Point;

extern Point Gpoint;
