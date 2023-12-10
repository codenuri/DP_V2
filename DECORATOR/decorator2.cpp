#include <iostream>
#include <string>

class Image
{
	std::string image_path;
public:
	Image(const std::string& path) : image_path(path) 
	{	
		// load image from file or internet
	}
	void draw() const 
	{ 
		std::cout << "draw " << image_path << std::endl; 
	}
};

class Frame : public Image 
{
public:
	using Image::Image;

	void draw() const 
	{ 
		std::cout << "==========================" << std::endl; 
		Image::draw();
		std::cout << "==========================" << std::endl; 
	}
};
class Balloon : public Image 
{
public:
	using Image::Image;

	void draw() const 
	{ 
		std::cout << "== Balloon ==============" << std::endl; 
		Image::draw();
		std::cout << "== Balloon ==============" << std::endl; 
	}
};

int main()
{
	Image img("www.image.com/car.jpg");
	img.draw();

	Frame frame("www.image.com/car.jpg");
	frame.draw();

	Balloon balloon("www.image.com/car.jpg");
	balloon.draw();
}