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


class NumEdit : public Edit
{	
	int count;
public:
	NumEdit(int count = 9999) : count(count) {}

	bool validate(const std::string& data, char c) override
	{		
		return data.size() < count && isdigit(c);
	}
	bool iscomplete(const std::string& data) override
	{
		return count != 9999 && data.size() == count;
	}
};


int main()
{
//	Edit edit;
	NumEdit edit(5); // 5자리 숫자만, 5자리 입력 되어야만 enter 가능
	
//	AddressEdit edit2;
	while (1)
	{
		std::string s = edit.get_text();
		std::cout << s << std::endl;
	}
}