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
int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

//	NetworkStream ns("127.0.0.1", 4000);
//	ns.write("hello");

//	PipeStream ps("named pipe");
//	ps.write("hello");
}
