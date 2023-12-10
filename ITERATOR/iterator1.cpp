#include <iostream>

template<typename T> struct IEnumerator
{
	virtual T& getObject() = 0;
	virtual bool moveNext() = 0;

	virtual ~IEnumerator() {}
};

template<typename T> struct IEnumerable  
{
	virtual IEnumerator<T>* getEnumerator() = 0;

	virtual ~IEnumerable() {}
};



int main()
{
	slist<int>  s = { 1,2,3,4,5 }; 
	vector<int> v = { 1,2,3,4,5 };

	list_enumerator   p1 = s.getEnumerator();
	vector_enumerator p2 = v.getEnumerator();

	p1.moveNext();
	p2.moveNext();

	int n1 = p1.getObject();
	int n2 = p2.getObject();
}