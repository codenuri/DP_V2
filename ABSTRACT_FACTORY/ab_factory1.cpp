#include <iostream>
#include <cstring>

struct IButton
{
	virtual void draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void draw() = 0;
	virtual ~IEdit() {}
};

struct RichButton : public IButton
{
	void draw() { std::cout << "draw RichButton" << std::endl; }
};
struct RichEdit : public IEdit
{
	void draw() { std::cout << "draw RichEdit" << std::endl; }
};

struct SimpleButton : public IButton
{
	void draw() { std::cout << "draw SimpleButton" << std::endl; }
};
struct SimpleEdit : public IEdit
{
	void draw() { std::cout << "draw SimpleEdit" << std::endl; }
};

int main(int argc, char** argv)
{
	IButton* btn;

	if (strcmp(argv[1], "-style:rich") == 0)
		btn = new RichButton;
	else
		btn = new SimpleButton;
		

	btn->draw();

}








