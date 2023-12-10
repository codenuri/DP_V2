#include <string>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age) : name(name), age(age) {}
};

class Student : public People
{
	int id;
public:
//	Student(int id) : id(id) {} // Student(int id) : People(),  id(id) {} //


	Student(const std::string& name, int age, int id) 
		: People(name, age),  id(id) {}
};

int main()
{
	Student s("kim", 20, 15);
}


