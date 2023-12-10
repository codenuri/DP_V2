#pragma once
#include <map>

enum color { red = 1, green = 2, blue = 3};

class Graphic
{
	struct Memento
	{
		int penWidth;
		int penColor;
		Memento(int w, int c) : penWidth(w), penColor(c) {}
	};
	std::map<int, Memento*> memento_map; 

	int penWidth = 1;
	int penColor = 0;
	int temporary_data;
public:

	int save()
	{
		static int key = 0;
		++key;

		Memento* p = new Memento(penWidth, penColor);
		memento_map[key] = p;

		return key;
	}
	
	void restore(int token)
	{
		penColor = memento_map[token]->penColor;
		penWidth = memento_map[token]->penWidth;
	}





	void draw_line(int x1, int y1, int x2, int y2)
	{
	}
	void set_stroke_color(int c) { penColor = c; }
	void set_stroke_width(int w) { penWidth = w; }
};