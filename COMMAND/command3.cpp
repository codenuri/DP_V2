#include <stack>
#include "monitor.h"

struct ICommand 
{
	virtual void execute() = 0;
	virtual void undo() {}	
};

class ResolutionCommand : public ICommand
{
	Monitor& m;
	int value;
	int old;
public:
	ResolutionCommand(Monitor& m, int value) 
		: m{m}, value{value} {}

	void execute() 
	{ 
		old = m.get_resolution();
		m.set_resolution(value);	
	}
	void undo() { m.set_resolution(old); } 
};

class BrightnessCommand : public ICommand
{
	Monitor& m;
	int value;
	int old;
public:
	BrightnessCommand(Monitor& m, int value) 
		: m{m}, value{value} {}

	void execute() 
	{ 
		old = m.get_brightness();
		m.set_brightness(value);	
	}
	void undo() { m.set_brightness(old);	} 
};

int main()
{
	Monitor m;

	ICommand* cmd = nullptr;

	std::stack<ICommand*> cmd_stack;

	cmd = new BrightnessCommand(m, 90);
	cmd->execute();
	cmd_stack.push(cmd);

	cmd = new ResolutionCommand(m, 1920);
	cmd->execute();
	cmd_stack.push(cmd);	

	// undo 
	cmd = cmd_stack.top();
	cmd_stack.pop();

	cmd->undo();
	delete cmd;
}