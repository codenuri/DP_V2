#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "CoolText.h"

class ClsAdapter : public CoolText, public Shape 
{
public:
	ClsAdapter(const std::string& text) : CoolText(text) {}

	void draw() override { CoolText::show();}
};	

class ObjAdapter : public Shape 
{
	CoolText* ct;
public:
	ObjAdapter(CoolText* ct) : ct(ct) {}

	void draw() override { ct->show();}
};	

int main()
{
	std::vector<Shape*> v;

	CoolText ct("Hello");	// CoolText : 클래스
							// ct       : 객체

//	v.push_back( &ct ); 	// error

	v.push_back( new ObjAdapter( &ct)  );

	v[0]->draw();
}