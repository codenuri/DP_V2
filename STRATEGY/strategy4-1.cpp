#include <iostream>
#include <string>
#include <conio.h>

struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool iscomplete(const std::string& data) { return true;}
	virtual ~IValidator() {}
};

class DigitValidator : public IValidator
{
	int count;
public:
	DigitValidator(int count = 9999) : count(count) {}

	bool validate(const std::string& data, char c) override 
	{
		return data.size() < count && isdigit(c);
	}
	bool iscomplete(const std::string& data) override 
	{
		return count != 9999 && data.size() == count;
	}
};





class Edit
{
	std::string data;

	IValidator* val = nullptr;
public:
	void set_validator(IValidator* p) { val = p;}

	std::string get_text()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && ( val == nullptr || val->iscomplete(data)    )  ) break;
			
			if (val == nullptr || val->validate(data, c))
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
	DigitValidator v(5);
	edit.set_validator(&v);
	
//	DigitValidator v2(15);
//	edit.set_validator(&v2);

	while (1)
	{
		std::string s = edit.get_text();
		std::cout << s << std::endl;
	}
}