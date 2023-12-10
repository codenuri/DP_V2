#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading...\n";
	}
public:

	void draw() 
	{ 
		std::cout << "draw " << image_url << '\n';
	}
	
	static std::map<std::string, Image*> image_map;

	static Image* create(const std::string& url)
	{
		Image* img;
		auto ret = image_map.find(url);
		
		if (ret == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return image_map[url];
	}
};
std::map<std::string, Image*> Image::image_map;

int main()
{
	Image* img1 = Image::create("www.image.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.image.com/a.png");
	img2->draw();
}



