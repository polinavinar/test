#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//���������, �������� �� �������
bool isAlpfa(char var) {
	switch (var) {
	case 'a':
		return true;
	case 'A':
		return true;
	case 'y':
		return true;
	case 'Y':
		return true;
	case 'e':
		return true;
	case 'E':
		return true;
	case 'i':
		return true;
	case 'I':
		return true;
	case 'o':
		return true;
	case 'O':
		return true;
	case 'u':
		return true;
	case 'U':
		return true;
	default:
		return false;
	}
}

int main() {
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string word;//������
	stringstream ss;
	while (in >> word) {//��������� �� �����������
						//��������� �� ���������
		if (word.size() > 0 && isAlpfa(word[0])) {
			ss << word << ' ';//������� � �����
		}
	}
	cout << ss.str();// ������� �����������
	in.close();//��������� ����										   
	system("pause>>void");
}