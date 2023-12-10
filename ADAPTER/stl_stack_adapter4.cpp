#include <vector>
#include <deque>
#include <list>
#include <iostream>

template<typename T, typename C = std::deque<T> > 
class stack 
{
	C c;
//	C* c; // object adapter
public:
	constexpr void push(const T& a) { c.push_back(a); }
	constexpr void pop()		    { c.pop_back(); 	}
	constexpr T&   top()            { return c.back(); }
};
#include <stack>
int main()
{
	stack<int, std::vector<int>> s1;
	stack<int, std::list<int>> s2;
	stack<int> s;
	s.push(10);
	s.push(20);
}
