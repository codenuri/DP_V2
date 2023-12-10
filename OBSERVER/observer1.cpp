#include <iostream>
#include <vector>

struct IChart
{
	virtual void update(int n) = 0;
	virtual ~IChart() {}
};

class Table
{
	std::vector<IChart*> v;
	int data;
public:
	void attach(IChart* p) { v.push_back(p); }
	void detach(IChart* p) { }

	void notify(int data)
	{
		// 등록된 모든 챠트에 알려준다.
		for (auto p : v)
			p->update(data);
	}

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
	
	t.edit();	// table 편집 모드
}
