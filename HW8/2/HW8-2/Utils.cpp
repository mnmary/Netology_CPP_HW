
bool compare3(int a, int b, int c)
{
	//сравним 3 числа
	if (a != b) return false;
	if (a != c) return false;
	if (b != c) return false;
	return true;
}
bool compare4(int a, int b, int c, int d)
{
	//сравним 4 числа
	if (a != b) return false;
	if (a != c) return false;
	if (a != d) return false;
	if (b != c) return false;
	if (b != d) return false;
	if (c != d) return false;
	return true;
}