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
	bool operator==(const aeroflot& a) const {
		return strcmp(a.name, name) == 0 && strcmp(a.number, number) == 0 && strcmp(a.type, type) == 0;
	}
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

/*������*/

class AeroListItem;

class AeroList
{
	AeroListItem 	*p_first;
	AeroListItem 	*p_last;
	size_t			_count;
public:
	int				AddItem(const aeroflot &pData, bool fFreeSelf = true);//���������� ��������
	void            Delete(size_t id);//�������� �������� �� ������
	int             DelItem(AeroListItem *item);//�������� �������� �� ������
	AeroListItem	*Next(AeroListItem * item);//��������� �������
	AeroListItem	*Prev(AeroListItem * item);//���������� �������
	AeroListItem	*ItemById(size_t id);//������� �� ��� Id
	aeroflot operator[](size_t id);//��������� �������� �� id
	size_t			Count();//������ ������
	void			Flush();//������� ������

	AeroList();	//�����������
	~AeroList(); //����������
};

class AeroListItem//������� ������
{
	AeroListItem 		*p_prev; //������ �� ���������� �������
	AeroListItem 		*p_next;
	bool				is_free; //������ ��

	aeroflot					m_pData;//������
	AeroListItem();
	~AeroListItem();

public:
	aeroflot					data();
	friend				AeroList;
};


AeroList::AeroList()
{
	p_first = p_last = nullptr;
	_count = 0;
}

AeroList::~AeroList()//����������
{
	while (p_first)
	{
		DelItem(p_first);
	}
	p_first = p_last = nullptr;
}

void AeroList::Delete(size_t id)
{
	DelItem(ItemById(id));
}

void AeroList::Flush()
{
	while (p_first)
	{
		DelItem(p_first);
	}
	p_first = p_last = nullptr;
}

size_t AeroList::Count()
{
	return _count;
}

int AeroList::AddItem(const aeroflot &pData, bool fFreeSelf)
{
	AeroListItem * item = new AeroListItem;

	item->m_pData = pData;
	item->is_free = fFreeSelf;

	if (!p_first && !p_last)
	{
		p_first = p_last = item;
	}
	else
	{
		p_last->p_next = item;
		item->p_prev = p_last;
		p_last = item;
	}

	return ++_count;
}

int AeroList::DelItem(AeroListItem *item)
{
	if (item->p_next && item->p_prev)
	{
		item->p_next->p_prev = item->p_prev;
		item->p_prev->p_next = item->p_next;
	}
	else if (!item->p_next && item->p_prev)
	{
		item->p_prev->p_next = nullptr;
		p_last = item->p_prev;
	}
	else if (item->p_next && !item->p_prev)
	{
		item->p_next->p_prev = nullptr;
		p_first = item->p_next;
	}
	else
	{
		p_first = p_last = nullptr;
	}
	delete item;
	return --_count;
}

aeroflot AeroList::operator[](size_t id)
{
	if (id >= _count) return aeroflot();

	for (AeroListItem * item = Next(0); item; item = Next(item))
	{
		if (!id--)
		{
			return item->m_pData;
		}
	}
	return aeroflot();
}

AeroListItem *AeroList::ItemById(size_t id)
{
	if (id >= _count)
	{
		return nullptr;
	}
	for (AeroListItem * item = Next(0); item; item = Next(item))
	{
		if (!id--)
		{
			return item;
		}
	}

	return nullptr;
}


AeroListItem *AeroList::Next(AeroListItem *item)
{
	return (item ? item->p_next : p_first);
}

AeroListItem *AeroList::Prev(AeroListItem *item)
{
	return (item ? item->p_prev : p_last);
}

AeroListItem::AeroListItem()
{
	p_next = p_prev = nullptr;
	m_pData = aeroflot();
	is_free = true;
}

AeroListItem::~AeroListItem()
{
	if (is_free)
	{
		m_pData = aeroflot();
	}
	p_next = p_prev = nullptr;
}

aeroflot AeroListItem::data()
{
	return m_pData;
}

void to_low(char mas[]) {
	int x = 0;
	char b, sumbol;
	while (mas[x]) {
		sumbol = mas[x]; //���������� ������
		b = (char)tolower(sumbol); //������� �������� ���������, �� ��������� ����� � ��������
		mas[x] = b; //����������� ������� �������� �������� ���
		x++;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	string path = "File.txt";
	char type[30];
	char a[30];
	AeroList A;
	int i = 0;
	int kol = 0;
	int n;
	char b;


	cout << "|1|\t������ ������ � ����������\n|2|\t������� ������ �� �����\n\n";
	int swtch = 1;
	cin >> swtch;
	switch (swtch)
	{
	case 1:
	{
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
			aeroflot temp;
			to_low(a);
			temp.set_name(a);

			cout << "������� ����� �����: ";
			cin >> a;
			temp.set_number(a);

			cout << "������� ��� �������: ";
			cin >> a;
			to_low(a);
			temp.set_type(a);
			cout << "\n\n";
			A.AddItem(temp);
		}

		//���������� �� ������ �����
		qsort(&A, n, sizeof(aeroflot), aeroflot::cmp);

		//������ � ����
		cout << "�������� ������ � ����? 1 -> ��, 2 -> ��� ";
		int chois = 0;
		cin >> chois;
		if (chois == 1)
		{
			ofstream fout;
			fout.open(path, ofstream::out);
			if (!fout.is_open())
			{
				cout << "������ �������� �����!" << endl;
			}
			else
			{
				cout << "���� ������!" << endl;
				fout << n << '\n';
				for (int i = 0; i < n; i++)
				{
					fout << A[i].get_name() << ' ' << A[i].get_number() << ' ' << A[i].get_type() << '\n';
					//fout.write((char*)&A[i], sizeof(aeroflot));
				}
			}
			fout.close();
			system("File.txt");
		}
		break;
	}
	case 2:
	{
		//���������� ������ �� �����
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "������ �������� �����!" << endl;
		}
		else
		{
			cout << "���� ������!" << endl;
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
				A.AddItem(temp);
			}
		}
		fin.close();
		system("File.txt");
		break;
	}
	default:
		break;
	}

	//����� �������
	cout << "����� ������� �� ����� \n";
	for (i = 0; i<n; i++)
		A[i].Print();

	//����� ������� ������������ ���� �������
	cout << "������� ��� �������: ";
	cin >> type;
	to_low(type);

	cout << "����� ����� ������ � ������� ����������, ������������� ����� " << type << "\n";
	for (i = 0; i<n; i++) {
		if (strcmp(A[i].get_type(), type) == 0) {
			A[i].Print();
			kol++;
		}
	}
	if (kol == 0) cout << "����� ������� ��� \n";
	system("pause");
}