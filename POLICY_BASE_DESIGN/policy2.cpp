template<typename T>
class vector
{
	T* ptr;
pubilc:
	void resize(std::size_t newsize)
	{
		ptr = allocate(size);

		deallocate(ptr, size);
	}

	virtual T*   allocate(std::size_t size)   { return new T[size];}
	virtual void deallocate(T* ptr, std::size_t size) { delete[] ptr;}
};

template<typename T> 
class malloc_vector : public vector<T>
{
public:
	T*   allocate(std::size_t size)   { return static_cast<T*>(malloc(sizeof(T)*size));}
	void deallocate(T* ptr, std::size_t size) { free(ptr);}
};


int main()
{
	//vector<int> v;
	malloc_vector<int> v;
}