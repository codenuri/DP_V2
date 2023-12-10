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

			if (c == 13) break; // enter 키

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
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