#include <iostream>

class Base
{
public:
	// 핵심 : Base에 디폴트 생성자가 없음.
	Base(int a){ }
};
class Derived : public Base
{
public:		
//	Derived() { }     // Derived() : Base(){ }
//	Derived(int a) { }// Derived(int a) : Base() { }

	Derived()      : Base(0) { }
	Derived(int a) : Base(a) { }
};
int main()
{

}
