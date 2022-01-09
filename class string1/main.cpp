#include"String.h"

#define delimiter "\n-------------------------------------\n"



//char str[] = { 's', 't', 'r', 'o', 'k', 'a' };
//#define CONSTRUCTORS_CHECK
#define OPERATORS_CHECK
//#define INPUT_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK

	String str1; //Default constructor
	str1.print();
	cout << str1 << endl;

	String str2(25); //Single-argument constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	cout << str3 << endl;

	String str4 = str3;//CopyConstructor
	cout << str4 << endl;

	String str5;
	str5 = str3; //CopyAssignment (operator = )
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK
	
#ifdef OPERATORS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
	str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;
	cout << delimiter << endl;
#endif // OPERATORS_CHECK

#ifdef INPUT_CHECK
	String str;
	cout << "Введите строку:\t";
	/*cin >> str;*/
	getline(cin, str);
	cout << str << endl;
	str.print();
#endif // INPUT_CHECK

	//String str1; //Default constructor
	//str1.print();
	//String str2 = "Hello"; //Single-argument constructor
	//str2.print();
	//String str3 = str2; //CopyConstructor
	//str3.print();
	//String str4(); //Здесь не вызывается никакой конструктор, 
	//поскольку здесь не создается обьект, а обьявляется функция str4
	//которая ничего не принимает и возвращ0ает значение типа String
	/*str4.print();*/

}