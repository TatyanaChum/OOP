#include"String.h"
//:: - оператор разрешения видимости (Scope operator)
int String::get_size() const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}

String::String(int size) :size(size), str(new char[size] {})
{
	/*this->size = size;
	this->str = new char[size] {};*///Память, выделяемую для строки обязательно нужно занулить
	cout << "SizeConstructor:\t" << this << endl;
}

String::String(const char str[]) :size(strlen(str) + 1), str(new char[size] {})
{
	/*this->size = strlen(str) + 1;
	this->str = new char[size] {};*/
	for (int i = 0; str[i]; i++) this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :size(other.size), str(new char [size] {})
{
	/*this->size = other.size;
	this->str = new char[size] {};*/
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << endl;

}
//Operators:

String& String::operator= (const String& other)
{
	if (this == &other) return *this;//Проверяем не является ли this  и other одним и тем же объектом
	delete[]this->str;
	//Deep copy (Побитовое копирование)
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return*this;
}

String& String:: operator +=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i) const
{
	return str[i];
}

char& String::operator[](int i)
{
	return str[i];
}
//Methods:

void String::print() const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (size_t i = 0; i < left.get_size(); i++)
		// l-value = r - value
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		result[i + left.get_size() - 1] = right[i];
	return result;
}

std::ostream& operator <<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator >>(std::istream& is, String& obj)

{
	/*return is.getline(obj.get_str(), 255);*/
	/*return is >> obj.get_str();*/
	const int SIZE = 10240;
	char buffer[SIZE] = {};

	is >> buffer;
	obj = buffer;
	return is;

}

std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}