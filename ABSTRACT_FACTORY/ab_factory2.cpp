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

struct IControlFactory
{
	IButton* create_button()= 0;
	IEdit*   create_edit()  = 0;
	virtual ~IControlFactory() {}
};

class RichControlFactory : public IControlFactory
{
public:
	IButton* create_button() { return new RichButton; }
	IEdit*   create_edit() { return new RichEdit; }	
};

class SimpleControlFactory : public IControlFactory
{
public:
	IButton* create_button() { return new SimpleButton; }
	IEdit*   create_edit() { return new SimpleEdit; }
};

int main(int argc, char** argv)
{
	IControlFactory* factory;

	if (strcmp(argv[1], "-style:rich") == 0)
		factory = new RichControlFactory;
	else
		factory = new SimpleControlFactory;

	IButton* btn = factory->create_button();
	
	btn->draw();
}








