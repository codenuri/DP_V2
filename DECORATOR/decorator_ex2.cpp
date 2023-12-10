#include <iostream>
#include <string>

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "w+")
	{
		file = fopen(s, mode);
	}
	~FileStream() {	fclose(file); }

	void write(const std::string& s)
	{
		std::cout << "write : " << s << std::endl;
	}
};

class ZipDecorator : public Stream
{
	Stream* stream; 
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data)
	{
		auto s = data + " Zip"; 

		stream->write(s); 
	}
};
class CryptoDecorator : public Stream
{
	Stream* stream; 
public:
	CryptoDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data)
	{
		auto s = data + " Crypto"; 
		stream->write(s); 
	}
};
int main()
{
	FileStream fs("a.txt");
//	fs.write("hello");

	CryptoDecorator cd(&fs); 
//	cd.write("hello");   

	ZipDecorator zd(&cd);
	zd.write("hello");
}
