#include <iostream>
#include <string>

class Image
{
	std::string image_path;
public:
	Image(const std::string& path) : image_path(path) {	}

	void draw() const { std::cout << "draw " << image_path << std::endl; }
};

class Frame 
{
	Image* img;
public:
	Frame(Image* img) : img(img) {}

	void draw() const 
	{ 
		std::cout << "==========================" << std::endl; 
		img->draw();
		std::cout << "==========================" << std::endl; 
	}
};

class Balloon 
{
	Image* img;
public:
	Balloon(Image* img) : img(img) {}

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

	Balloon balloon(&img);
//	Balloon balloon(&frame); // ?
	balloon.draw();
}