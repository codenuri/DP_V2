#include <print>

class vending_machine
{
public:
	void insert_coin() { std::println("inserted coin");}
	void push_button() { std::println("make coffee");}
};

int main()
{
	vending_machine vm;

//  vm.insert_coin();
	vm.push_button();
}