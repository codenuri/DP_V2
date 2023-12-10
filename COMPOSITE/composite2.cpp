#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() const { return title; }
	
	void set_title(const std::string& s) { title = s; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // m1 메뉴를 선택
}
