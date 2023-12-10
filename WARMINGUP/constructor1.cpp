#include <iostream>

class Base
{
public:
	Base()     { std::cout << "Base()"    << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()"   << std::endl; }
};
class Derived : public Base
{
public:		
	Derived()		// ==> Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)	// ==> Derived(int a) : Base()
	{ 
		std::cout << "Derived(int)" << std::endl;
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// ~Base()
	}
};
int main()
{
//	Derived d1;		
	Derived d2(5);	// call Derived::Derived(int)

}
