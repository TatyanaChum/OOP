//Fraction

#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;

Fraction operator*(Fraction left, Fraction right); //Объявляем фунцию
Fraction operator+(Fraction left, Fraction right); //Объявляем фунцию
Fraction operator-(Fraction left, Fraction right); //Объявляем фунцию
Fraction operator/(Fraction left, Fraction right); //Объявляем фунцию

bool operator<(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}

	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}

	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor: \t" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor: \t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor: \t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor: \t" << this << endl;
	}
	//operators:
	
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
		//		A	 =	A	*	B;
	}

	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
		//		A	 =	A	+	B;
	}

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
		//		A	 =	A	-	B;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
		//		A	 =	A	-	B;
	}
	//Methods:

	Fraction& reduce()
	{
		if (numerator == 0) return *this;
		int more, less;
		int rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD - Greatest Common Divisor (наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	Fraction& to_improper()//переводит дробь в неправильную
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()//переводит дробь в правильную
	{
		integer += numerator / denominator;
		numerator %= denominator;
		//numerator = nemerator%denominator;
		return *this;
	}
	Fraction inverted()
	{
	/*	Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		to_improper();
		return Fraction(this->denominator, this->numerator);
	}

	void print() const
	{
		if (integer) cout << integer;//Если есть целая часть выводим ее на экран
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction //явно вызывваем конструктор, который создает временный объект
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	). to_proper().reduce();
	/*result.set_numerator(left.get_numenator() * right.get_numenator());
	result.set_denominator(left.get_denominator() * right.get_denominator);*/

}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction //явно вызывваем конструктор, который создает временный объект
	(
		left.get_numerator() * right.get_denominator() +
		right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()

	).to_proper().reduce();
	

}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction //явно вызывваем конструктор, который создает временный объект
	(
		left.get_numerator() * right.get_denominator() -
		right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()

	).to_proper().reduce();


}
Fraction operator/(Fraction left,  Fraction right)
{
	return left * right.inverted();

}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_numerator() <
		left.get_denominator() * right.get_denominator();
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_numerator() >
		left.get_denominator() * right.get_denominator();
}

bool operator==(Fraction left, Fraction right)
{
	
	return !(left == right);
}
bool operator<=(Fraction left, Fraction right)
{
	return !(left <= right);
}
bool operator>=(Fraction left, Fraction right)
{
	return !(left >= right);
}

bool operator!=( Fraction left, const Fraction right)
{
	
	return !(left != right);
}

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;//default constructor
	A.print();
	double b = 5;
	Fraction B = 5;
	B.print();
	Fraction C(0, 3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

	double a = 2.5;
	double b = 3.4;
	double c = a * b;
	cout << c << endl;
	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	/*Fraction C = A * B;
	C.print();
	C.reduce();
	C.print();*/

	/*Fraction D(840, 3600);
	D.reduce();
	D.print();*/

	/*C = A / B;
	C.print();*/

	/*A *= B;
	A.print();*/

	/*Fraction C = A + B;
	C.print();*/

	//Fraction C = A - B;
	//C.print();
	/*A += B;
	A.print();*/
	/*A -= B;
	A.print();*/

	/*A /= B;
	A.print();*/

	bool value1, value2;

	//value1 = A < B;
	//cout << "Value1 = "<< value1 << endl;

	//value2 = A > B;
	//cout << "Value1 = " << value2 << endl;

	//value1 = A <= B;
	//cout << "Value1 = " << value1 << endl;

	//value2 = A >= B;
	//cout << "Value1 = " << value2 << endl;

	value1 = A == B;
	cout << "Value1 = " << value1 << endl;

	value2 = A != B;
	cout << "Value1 = " << value2 << endl;
}