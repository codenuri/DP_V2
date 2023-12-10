#include <vector>
#include <deque>
#include <list>
#include <iostream>

template<typename T> 
class stack : public std::list<T>
{
public:
	void push(const T& a) 
	{ 
		std::list<T>::push_back(a); 
	}
	void pop()			  
	{ 
		std::list<T>::pop_back(); 
	}
	T&   top()            
	{ 
		return std::list<T>::back(); 
	}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

//	s.push_front(100); // ??
}
