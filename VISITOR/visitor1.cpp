#include <iostream>
#include <list>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 방법 1. 직접 연산
	for (auto& e : s)
	{
		e *= 2;
	}

	// 방법 2. 방문자 패턴 사용
	TwiceVisitor<int> tv; // 요소 한개의 값을 2배로 하는
						  // 방문자
	s.accept(&tv);

	ShowVisitor<int> sv; // 요소 한개를 출력하는 방문자
	s.accept(&sv);	
}