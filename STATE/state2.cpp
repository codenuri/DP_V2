#include <print>

class vending_machine
{
	enum { NOCOIN, HASCOIN };

	int state = NOCOIN;
public:
	void insert_coin() 
	{ 
		if ( state == NOCOIN )
		{
			std::println("inserted coin");
			state = HASCOIN;
		}
		else if ( state == HASCOIN )
		{
			std::println("already inserted coin");
			std::println("please push button");
		}
	}
	void push_button() 
	{ 
		if ( state == NOCOIN )
		{
			std::println("please insert coin");
		}
		else if ( state == HASCOIN )
		{
			std::println("make coffee");
			state = NOCOIN;
		}		
	}
};

int main()
{
	vending_machine vm;
//	vm.insert_coin();
	vm.push_button();
}