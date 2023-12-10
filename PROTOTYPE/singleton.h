#pragma once

#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
	classname(classname&) = delete;			\
	void operator=(classname&) = delete;	\
public:										\
	static classname& get_instance()		\
	{										\
		static classname instance;			\
		return instance;					\
	}										\
private: