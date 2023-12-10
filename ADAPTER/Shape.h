// Shape.h
#pragma once

class Shape
{
public:
	virtual ~Shape() {}

	virtual void draw() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl;}
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl;}
};
