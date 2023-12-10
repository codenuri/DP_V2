#include <iostream>
#include <vector>
#include <map>
#include "singleton.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using F = Shape*(*)(); 

	std::map<int, F> create_map; 

public:

	void register_shape(int key, F create_function)
	{
		create_map[key] = create_function;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		if (create_map[type] != nullptr)
		{
			p = create_map[type](); // 도형 생성
		}
		return p;
	}
};

class RegisterFactory
{	
public:
	RegisterFactory(int type, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(type, f);
	}
};

//RegisterFactory rf(1, &Rect::create);




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }


	static RegisterFactory rf;
};
RegisterFactory Rect::rf(1, &Rect::create);






class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	static RegisterFactory rf;
};
RegisterFactory Circle::rf(2, &Circle::create);




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품을 등록한다.
	// factory.register_shape(1, &Rect::create);
	// factory.register_shape(2, &Circle::create);

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)
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




