#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>

using namespace std;
class aeroflot {
public:
	char name[30]; //название рейса
	char number[10];
	char type[30];

	static int cmp(const void * a, const void * b)
	{
		return strcmp(((aeroflot*)a)->number, ((aeroflot*)b)->number);
	}
}A[10];

int main() {
	setlocale(LC_ALL, "Russian");
	char type[30];
	int i = 0;
	int kol = 0;
	int n;

	char a[30];
	char b;
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

		int x; //счётчик
		char sumbol; //символ

		x = 0;
		while (a[x]) {
			sumbol = a[x]; //выдеделяём символ
			b = (char)tolower(sumbol); //функция перевода регистров, из заглавной буквы в строчную
			a[x] = b; //выделенному символу присваем строчный вид
			x++;
		}
		strcpy(A[i].name, a);

		cout << "Введите номер рейса: ";
		cin >> A[i].number;

		cout << "Введите тип самолёта: ";
		cin >> a;

		x = 0;
		while (a[x]) {
			sumbol = a[x]; //выдеделяём символ
			b = (char)tolower(sumbol); //переводим его в строчный вид
			a[x] = b; //выделенному символу присваем строчный вид
			x++;
		}
		strcpy(A[i].type, a);
		cout << "\n\n";
	}


	qsort(A, n, sizeof(aeroflot), aeroflot::cmp);


	//Вывод записей
	cout << "Вывод записей на экран \n";
	for (i = 0; i<n; i++) {
		cout << A[i].name <<
			" " << A[i].number <<
			" " << A[i].type << "\n\n";
	}

	//Вывод записей определённого типа самолёта
	cout << "Введите тип самолёта: ";
	cin >> type;

	int x = 0;
	char character;

	while (type[x]) {
		character = type[x]; //выдеделяём символ
		b = (char)tolower(character); //переводим его в строчный вид
		type[x] = b; //выделенному символу присваем строчный вид
		x++;
	}

	cout << "Вывод номер рейсов и пунктов назначение, обслуживаемых типом " <<
		type << "\n";
	for (i = 0; i<n; i++) {
		if (strcmp(A[i].type, type) == 0) {
			cout << A[i].name << setw(11) << A[i].number << endl;
			kol++;
		}
	}
	if (kol == 0) {
		cout << "Таких записей нет \n";
	}
	system("pause");
}