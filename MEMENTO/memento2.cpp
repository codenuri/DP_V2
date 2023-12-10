#include <iostream>
#include "graphic.h"

int main()
{
	Graphic g;

	g.set_stroke_color(red);
	g.set_stroke_width(10);
	g.draw_line(0, 0, 100, 100);
	g.draw_line(0, 0, 200, 200); 
	
	int token = g.save();

	g.set_stroke_color(blue);
	g.set_stroke_width(20);
	g.draw_line(0, 0, 300, 300);
	g.draw_line(0, 0, 400, 400);

	// 처음 그렸던 선과 동일한 속성으로 그리고 싶다. 
	g.restore(token);

	g.draw_line(10, 20, 300, 300);
	g.draw_line(10, 30, 400, 400);
}









