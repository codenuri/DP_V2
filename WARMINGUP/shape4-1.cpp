#include <iostream>
#include <vector>

class Shape
{
public:
	virtual void draw() { std::cout << "draw Shape" << std::endl; }

	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override  { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

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

			if ( dynamic_cast<Rect*>(v[k]) != nullptr )
			{
				v.push_back( new Rect );
			}
			else if ( dynamic_cast<Circle*>(v[k]) != nullptr )
			{
				v.push_back( new Circle );
			}

		}
	}
}

