//#include "PointImpl.h"
class PointImpl; // 핵심.. 

class Point
{
	PointImpl* impl;
public:
	Point(int x, int y);

	void print() const;
};