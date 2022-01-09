#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Matrix;
Matrix operator+ (const Matrix str1, const Matrix str2);
Matrix operator- (const Matrix str1, const Matrix str2);
Matrix operator* (const Matrix str1, const Matrix str2);
#define delimiter "\n---------------------------\n"




class Matrix
{
	int length;
	int witdh;
	int** matrix;

public:
	const int get_length() const
	{
		return length;
	}

	const int get_witdh() const
	{
		return witdh;
	}

	int** get_matrix()
	{
		return matrix;
	}

	Matrix(int length = 2, int witdh = 2)
	{
		this->length = length;
		this->witdh = witdh;
		this->matrix = new int* [length] {};
		for (size_t i = 0; i < length; i++)
		
			matrix[i] = new int[witdh] {};
		cout << "DefaultConstructor: \t" << this << endl;
	}

	Matrix(const Matrix& other)
	{
		this->length = other.length;
		this->witdh = other.witdh;
		this->matrix = new int* [length] {};
		for (size_t i = 0; i < length; i++)
			for (size_t j = 0; j < witdh; j++)
			{
				matrix[i][j] = other.matrix[i][j];
			}
			
		cout << "CopyConstructor: \t" << this << endl;
	}
	~Matrix()
	{
		for (size_t i = 0; i < length; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	void rand_matrix()
	{
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < witdh; j++)
			{
				matrix[i][j] = rand() % 10;
				
			}
		}
	}

	void input_matrix()
	{
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < witdh; j++)
			{
				cin >> matrix[i][j];
			}
		}
	}

	void print()
	{
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < witdh; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	int* operator[](int i)
	{
		return matrix[i];
	}

	const int* operator[](int i) const
	{
		return matrix[i];
	}

	
};
Matrix operator+(const Matrix str1, const Matrix str2)
{
	Matrix result(str1.get_length(), str1.get_witdh());
	for (size_t i = 0; i < str1.get_length(); i++)
	{
		for (size_t j = 0; j < str1.get_witdh(); j++)
		{
			result[i][j] = str1[i][j] + str2[i][j];

		}
	}
	return result;
}
Matrix operator-(const Matrix str1, const Matrix str2)
{
	Matrix result(str1.get_length(), str1.get_witdh());
	for (size_t i = 0; i < str1.get_length(); i++)
	{
		for (size_t j = 0; j < str1.get_witdh(); j++)
		{
			result[i][j] = str1[i][j] - str2[i][j];

		}
	}
	return result;
}
Matrix operator*(const Matrix str1, const Matrix str2)
{
	Matrix result(str2.get_length(), str1.get_witdh());
	for (size_t i = 0; i < str1.get_length(); i++)
	{
		for (size_t j = 0; j < str1.get_witdh(); j++)
		{
			result[i][j] = str1[i][j] * str2[i][j];

		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "");


	Matrix A(2, 2);
	A.rand_matrix();
	
	A.print();
	

	
	Matrix B(2, 2);
	B.rand_matrix();
	
	B.print();

	Matrix C =  A + B;
	
	C.print();
	

}