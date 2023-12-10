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

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }
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

			// k번째 도형의 복사본을 생성해서 v의 끝에 추가합니다.
			// 그런데, k번째 도형은 뭘까요 ?
			// 어떻게 만들어야 할까요 ?
			
		}
	}
}

