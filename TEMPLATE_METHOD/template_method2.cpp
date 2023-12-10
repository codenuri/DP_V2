#include <iostream>
#include "Painter.h"

class Shape
{
public:
	virtual ~Shape() {}

	void draw() 
	{
		PainterPath path;
		path.begin();

		// path 멤버 함수로 그림을 그린다.
		draw_imp(path);

		path.end();

		Painter surface;
		surface.draw_path(path);		
	}

protected:
	virtual void draw_imp(PainterPath& path) = 0;
};



class Rect : public Shape
{
protected:
	void draw_imp(PainterPath& path) override
	{
		path.draw_rect();
	}
};


class Circle : public Shape
{
protected:
	void draw_imp(PainterPath& path) override
	{
		path.draw_circle();
	}
};

int main()
{
	Shape* s1 = new Rect;
	Shape* s2 = new Circle;

	s1->draw();
	s2->draw();
}
