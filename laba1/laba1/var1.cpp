#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>

using namespace std;
class aeroflot {
private:
	char name[30];
	char number[10];
	char type[30];
public:

	void Print() {
		cout << name << "\t" << number << "\t" << type << "\n\n";
	}
	void set_name(char *_name) {
		strcpy(name, _name);
	}
	void set_number(char *_number) {
		strcpy(number, _number);
	}
	void set_type(char *_type) {
		strcpy(type, _type);
	}

	char* get_name() {
		return name;
	}
	char* get_number() {
		return number;
	}
	char* get_type() {
		return type;
	}

	static int cmp(const void * a, const void * b)
	{
		return strcmp(((aeroflot*)a)->number, ((aeroflot*)b)->number);
	}
};

void to_low(char mas[]) {
	int x = 0;
	char b, sumbol;
	while (mas[x]) {
		sumbol = mas[x]; //выдеделяём символ
		b = (char)tolower(sumbol); //функция перевода регистров, из заглавной буквы в строчную
		mas[x] = b; //выделенному символу присваем строчный вид
		x++;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	string path = "File.txt";
	char type[30];
	char a[30];
	aeroflot *A = new aeroflot[10];
	int i = 0;
	int kol = 0;
	int n;
	char b;


	cout << "|1|\tВвести данные с клавиатуры\n|2|\tСчитать данные из файла\n\n";
	int swtch = 1;
	cin >> swtch;
	switch (swtch)
	{
	case 1:
	{
		cout << "Количество записей? (максимум 7): ";
		do {
			cin >> n;
			if (n>7) {
				cout << "Вы ввели больше 7, введите число, меньше 7: ";
			}
		} while (n>7);
		cout << "\n\n";

		//Ввод записей
		for (i = 0; i<n; i++) {
			cout << "Введите название пункта назначения рейса : ";
			cin >> a;
			to_low(a);
			A[i].set_name(a);

			cout << "Введите номер рейса: ";
			cin >> a;
			A[i].set_number(a);

			cout << "Введите тип самолёта: ";
			cin >> a;
			to_low(a);
			A[i].set_type(a);
			cout << "\n\n";
		}

		//сортировка по номеру рейса
		qsort(A, n, sizeof(aeroflot), aeroflot::cmp);

		//запись в файл
		cout << "Записать данные в файл? 1 -> ДА, 2 -> НЕТ ";
		int chois = 0;
		cin >> chois;
		if (chois == 1)
		{
			ofstream fout;
			fout.open(path, ofstream::out);
			if (!fout.is_open())
			{
				cout << "Ошибка открытия файла !" << endl;
			}
			else
			{
				cout << "Файл открыт!" << endl;
				for (int i = 0; i < n; i++)
				{
					fout.write((char*)&A[i], sizeof(aeroflot));
				}
			}
			fout.close();
			system("File.txt");
		}
		break;
	}
	case 2:
	{
		//считывание данных из файла
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		else
		{
			cout << "Файл открыт!" << endl;
			i = 0;
			while (fin.read((char*)&A[i], sizeof(aeroflot)))
			{
				//A[i].Print();
				i++;
			}
			n = i;
		}
		fin.close();
		system("File.txt");
		break;
	}
	default:
		break;
	}

	//Вывод записей
	cout << "Вывод записей на экран \n";
	for (i = 0; i<n; i++)
		A[i].Print();

	//Вывод записей определённого типа самолёта
	cout << "Введите тип самолёта: ";
	cin >> type;
	to_low(type);

	cout << "Вывод номер рейсов и пунктов назначение, обслуживаемых типом " << type << "\n";
	for (i = 0; i<n; i++) {
		if (strcmp(A[i].get_type(), type) == 0) {
			A[i].Print();
			kol++;
		}
	}
	if (kol == 0) cout << "Таких записей нет \n";
	delete[] A;
	system("pause");
}