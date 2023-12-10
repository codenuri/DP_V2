#include <iostream>
#include <vector>

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};

int main()
{
	Rect* r1 = new Rect;
	Circle* c1 = new Circle;

	std::vector<Shape*> v;

	v.push_back( new Rect);
	v.push_back( new Circle);
	
}

