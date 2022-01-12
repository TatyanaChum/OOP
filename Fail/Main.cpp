#include<iostream>
#include <fstream>

using namespace std;
//#define WRITE_TO_FILE
void main()

{

	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	cout << "Hello World" << endl;
	ofstream fout("file.txt", ios::app);
	//app - append (добавить, дописать)
	fout << "Connecting World" << endl;
	fout.close();
	system("notepad file.txt");

#endif // WRITE_TO_FILE




	const int size = 1024;
	char buffer[size]{};

	ifstream fin; //Создаем поток
	fin.open("file.txt");
	if (fin.is_open())
	{
		//читаем файл
		while (!fin.eof())//пока не конец файла(end of file)
		{
			//fin >> buffer;
			fin.getline(buffer, size);
			cout << buffer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	fin.close();

}