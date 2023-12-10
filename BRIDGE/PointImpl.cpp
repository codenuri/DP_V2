#include <iostream>
#include "PointImpl.h"

PointImpl::PointImpl(int x, int y)
	: x(x), y(y)
{
}

void PointImpl::print() const
{
	std::cout << x << ", " << y << std::endl;
} 