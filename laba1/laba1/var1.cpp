#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>

using namespace std;
class aeroflot {
public:
	char name[30]; //�������� �����
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
	cout << "���������� �������? (�������� 7): ";
	do {
		cin >> n;
		if (n>7) {
			cout << "�� ����� ������ 7, ������� �����, ������ 7: ";
		}
	} while (n>7);

	cout << "\n\n";

	//���� �������
	for (i = 0; i<n; i++) {
		cout << "������� �������� ������ ���������� ����� : ";
		cin >> a;

		int x; //�������
		char sumbol; //������

		x = 0;
		while (a[x]) {
			sumbol = a[x]; //���������� ������
			b = (char)tolower(sumbol); //������� �������� ���������, �� ��������� ����� � ��������
			a[x] = b; //����������� ������� �������� �������� ���
			x++;
		}
		strcpy(A[i].name, a);

		cout << "������� ����� �����: ";
		cin >> A[i].number;

		cout << "������� ��� �������: ";
		cin >> a;

		x = 0;
		while (a[x]) {
			sumbol = a[x]; //���������� ������
			b = (char)tolower(sumbol); //��������� ��� � �������� ���
			a[x] = b; //����������� ������� �������� �������� ���
			x++;
		}
		strcpy(A[i].type, a);
		cout << "\n\n";
	}


	qsort(A, n, sizeof(aeroflot), aeroflot::cmp);


	//����� �������
	cout << "����� ������� �� ����� \n";
	for (i = 0; i<n; i++) {
		cout << A[i].name <<
			" " << A[i].number <<
			" " << A[i].type << "\n\n";
	}

	//����� ������� ������������ ���� �������
	cout << "������� ��� �������: ";
	cin >> type;

	int x = 0;
	char character;

	while (type[x]) {
		character = type[x]; //���������� ������
		b = (char)tolower(character); //��������� ��� � �������� ���
		type[x] = b; //����������� ������� �������� �������� ���
		x++;
	}

	cout << "����� ����� ������ � ������� ����������, ������������� ����� " <<
		type << "\n";
	for (i = 0; i<n; i++) {
		if (strcmp(A[i].type, type) == 0) {
			cout << A[i].name << setw(11) << A[i].number << endl;
			kol++;
		}
	}
	if (kol == 0) {
		cout << "����� ������� ��� \n";
	}
	system("pause");
}