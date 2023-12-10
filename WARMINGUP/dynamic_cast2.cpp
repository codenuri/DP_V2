class Animal
{
public:
	virtual ~Animal() {}
};
class Cat : public Animal {};
class Dog : public Animal 
{
public:
	void run() {}
};
void foo(Animal* p)
{
	// p가 Dog를 가리킨다면 run() 멤버 함수를 호출하고 싶다
	// p->run(); // error

	Dog* pdog = dynamic_cast<Dog*>(p);

	if ( pdog != nullptr )
	{
		pdog->run();
	}

}
int main()
{
	Dog d; foo(&d);
	Cat c; foo(&c);
}