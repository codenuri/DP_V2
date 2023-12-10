template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> struct slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) 
	{ 
		head = new Node<T>(a, head); 
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
}