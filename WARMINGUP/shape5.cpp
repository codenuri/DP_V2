#include <iostream>
#include <vector>

class no_implementation {};

class Shape
{
public:
	virtual void draw() = 0;

	virtual ~Shape() {}

	virtual Shape* clone() const // = 0
	{
		throw no_implementation();
	}
};


class Rect : public Shape
{
public:
	void draw() override  { std::cout << "draw Rect" << std::endl; }

	Rect* clone() const override
	{
		return new Rect(*this);
	}
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	Circle* clone() const override
	{
		return new Circle(*this);
	}
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 1. 객체의 생성과정을 OCP를 만족하게 할수 없을까 ?
		// 2. Undo/Redo 기능을 추가하려면 어떻게 해야 할까 ?

		if      ( cmd == 1 ) v.push_back(new Rect);
		else if ( cmd == 2 ) v.push_back(new Circle);
		else if ( cmd == 9 )
		{
			for (auto p : v) 
				p->draw(); 
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back( v[k]->clone() );
			
		}
	}
}

