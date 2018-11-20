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
	case 'y':
		return true;
	case 'e':
		return true;
	case 'i':
		return true;
	case 'o':
		return true;
	case 'u':
		return true;
	default:
		return false;
	}
}

int main() {
	setlocale(LC_ALL, "");
	ifstream in;
	try
	{
		in.open("input.txt");
		if (!in.is_open()) {
			throw 505;
		}
		string word;//������ 
		stringstream ss;
		while (in>> word) {//��������� �� ����������� 
						   //��������� �� ��������� 
			if (word.size() > 0 && isAlpfa(word[0])) {
				ss<< word<< ' ';//������� � ����� 
			}
			cout<< ss.str();// ������� ����������� 
			in.close();//��������� ���� 
		}
	}
	catch (const int &ex)
	{
		cout<< "������ �������� �����!"<< endl<< "��� ������: #"<< ex<< endl;
	}
	system("pause�void");
}