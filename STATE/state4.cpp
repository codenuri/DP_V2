#include <print>

struct IState 
{
	virtual void insert_coin() = 0;
	virtual void push_button() = 0;
	virtual ~IState() {}
};

struct IVendingMachine
{
	virtual IState* get_nocoin_state() = 0;
	virtual IState* get_hascoin_state() = 0;
	virtual void set_state(IState*)     = 0;

	virtual ~IVendingMachine() {}
};

class no_coin : public IState
{
	IVendingMachine* vm;
public:
	no_coin(IVendingMachine* vm) : vm{vm} {}

	void insert_coin() override 
	{
		std::println("inserted coin");
		vm->set_state( vm->get_hascoin_state() );
	}
	void push_button() override 
	{
		std::println("please insert coin");
	}
};

class has_coin : public IState
{
	IVendingMachine* vm;
public:
	has_coin(IVendingMachine* vm) : vm{vm} {}

	void insert_coin() override 
	{
		std::println("already inserted coin");
		std::println("please push button");		
	}
	void push_button() override 
	{
		std::println("make coffee");
		vm->set_state( vm->get_nocoin_state() );
	}
};

class vending_machine : public IVendingMachine
{
	no_coin  nocoin;
	has_coin hascoin;

	IState* state = &nocoin;
public:
	vending_machine() : nocoin{this}, hascoin{this} {}

	IState* get_nocoin_state() override { return &nocoin; }
	IState* get_hascoin_state()override { return &hascoin; }

	void set_state(IState* s)  override { state = s; }

	void insert_coin() { state->insert_coin(); }
	void push_button() { state->push_button(); }
};

int main()
{
	vending_machine vm;
	vm.insert_coin();
	vm.insert_coin();
//	vm.push_button();
}