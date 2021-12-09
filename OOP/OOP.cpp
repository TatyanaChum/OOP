﻿// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

// Обьектно-ориентированное программирование (ООП) - это подход, при котором программ строится из объектов и взаиможействия между этими объектами.
// Ключевым понятием ООП является объект.
// Обьект - некая сущность, которая существует в пространстве и времени. Каждый обьект можно как-то охарактеризовать.
// Нас везде окружают обьекты - телефоны, компьютеры, машины, животные, люди. Это все обьекты.
#define tab "\t"

class Point
{
	double x;
	double y;
public:
	//get-методы дожны быть константными
	//константным называется метод, который НЕ изменяет объект, 
	//для которого вызывается.
	//Для константного объекта могут быть вызваны только константные методы
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//constructor
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = double(); //double() - значение по умолчанию для типа double
	//	//double() - якобы вызываем конструктор по умолчанию для double
	//	cout << "1argConstructor:\t" << this << endl;
	//}
	Point(double x = 0, double y = 0)//Point(double x = 0, double y = 0) параметры по умолчанию, defolt parametres, х = 0 и y = 0 значение по умолчанию.
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
	}
	//Methods:
	double distance(Point other)
	{
		//other другой, другая точка
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
			//sqrt - Square Root(квадратный корень)
		return distance;
	}
	void Print() const
	{ 
		cout << "X= " << x << "\tY = " << y << endl;
	}
};
//#define STRUCT_POINT
//Point G;// глобальный обьект.
//int g;// глобальная переменная DEPRECATED - не рекомендуется для использования
//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	//type name;
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
			//Объявление объекта 'A' структуры 'Point'
			//Создание экземпляра 'A' структуры 'Point'
	//instance - экземпляр
	//instantiate - создать экземпляр
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//Объявляем указатель на Point 'pA', 
					//и инициализируем его адресом объекта 'A'
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.Print();

	Point B(4, 5);
	B.Print();

	Point C = 5; // Single - argument constructor
	C.Print();

	Point D(8); // single - argument constructor
	D.Print();
#endif //CONSTRUCTORS_CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << "distance A and B = " << A.distance(B) << endl;
	cout << "distance B and A = " << B.distance(A) << endl;
	/*
	----------------------------------------------
	.  - Оператор прямого доступа	(Point operator)
	-> - Оператор косвенного доступа(Arrow operator)
	----------------------------------------------
	*/

	/*
	----------------------------------------------
	1. Инкапсуляция (Encapsulation);
		Модификаторы доступа:
			-private:	закрытые поля, доступны только изнутри класса;
			-public:	открытые поля, доступны из любого места программы;
			-protected: защищенные поля, используются только при наследовании
						доступны внутри нашего класса, и внутри дочерних классов;
		get/set-методы:
		get (взять, получить)
		set (задать, установить)
	2. Наследование (Inheritance);
	3. Полиморфизм (Polymorphism);
	----------------------------------------------
	*/
	// Конструкторы.
	// абсолютно во всех классах есть некоторые методы, которые играют особую роль. К ним относятся конструктор, деструктор и оператор присвоить.
	// конструктор - метод который создает обьект. А точнее, он выделяет память под обьект и инициализирует его переменные члены.
	// деструктор - метод, который уничтожает объект по завершении его времени жизни. Время жизни обьекта завершается при выходе за пределелы области видимости, в которой он обьявлен. Это любые фигурные скобки.
	// Конструктор и деструктор всегда называются так же как и класс. НО перед деструктором еще ставится символ ` (тильда)
	// конструктор может принимать параметры, поэтому как и любую другую функцию его можно перегрузить. И поэтому в классе может быть сколько угодно конструкторов.
	// Деструктор же никогда не принимает никаких параметров. Поэтому и перегрузить его нельзя. Следовательно в классе может только один деструктор.
	// Обьекты можно создавать по разному, но все обьекты удаляются одинаково, вне зависимости от того как они были созданы.
	// Конструкторы бывают с парамтерами, без параметров, по умолчанию, конструктор копирования и конструктов переноса.
	// Констурктор по умолчанию или defolt constructor - констурктор, который может быть вызван без параметров. Это может быть конструктор не принимающий никаких параметров или же 
	// конструктор какждый параметр которого имеет значение по умолчанию.
	// Если в классе нет не единого конструктора, то компилятор сам не явно добаит туда конструктор по умолчанию, по скольку без конструктора не возможно создать обьект.
	// Такой не явный конструктор по умолчанию просто выделяет память под обьект и заполняет его переменные члены мусором. 
	// Хотя конструктор по умолчанию должен заполнять переменные члены значениями по умолчанию.
	// Конструктор по умолчанию вызывается не явно всякий раз, когда мы просто создаем обьект и не определяем каким он будет этот обьект
	//Конструкторы и деструктор никогда не возвращают никаких значений и при этом перед ними не пишется ключевое слово void.
	// если мы хотим создаать обьекты и определять какими они будут, то в классе должен быть констурктор с параметрами
	// Особое место здесь занимает конструкто с одним параметром, но в принципе конструктр может принимать сколько угодно парамтеров.
	// 



	//for (size_t i = 0; i < 10; i++)
	//{
	//	cout << i << tab;

	//}
	////cout << i << endl;
	//cout << endl;
	// безфмянное пространство имен
	/*{
		int a = 2;
	}*/ 
	//cout << a << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.