#include <string> 
#include <iostream> 
#include <fstream> 
#include <sstream> 

using namespace std;

//проверяем, является ли гласной 
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
		string word;//строка 
		stringstream ss;
		while (in>> word) {//считываем по предложению 
						   //проверяем на гласность 
			if (word.size() > 0 && isAlpfa(word[0])) {
				ss<< word<< ' ';//выводим в поток 
			}
			cout<< ss.str();// выводим предложения 
			in.close();//закрываем файл 
		}
	}
	catch (const int &ex)
	{
		cout<< "Ошибка открытия файла!"<< endl<< "Код ошибки: #"<< ex<< endl;
	}
	system("pause»void");
}