#include "Point.h"
#include "PointImpl.h"

Point::Point(int x, int y) 
: impl( new PointImpl(x, y) )
{
	 
}
void Point::print() const
{ 
	impl->print(); 
}