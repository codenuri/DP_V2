#include <vector>
#include <deque>
#include <list>
#include <iostream>

template<typename T> 
class stack 
{
	std::list<T> c;
public:
	void push(const T& a) 
	{ 
		c.push_back(a); 
	}
	void pop()			  
	{ 
		c.pop_back(); 
	}
	T&   top()            
	{ 
		return c.back(); 
	}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

//	s.push_front(100); // error. 
						// 함수 없음.
}
