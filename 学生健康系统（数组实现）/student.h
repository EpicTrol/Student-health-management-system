#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;
#ifndef X
#define F1

fstream file;

struct student
{
	string name, sex, health;
	int num, year, month, day;

	student(int x = 0, string n = "", int y = 0, int m = 0, int d = 0, string s = "", string h = "")
	{
		num = x;
		name = n;
		year = y;
		month = m;
		day = d;
		sex = s;
		health = h;
	}
	~student()
	{
		num = 0;
		name = "";
		year = 0;
		month = 0;
		day = 0;
		sex = "";
		health = "";
	}
	bool operator==(student &s)
	{
		if (num == s.num&&name == s.name&&sex == s.sex&&year == s.year&&month == s.month&&day == s.day)
			return true;
		else
			return false;
	}
};

template<class T>
class Array
{
public:
	Array(int m = 20, int la = 0, T *da = NULL)
	{
		maxSize = m;
		last = la;
		data = da;
	}
	void create(int m);  //�½�ѧ��������
	void add(T &s);     //��ѧ�����������ѧ����Ϣ
	void Search(int x); //�ڽ������в�ѯѧ����Ϣ�����
	void del(int x);    //ɾ������ѧ��������Ϣ
	//void delall();      //ɾ�������
	void write();       //���ļ���д�뽡������Ϣ
	void read();        //���ļ���ȡѧ����������Ϣ
	void show(T &s);    //��ʾ������ѧ����Ϣ
	void showall();     //����Ļ�����ȫ��ѧ����Ϣ
private:
	int maxSize;
	int last;
	T *data;
};

template<class T>
void print(T &s);

template<class T>
 void Array<T>::create(int m)
{
	maxSize = m;
	last = 0;
	data = new T[maxSize];
}

template<class T>
 void Array<T>::add(T & s)
{
	if (maxSize == last)
	{
		cout << "�Ѵﵽϵͳ����������޷������������" << endl;
		return;
	}
	else
	{
		data[last] = s;
		last++;
		cout << "��ӳɹ�" << endl;
	}
}

template<class T>
 void Array<T>::Search(int x)
{
	int flag = 0;
	for (int i = 0; i < last; i++)
		if (data[i].num == x)   //��ѧ�Ų���
		{
			cout << "��ѧ��������Ϣ��";
			show(data[i]);
			flag = 1;
			break;
		}
	if (flag == 0)
		cout << "û���ҵ���ѧ����Ϣ" << endl;
}

template<class T>
 void Array<T>::del(int x)
{
	int j = 0;
	for (int i = 0; i < last; i++)
	{
		if (data[i].num == x)
		{
			for (int k = i; k < last; k++)
			{
				data[k] = data[k + 1];
				last--;
			}
			j++;
		}
	}
	if (j == 0)
		cout << "û���ҵ���ѧ����Ϣ" << endl;
	else
		cout << "��Ϣɾ���ɹ�" << endl;
}

template<class T>
void Array<T>::write()
{
	file.open("data.txt");
	for (int i = 0; i < last; i++)
	{
		file << data[i].num << " " << data[i].name << " ";
		file << data[i].year << '-' << data[i].month << '-' << data[i].day << " ";
		file << data[i].sex << " " << data[i].health << endl;
	}
	file.close();
}

template<class T>
void Array<T>::read()
{
	file.open("data.txt");
	string str;
	cout << "ѧ��" << '\t' << "����" << '\t';
	cout << "��������" << '\t';
	cout << "�Ա�" << '\t' << "����״��" << endl;
	while (getline(file, str, '\n'))
		cout << str << endl;
	file.close();
}

template<class T>
void Array<T>::show(T & s)
{
	int j = 0;
	for (int i = 0; i < last; i++)
		if (data[i] == s)
		{
			print(data[i]);
			j++;
		}
	if (j == 0)
		cout << "û���ҵ���ѧ����Ϣ" << endl;
}

template<class T>
void Array<T>::showall()
{
	for (int i = 0; i < last; i++)
		print(data[i]);
}

template<class T>
void print(T & s)
{
	cout << "ѧ��" << '\t' << "����" << '\t';
	cout << "��������" << '\t';
	cout << "�Ա�" << '\t' << "����״��" << endl;
	cout << s.num << '\t' << s.name << '\t';
	cout << s.year << '-' << s.month << '-' << s.day << '\t';
	cout << s.sex << '\t' << s.health << endl;
}

#endif



