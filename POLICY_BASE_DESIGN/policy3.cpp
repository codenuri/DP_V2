template<typename T> struct IAllocator
{
	virtual T* allocate(std::size_t newsize) = 0;
	virtual void deallocate(T* ptr, std::size_t size) = 0;
	~IAllocator() {}
};

template<typename T>
class vector
{
	T* ptr;

	IAllocator<T>* ax = nullptr;
pubilc:
	void set_allocator(IAllocator<T>* p) { ax = p;}

	void resize(std::size_t newsize)
	{
		ptr = ax->allocate(size);

		ax->deallocate(ptr, size);
	}
};

template<typename T>
class malloc_allocator : public IAllocator<T>
{
public:
	T*   allocate(std::size_t size)  override { return static_cast<T*>(malloc(sizeof(T)*size));}
	void deallocate(T* ptr, std::size_t size) override { free(ptr);}
};

int main()
{
	vector<int> v;
	malloc_allocator<int> ma;
	v.set_allocator(&ma);
//	v.set_allocator(&ma2);
}