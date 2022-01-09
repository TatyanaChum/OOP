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

	~Binary()
	{
		delete[]number;
		number = nullptr;
		capacity = 0;
		cout << "Destructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os = std::cout) const
	{
		for (int i = capacity - 1; i >= 0; i--) 
		{
			cout << number[i];
			if (i % 8 == 0) cout << " ";
			if (i % 4 == 0) cout << " ";
			
		}
		return os;
	}

};

void main()
{
	setlocale(LC_ALL, "");
	Binary num1;
	num1.print();
}