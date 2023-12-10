#include <iostream>
#include <vector>
#include "singleton.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		switch(type)
		{
			case 1: p = new Rect;   break;
			case 2: p = new Circle; break;
		}
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8) // 1 ~ 7 을 도형 번호로 예약
		{
			Shape* s = factory.create(cmd);

			if ( s )
				v.push_back(s);
		}


		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
	}
}




