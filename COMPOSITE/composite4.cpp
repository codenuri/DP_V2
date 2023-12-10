#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

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

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* m) { v.push_back(m); }

	void command()
	{
		while(1)
		{
			system("cls");

			std::size_t sz = v.size();
			std::size_t i = 0;

			for (MenuItem* p : v)
			{
				std::cout << ++i << ". " << p->get_title() << "\n";
			}
			std::cout << i + 1 << ". 종료\n";
			std::cout << "메뉴를 선택해 주세요 >> ";

			int cmd;
			std::cin >> cmd;

			if ( cmd == sz + 1 )
				break;

			if ( cmd < 1 || cmd > sz + 1)
				continue;
			v[cmd - 1]->command();		
		}

	}
};

int main()
{
	MenuItem m1("참치 김밥",   11);
	MenuItem m2("소고기 김밥", 12);
	MenuItem m3("돈까스 김밥", 13);

	MenuItem m4("라면",   21);
	
	PopupMenu kimbab("김밥류");
	kimbab.add_menu(&m1);
	kimbab.add_menu(&m2);
	kimbab.add_menu(&m3);

	PopupMenu pm("오늘의 메뉴");
	pm.add_menu(&kimbab); // error.
	pm.add_menu(&m4);

	pm.command(); 
}
