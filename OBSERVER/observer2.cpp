#include <iostream>
#include <vector>

struct IChart
{
	virtual void update(int n) = 0;
	virtual ~IChart() {}
};

class Subject
{
	std::vector<IChart*> v;
public:
	virtual ~Subject() {}

	void attach(IChart* p) { v.push_back(p); }
	void detach(IChart* p) { }

	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
	
};

class Table : public Subject
{
	int data;
public:
	void edit()
	{
		while (1)
		{
			std::cout << "data >> ";			
			std::cin >> data; 
			notify(data);
		}
	}
};

class BarChart : public IChart
{
public:
	void update(int n) override
	{
		std::cout << "Bar Chart : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieChart : public IChart
{
public:
	void update(int n) override
	{
		std::cout << "Pie Chart : ";

		for (int i = 0; i < n; i++)
			std::cout << "(";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;
	BarChart bc; t.attach(&bc);
	PieChart pc; t.attach(&pc);
	
	t.edit();	
}
