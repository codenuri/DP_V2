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

int main()
{
	Image img("www.image.com/car.jpg");
	img.draw();
}