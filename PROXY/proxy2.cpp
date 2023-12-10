#include <iostream>
#include <string>


struct IImage
{
	virtual void draw() = 0;
	virtual int width() const = 0;
	virtual int height() const = 0;
	virtual ~IImage() {}
};

class Image : public IImage
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


class ImageProxy : public IImage
{
	std::string name;
	Image* img = nullptr;
public:
	ImageProxy(const std::string& name) : name(name) {}

	int width()  const { return 100;} // 파일헤더에서 정보 획득
	int height() const { return 100;} // 파일헤더에서 정보 획득

	void draw() 
	{
		if ( img == nullptr )
			img = new Image(name);

		img->draw();
	}
};
int main()
{
//	Image* img = new Image("C:\\a.png");
	IImage* img = new ImageProxy("C:\\a.png");
//	img->draw();

	int w = img->width();
	int h = img->height();
	img->draw();
}