#include <iostream>

using namespace std;

class Binary
{
	bool* number;//�������� �����
	unsigned int capacity; //����������� �����
	
public:
	Binary()
	{
		capacity = 8;//�� ��������� ����� ����� ������������ �������� 1 ����
		number = new bool[capacity] {};
		cout << "DefaultConstructor: \t" <<this<< endl;
	}
	Binary(int decimal)
	{
		int buffer = decimal;
		//���������� ���-�� �������� ��������:
		capacity = 0;
		for (; buffer; capacity ++)
		{
			buffer /= 2;
		}
		//����������� ����������� ��������� ����� �� ������� �����:
		if (capacity < 8) capacity = 8;
		else if (capacity < 16) capacity = 16;
		else if (capacity < 24) capacity = 24;
		else if (capacity < 32) capacity = 32;
		//��� ����� ��� ����, ����� ���� �������� ����� �������� 1,2,3 ���� 4 �����

		//�������� ������ ��� ���� �������� �����:
		number = new bool[capacity] {};
		// ��������� ���������� ����� � �������� ������� ���������:
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
		//os.width(); - ������ ������ ���������� ����
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

	Binary num2 = 380; //�������� ����� �������������� ���������� ������
	cout << num2 << endl;
}