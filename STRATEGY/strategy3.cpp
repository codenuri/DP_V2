#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:

	std::string get_text()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && iscomplete(data) ) break;

			if (validate(data, c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
	virtual bool validate(const std::string& data, char c)
	{
		return true;
	}
	virtual bool iscomplete(const std::string& data)
	{
		return true;
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