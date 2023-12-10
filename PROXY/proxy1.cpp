#include <iostream>
#include <string>

class Image
{
	std::string name;
public:
	Image(const std::string& name) : name(name)
	{
		std::cout << "open " << name << '\n';
	}
	void draw() { std::cout << "draw " << name << '\n'; }

	int width()  const { return 100;}
	int height() const { return 100;}
};

int main()
{
	Image* img = new Image("C:\\a.png");
	img->draw();

	int w = img->width();
	int h = img->height();
}