#include <print>

struct IState 
{
	virtual void insert_coin() = 0;
	virtual void push_button() = 0;
	virtual ~IState() {}
};

class no_coin : public IState
{
public:
	void insert_coin() override {}
	void push_button() override {}
};

class has_coin : public IState
{
public:
	void insert_coin() override {}
	void push_button() override {}
};

class vending_machine 
{
	no_coin  nocoin;
	has_coin hascoin;

	IState* state = &nocoin;
public:
	void insert_coin() { state->insert_coin();}
	void push_button() { state->push_button();}
};

int main()
{
	vending_machine vm;
	vm.insert_coin();
	vm.push_button();
}