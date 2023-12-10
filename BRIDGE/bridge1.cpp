#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;

	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
	void use(IMP3* p) 
	{				  					  
		p->play();
		p->stop();		

		p->play_one_minute();
	}
};

int main()
{
	People p;
	IPod pod;
	p.use(&pod);
}


