#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor& ) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex m;
	static Cursor* instance;
public:
	static Cursor& get_instance()
	{
		if ( instance == nullptr )
		{
			m.lock();

			if ( instance == nullptr )
			{
				instance = new Cursor;

			//	instance = Cursor 크기 메모리할당;
			//	Cursor::Cursor();
			}

			m.unlock();
		}

		return *instance;
	}
};
Cursor* Cursor::instance = nullptr;
std::mutex Cursor::m;

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}