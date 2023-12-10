template<typename T>
class vector
{
	T* ptr;
pubilc:
	void resize(std::size_t newsize)
	{
		// 메모리 할당/해지가 필요 하다면 ?
		ptr = new T[newsize];

		delete[] ptr;
	}
};

int main()
{
	vector<int> v;
}