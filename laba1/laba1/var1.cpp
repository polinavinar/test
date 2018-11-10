#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include "List.h"


using namespace std;

class aeroflot {
private:
	char name[30];
	char number[10];
	char type[30];
public:
	aeroflot & operator=(const aeroflot& a) {
		strcpy(name, a.name);
		strcpy(number, a.number);
		strcpy(type, a.type);
		return *this;
	}
	bool operator==(const aeroflot& a) const {
		return strcmp(a.name, name) == 0 && strcmp(a.number, number) == 0 && strcmp(a.type, type) == 0;
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

	static int cmp(const aeroflot& a, const aeroflot& b)
	{
		return strcmp(a.number, b.number);
	}
	friend istream& operator >> (istream& in, aeroflot& a) {
		in >> a.name >> a.number >> a.type;
		return in;
	}

	friend ostream& operator << (ostream& out, const aeroflot& a) {
		out << a.name << "\t" << a.number << "\t" << a.type << "\n\n";
		return out;
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

void bsort(list<aeroflot>& A, int size) {
	int j, n = size;
	do {
		int nn = 0;
		for (j = 1; j < n; ++j)
			if (aeroflot::cmp(A[j - 1], A[j]) > 0) {
				aeroflot temp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = temp;
				nn = j;
			}
		n = nn;
	} while (n);
}


int main() {
	setlocale(LC_ALL, "Russian");
	string path = "File.txt";
	char type[30];
	char a[30];
	list<aeroflot> A;
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

			cout << "Введите название пункта назначения рейса\n";
			cout << "Введите номер рейса\n";
			cout << "Введите тип самолёта\n";
			cout << "\n\n";
			aeroflot temp;
			cin >> temp;
			A.add(temp);
		}

		//сортировка по номеру рейса
		bsort(A, n);

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
				cout << "Ошибка открытия файла!" << endl;
			}
			else
			{
				cout << "Файл открыт!" << endl;
				fout << n << '\n';
				for (int i = 0; i < n; i++)
				{
					fout << A[i].get_name() << ' ' << A[i].get_number() << ' ' << A[i].get_type() << '\n';
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
			fin >> n;
			for (i = 0; i < n; ++i)
			{
				aeroflot temp;

				char t[30];
				fin >> t;
				temp.set_name(t);
				fin >> t;
				temp.set_number(t);
				fin >> t;
				temp.set_type(t);
				A.add(temp);
			}
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

	//Вывод записей определённого типа самолёта
	cout << "Введите тип самолёта: ";
	cin >> type;
	to_low(type);

	cout << "Вывод номер рейсов и пунктов назначение, обслуживаемых типом " << type << "\n";
	for (i = 0; i<n; i++) {
		if (strcmp(A[i].get_type(), type) == 0) {
			kol++;
		}
	}
	if (kol == 0) cout << "Таких записей нет \n";
	system("pause");
}