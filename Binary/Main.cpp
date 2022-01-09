#include <iostream>

using namespace std;

class Binary
{
	bool* number;//Двоичное число
	unsigned int capacity; //разрядность числа
	
public:
	Binary()
	{
		capacity = 8;//по умолчанию число будет разрядностью занимать 1 байт
		number = new bool[capacity] {};
		cout << "DefaultConstructor: \t" <<this<< endl;
	}
	Binary(int decimal)
	{
		int buffer = decimal;
		//определяем кол-во двоичных разрядов:
		capacity = 0;
		for (; buffer; capacity ++)
		{
			buffer /= 2;
		}
		//выравниваем разрядность двоичного числа по границе Байта:
		if (capacity < 8) capacity = 8;
		else if (capacity < 16) capacity = 16;
		else if (capacity < 24) capacity = 24;
		else if (capacity < 32) capacity = 32;
		//это нужно для того, чтобы наши двоичные числа занимали 1,2,3 либо 4 байта

		//Выделяем память под наше двоичное число:
		number = new bool[capacity] {};
		// переводим десятичное число в двоичную Систему счисления:
		for (int i = 0; decimal; i++)
		{
			number[i] = decimal % 2;
			decimal /= 2;
		}
	}
	~Binary()
	{
		delete[]number;
		number = nullptr;
		capacity = 0;
		cout << "Destructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os = std::cout) const
	{
		if (capacity == 8) os.width(11*3);
		if (capacity == 16) os.width(11*2);
		if (capacity == 24) os.width(11);
		//os.width(); - задает ширину выводимого поля
		for (int i = capacity - 1; i >= 0; i--) 
		{
			os << number[i];
			if (i % 8 == 0) cout << " ";
			if (i % 4 == 0) cout << " ";
			
		}
		return os;
	}

};

std::ostream& operator<<(std::ostream& os, const Binary& obj)
{
	return obj.print(os);
}

void main()
{
	setlocale(LC_ALL, "");
	Binary num1;
	num1.print();
	cout << endl;

	Binary num2 = 380; //двоичное число инициализируем десятичным числом
	cout << num2 << endl;
}