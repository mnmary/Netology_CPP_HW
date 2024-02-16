#pragma once
class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator);
	friend bool operator ==(Fraction& f);

	bool operator < (const Fraction& f) const;
	bool operator > (const Fraction& f) const;
	//bool operator != (const Fraction& f) const;	//גמחüלול NOT ==
	//bool operator <= (const Fraction& f) const;	//גמחüלול NOT >
	//bool operator >= (const Fraction& f) const;	//גמחüלול NOT <
};

