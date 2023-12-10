#pragma once

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