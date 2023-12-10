#include <iostream>

class Graphic
{
	// 윈도우의 그림을 그리는 수 많은 함수들을 제공
};

int main()
{
	Graphic g;

	// 그림을 그릴때 선의 색상이나 두께 등을 변경하고 싶다.

	// 방법 1. 함수인자로 전달.
	g.draw_line(0, 0, 100, 100, red, 10);  
	g.draw_line(0, 0, 200, 200, blue, 20); 


	// 방법 2. Graphic 객체의 속성으로 전달
	g.set_stroke_color(red);
	g.set_stroke_width(10);

	g.draw_line(0, 0, 100, 100);
	g.draw_line(0, 0, 100, 100);
}

