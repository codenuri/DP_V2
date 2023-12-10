#include <mutex>

template<typename T>
class Singleton
{
protected:
	Singleton() {}

private:	
	Singleton(const Singleton& ) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static std::mutex m;
	static T* instance;
public:
	static T& get_instance()
	{		
		std::lock_guard<std::mutex> g(m);

		if ( instance == nullptr )
			instance = new T;
		
		return *instance;
	}
};
template<typename T> T* Singleton<T>::instance = nullptr;
template<typename T> std::mutex Singleton<T>::m;


class Mouse : public Singleton< Mouse >
{

};

int main()
{
	Mouse& c1 = Mouse::get_instance();
}