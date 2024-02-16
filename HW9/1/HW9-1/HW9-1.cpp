// HW9-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator == (const Fraction& right) const	//тип правой части выражения
	{
		//1 приведем к общему знаменателю обе дроби
		int denominatorLR = this->denominator_ * right.denominator_;	//произведение знаменателей
		int numeratorL = this->numerator_ * right.denominator_;			//умножим левый числитель на правый знаменатель
		int numeratorR = right.numerator_ * this->denominator_;			//умножим правый числитель на левый знаменатель
		
		//2 будем сравнивать числители у модифицированных дробей. Если равны числители - равны дроби
		if (numeratorL == numeratorR)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (const Fraction& right) const
	{
		return !(this->operator == (right));
	}

	bool operator < (const Fraction& right) const
	{
		//1 приведем к общему знаменателю обе дроби
		int denominatorLR = this->denominator_ * right.denominator_;	//произведение знаменателей
		int numeratorL = this->numerator_ * right.denominator_;			//умножим левый числитель на правый знаменатель
		int numeratorR = right.numerator_ * this->denominator_;			//умножим правый числитель на левый знаменатель

		//2 будем сравнивать числители у модифицированных дробей. Если левый числитель меньше правого - левая дробь меньше правой
		if (numeratorL < numeratorR)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator >= (const Fraction& right) const
	{
		return !(this->operator < (right));
	}

	bool operator > (const Fraction& right) const
	{
		//1 приведем к общему знаменателю обе дроби
		int denominatorLR = this->denominator_ * right.denominator_;	//произведение знаменателей
		int numeratorL = this->numerator_ * right.denominator_;			//умножим левый числитель на правый знаменатель
		int numeratorR = right.numerator_ * this->denominator_;			//умножим правый числитель на левый знаменатель

		//2 будем сравнивать числители у модифицированных дробей. Если левый числитель больше правого - левая дробь больше правой
		if (numeratorL > numeratorR)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator <= (const Fraction& right) const
	{
 		return !(this->operator > (right));
	}
};
int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
