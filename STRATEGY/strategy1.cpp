#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
	std::string get_text()
	{
		std::cin >> data;
		return data;
	}
};

int main()
{
	Edit edit;
	while (1)
	{
		std::string s = edit.get_text();
		std::cout << s << std::endl;
	}
}