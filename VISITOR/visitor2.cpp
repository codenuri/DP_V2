#include <iostream>
#include <list>

// 방문자(Visitor)의 인터페이스
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

template<typename T> 
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { e *= 2; }
};

template<typename T> 
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override
	{
		std::cout << e << ", ";
	}
};

template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

template<typename T> 
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list;

	void accept(IVisitor<T>* visitor) override
	{
		for( auto& e : *this)
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.accept(&tv);

	ShowVisitor<int> sv; 
	s.accept(&sv);	
}