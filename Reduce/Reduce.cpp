//Fraction

#pragma warning (disable:4326)//отключаем warning по коду
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

	Fraction(double decimal)
	{
		decimal += 1e-11;
		integer = decimal;
		denominator = 1e+9; //1*10^9
		decimal -= integer;//убираем целую часть из десятичной дроби
		numerator = decimal * denominator;
		reduce();
		std::cout << "1argConstructor for double:\t" << this << std::endl;
	}


	explicit Fraction(int integer)
//explicit - явный, разрешает только явные преобразования
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

	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
	}
	
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
		//		A	 =	A	/	B;
	}

	//type-cast operators:

	explicit operator int()const
	{
		return integer;
	}

	explicit operator double() const
	{
		
		return integer + double(numerator) / denominator;
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

	std::ostream& print(std::ostream&os) const
	{
		if (integer) os << integer;//Если есть целая часть выводим ее на экран
		if (numerator)
		{
			if (integer) os << "(";
			os << numerator << "/" << denominator;
			if (integer) os << ")";
		}
		else if (integer == 0) os << 0;
		return os;
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

bool operator!=( Fraction left,  Fraction right)
{
	
	return !(left != right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj) 
{
	//if (obj.get_integer()) os << obj.get_integer();//Если есть целая часть выводим ее на экран
	//if (obj.get_numerator())
	//{
	//	if (obj.get_integer()) os << "(";
	//	os << obj.get_numerator() << "/" << obj.get_denominator();
	//	if (obj.get_integer()) os << ")";
	//}
	//else if (obj.get_integer() == 0) os << 0;
	//return os;
	return obj.print(os);
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	//int integer;
	//int numerator;
	//int denominator;
	//is >> integer >> numerator >> denominator;

	//obj.set_integer(integer);
	//obj.set_numerator(numerator);
	//obj.set_denominator(denominator);

	const int size = 256;
	char buffer[size] = {};
	char delimiters[] = "() /";
	is.getline(buffer, size);
	char* number[3] = {}; // Этот массив будет хранить части строки, полученные при помощи strtok 
	int n = 0; //Индекс элемента в массиве number
	for (char* pch = strtok(buffer,delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = pch;
	}
	//for (size_t i = 0; i < n; i++)
	//{
	//	cout << number[i] << "\t";
	//}
	//cout << endl;

	switch (n)
	{
	case 1: obj.set_integer(atoi(number[0])); break;
		case 2: 
			obj.set_numerator(atoi(number[0]));
			obj.set_denominator(atoi(number[1])); break;
		case 3: obj.set_integer(atoi(number[0]));
			obj.set_numerator(atoi(number[1]));
			obj.set_denominator(atoi(number[2]));
	}

	return is;
}

//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define FROM_OTHER_TO_CLASS
//#define HOME_WORK
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

#ifdef OPERATORS_CHECK
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
#endif // OPERATORS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2; //NO conversion
	double b = 3; //From less to more
	int c = b; //From more to less without data loss
	int d = 4.5; //From more to less with data loss
	cout << d << endl;
#endif // TYPE_CONVERSIONS_BASICS

#ifdef FROM_OTHER_TO_CLASS

	double a = 2;//from int to double
	Fraction A = (Fraction)5; //from int ro fraction
	//Single - argument constructor
	A.print();

	Fraction B;
	cout << "\n_______________________\n";
	B = Fraction(8);//CopyAssignment
	cout << "\n_______________________\n";
	B.print();

	//Fraction C = 12;//explicit constructor невозможно вызвать так
	Fraction C(12); //НО explicit constructor всегда можно вызвать так 
	Fraction D{ 13 }; //или вот так    
#endif // FROM_OTHER_TO_CLASS
	
	//double b = 2; //From more to less
	////from double to int 
	//int c = 2;

	//Fraction A(2);
	//int a(A);
	//cout << a << endl; 
	//int i = (int)A;

#ifdef HOME_WORK

	Fraction A{ 2,3,4 };
	double a = A;//Преобазуем наш тип в другой тип
	cout << a << endl;

	double b = 2.75;
	Fraction B = b; //преобразуем другой тип в наш, для этого нужен констуктор с одним параметром типа double
	B.print();
#endif // HOME_WORK

	Fraction A(2, 3, 4);
	cout << A << endl;
	Fraction B;
	cout << "Введите простую дробь: \t";
	cin >> B;
	cout << B << endl;
}