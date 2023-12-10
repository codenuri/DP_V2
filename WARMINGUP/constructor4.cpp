class Animal
{
//public:		// A, B 모두 ok
//private:		// A, B 모두 error
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};

int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// A error
	Dog    d;	// B ok
}



