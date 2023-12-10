#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> s = {1,2,3,4,3,2,1};

//	auto first = s.begin();
//	auto last  = s.end();

//	std::reverse_iterator< std::vector<int>::iterator  > first(s.end());
	std::reverse_iterator first(s.end());
	std::reverse_iterator last(s.begin());

	auto ret = std::find(first, last, 3);
}
