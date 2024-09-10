#include "monitor.h"

class ResolutionCommand 
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
	void undo() {m.set_resolution(old);	} 
};

int main()
{
	Monitor m;

	int old = m.get_resolution();
	m.set_resolution(1920);
	m.set_resolution(old);

	ResolutionCommand res_cmd{m, 1920};
	res_cmd.execute();	
	res_cmd.undo();
}