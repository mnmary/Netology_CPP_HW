#include "math.h"
#include <cmath>

int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int divide(int x, int y)
{
	if (y != 0)
	{
		return x / y;
	}
	return 0;
}
double pow_f(int x, int y)
{
	return pow(x, y);
}