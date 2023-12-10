#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> 
class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p)
	{
	}

	inline T& operator*() { return current->data; }

	inline slist_iterator& operator++() 
	{
		current = current->next;
		return *this; 
	}

	inline bool operator==(const slist_iterator& other) const 
	{
		return current == other.current;
	}
	inline bool operator!=(const slist_iterator& other) const 
	{
		return current != other.current;
	}	
};



template<typename T> class slist 
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	inline slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);
	}
	inline  slist_iterator<T> end()
	{
		return slist_iterator<T>(nullptr);
	}
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	auto first = s.begin();
	auto last = s.end();

	while( first != last )
	{
		std::cout << *first << std::endl;
		++first;
	}
}