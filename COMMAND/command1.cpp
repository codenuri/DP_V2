#include "monitor.h"

class ResolutionCommand 
{
	Monitor& m;
	int value;
public:
	ResolutionCommand(Monitor& m, int value) 
		: m{m}, value{value} {}

	void execute() { m.set_resolution(value);	}
};

int main()
{
	Monitor m;
	m.set_resolution(1920);


	ResolutionCommand res_cmd{m, 1920};
	res_cmd.execute();	
}