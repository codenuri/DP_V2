template<typename T, typename Ax = std::allocator<T> >
class vector
{
	T* ptr;
	Ax ax;
pubilc:
	void resize(std::size_t newsize)
	{
		ptr = ax.allocate(size);

		ax.deallocate(ptr, size);
	}
};

template<typename T>
class malloc_allocator 
{
public:
	inline T*   allocate(std::size_t size)  { return static_cast<T*>(malloc(sizeof(T)*size));}
	inline void deallocate(T* ptr, std::size_t size) { free(ptr);}
};

int main()
{
	vector<int, malloc_allocator<int> > v;

}