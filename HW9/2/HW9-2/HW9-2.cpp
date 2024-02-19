// HW9-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	int gcd(int n, int d)
	{
		int remainder;
		while (d != 0)
		{
			remainder = n % d;
			n = d;
			d = remainder;
		}
		return abs(n);
	}
public:
	Fraction()
	{
		numerator_ = 0;
		denominator_ = 0;
	}
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	std::string fractionToStr()
	{
		std::string a = std::to_string(this->numerator_);
		a += "/";
		a += std::to_string(this->denominator_);
		return a;
	}

	Fraction& operator ++ ()	//префиксная
	{
		this->numerator_ = this->numerator_ + this->denominator_;
		return (*this);
	}
	Fraction& operator ++ (int)	//постфиксная
	{
		Fraction* f = new Fraction(*this);
		this->numerator_ = this->numerator_ + this->denominator_;
		return (*f);
	}
	Fraction& operator -- ()	//префиксная
	{
		this->numerator_ = this->numerator_ - this->denominator_;
		return (*this);
	}
	Fraction& operator -- (int)	//постфиксная
	{
		Fraction* f = new Fraction(*this);
		this->numerator_ = this->numerator_  - this->denominator_;
		return (*f);
	}
	Fraction& operator - ()	//унарный минус
	{
		this->numerator_ = -this->numerator_;
		return (*this);
	}
	Fraction& operator + (const Fraction& right)	//сложить
	{
		//1 приведем к общему знаменателю обе дроби
		int denominatorLR = this->denominator_ * right.denominator_;	//произведение знаменателей
		int numeratorL = this->numerator_ * right.denominator_;			//умножим левый числитель на правый знаменатель
		int numeratorR = right.numerator_ * this->denominator_;			//умножим правый числитель на левый знаменатель 
		//2 сложим числители
		int numeratorLR = numeratorR + numeratorL;
		//3 сократим дробь, разделим числитель и знаменатель на наибольший общий делитель
		int nod = gcd(numeratorLR, denominatorLR);
		Fraction* f = new Fraction(numeratorLR / nod, denominatorLR / nod);
		return (*f);
	}
	Fraction& operator - (const Fraction& right)	//вычесть
	{
		//1 приведем к общему знаменателю обе дроби
		int denominatorLR = this->denominator_ * right.denominator_;	//произведение знаменателей
		int numeratorL = this->numerator_ * right.denominator_;			//умножим левый числитель на правый знаменатель
		int numeratorR = right.numerator_ * this->denominator_;			//умножим правый числитель на левый знаменатель 
		//2 вычтем числители
		int numeratorLR = numeratorL - numeratorR;
		//3 сократим дробь, разделим числитель и знаменатель на наибольший общий делитель
		int nod = gcd(numeratorLR, denominatorLR);
		Fraction* f = new Fraction(numeratorLR / nod, denominatorLR / nod);
		return (*f);
	}
	Fraction& operator * (const Fraction& right)	//умножить
	{
		//1 умножим знаменатели
		int denominatorLR = this->denominator_ * right.denominator_;	//произведение знаменателей
		//2 умножим числители
		int numeratorLR = this->numerator_ * right.numerator_;
		//3 сократим дробь, разделим числитель и знаменатель на наибольший общий делитель
		int nod = gcd(numeratorLR, denominatorLR);
		Fraction* f = new Fraction(numeratorLR / nod, denominatorLR / nod);
		return (*f);
	}
	Fraction& operator / (const Fraction& right)	//поделить
	{
		//1 умножим знаменатель на числитель
		int denominatorLR = this->denominator_ * right.numerator_;	
		//2 умножим числитель на знаменатель
		int numeratorLR = this->numerator_ * right.denominator_;
		//3 сократим дробь, разделим числитель и знаменатель на наибольший общий делитель
		int nod = gcd(numeratorLR, denominatorLR);
		Fraction* f = new Fraction(numeratorLR / nod, denominatorLR / nod);
		return (*f);
	}

};



int main()
{
	setlocale(LC_ALL, "Rus");
   /*
   Введите числитель дроби 1: 3
Введите знаменатель дроби 1: 4
Введите числитель дроби 2: 4
Введите знаменатель дроби 2: 5
3/4 + 4/5 = 31/20
3/4 - 4/5 = -1/20
3/4 * 4/5 = 3/5
3/4 / 4/5 = 15/16
++3/4 * 4/5 = 7/5
Значение дроби 1 = 7/4
7/4-- * 4/5 = 7/5
Значение дроби 1 = 3/4
*/ 
	int n1, n2, d1, d2;
	Fraction oldf, f;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> d1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> n2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> d2;

	Fraction f1(n1, d1);
	Fraction f2(n2, d2);
	
	f = f1 + f2;
	std::cout << f1.fractionToStr() << " + " << f2.fractionToStr() << " = " << f.fractionToStr() << std::endl;
	f = f1 - f2;
	std::cout << f1.fractionToStr() << " - " << f2.fractionToStr() << " = " << f.fractionToStr() << std::endl;
	f = f1 * f2;
	std::cout << f1.fractionToStr() << " * " << f2.fractionToStr() << " = " << f.fractionToStr() << std::endl;
	f = f1 / f2;
	std::cout << f1.fractionToStr() << " / " << f2.fractionToStr() << " = " << f.fractionToStr() << std::endl;
	
	oldf = f1;
	f = (++f1) * f2;
	std::cout << "++" << oldf.fractionToStr() << " * " << f2.fractionToStr() << " = " << f.fractionToStr() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.fractionToStr() << std::endl;
	
	oldf = f1;
	f = (f1--) * f2;
	std::cout  << oldf.fractionToStr() << "--" << " * " << f2.fractionToStr() << " = " << f.fractionToStr() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.fractionToStr() << std::endl;
}

