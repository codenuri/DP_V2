#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "CoolText.h"

class ClsAdapter : public CoolText, public Shape 
{
public:
	ClsAdapter(const std::string& text) 
			: CoolText(text) {}

	void draw() override { CoolText::show();}
};	


int main()
{
	std::vector<Shape*> v;

	v.push_back( new ClsAdapter("Hello"));

	v[0]->draw();
}