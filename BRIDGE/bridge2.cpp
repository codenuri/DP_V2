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

class MP3
{
	IMP3* impl; 
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr)
			impl = new IPod;
	}

	void play() { impl->play(); }
	void stop() { impl->stop(); }
	
	void play_one_minute()
	{
		impl->play();
		// 1분 후에.. 
		impl->stop();
	}
};

class People
{
public:
	void use(MP3* p) 
	{				  					  
		p->play();
		p->stop();		

		p->play_one_minute();
	}
};

int main()
{
	People p;
	MP3 mp3;
	p.use(&mp3);
}


