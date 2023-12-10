#include <print>

class Animal
{
public:
//	virtual ~Animal() {}
};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	Animal* pa = new Dog;
//	Animal* pa = new Cat;

//	Dog* pd = pa; // error
//	Dog* pd = static_cast<Dog*>(pa); 
	Dog* pd = dynamic_cast<Dog*>(pa); 

	std::println("{}", 
				 reinterpret_cast<void*>(pd));
}