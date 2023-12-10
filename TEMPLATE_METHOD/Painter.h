#pragma once
#include <iostream>

// Painter & PainterPath 클래스 의도
// 1. 수십 ~ 수백가지의 그림을 그리는 메소드를 제공하는 클래스
// 2. 먼저, PainterPath 클래스로 그림을 그리고(내부적으로 비트맵에 그림을 그리고)
// 3. Painter 를 사용해서 "비트맵"을 실제 화면에 그리는 역활 
// 

class PainterPath
{
public:
	void begin(){}
	void end()  {}

	void draw_rect()   { std::cout << "draw rect" << std::endl; }
	void draw_circle() { std::cout << "draw circle" << std::endl; }
};

class Painter
{
public:
	void draw_path(const PainterPath& path) {}
};
