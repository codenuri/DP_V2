#include <iostream>
#include <string>


struct IDraw
{
	virtual void draw() const  = 0;

	virtual ~IDraw() {}
};


class Image : public IDraw
{
	std::string image_path;
public:
	Image(const std::string& path) : image_path(path) {	}

	void draw() const { std::cout << "draw " << image_path << std::endl; }
};

class Frame : public IDraw
{
	IDraw* img;
public:
	Frame(IDraw* img) : img(img) {}

	void draw() const 
	{ 
		std::cout << "==========================" << std::endl; 
		img->draw();
		std::cout << "==========================" << std::endl; 
	}
};

class Balloon : public IDraw
{
	IDraw* img;
public:
	Balloon(IDraw* img) : img(img) {}

	void draw() const 
	{ 
		std::cout << "== Balloon ===============" << std::endl; 
		img->draw();
		std::cout << "== Balloon ==============="  << std::endl; 
	}
};

int main()
{
	Image img("www.image.com/car.jpg");
	img.draw();

	Frame frame(&img);
	frame.draw();

	Balloon balloon(&frame); // ?
	balloon.draw();
}