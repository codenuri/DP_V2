/*
#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
	classname(classname&) = delete;			\
	void operator=(classname&) = delete;	\
public:										\
	static classname& getInstance()			\
	{										\
		static classname instance;			\
		return instance;					\
	}										\
private:
*/
#include "singleton.h"

class Cursor
{
    MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
}