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
	// 모든 동물의 공통의 작업
}

void foo(Dog* p)
{
	foo(static_cast<Animal*>(p));
	p->run();
}

int main()
{
	Dog d; foo(&d);
	Cat c; foo(&c);
}