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
	void create(int m);  //新建学生健康表
	void add(T &s);     //向学生健康表插入学生信息
	void Search(int x); //在健康表中查询学生信息并输出
	void del(int x);    //删除单个学生健康信息
	//void delall();      //删除真个表
	void write();       //从文件中写入健康表信息
	void read();        //向文件读取学生健康表信息
	void show(T &s);    //显示单个的学生信息
	void showall();     //在屏幕中输出全部学生信息
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
		cout << "已达到系统最大容量，无法继续添加数据" << endl;
		return;
	}
	else
	{
		data[last] = s;
		last++;
		cout << "添加成功" << endl;
	}
}

template<class T>
 void Array<T>::Search(int x)
{
	int flag = 0;
	for (int i = 0; i < last; i++)
		if (data[i].num == x)   //按学号查找
		{
			cout << "该学生健康信息：";
			show(data[i]);
			flag = 1;
			break;
		}
	if (flag == 0)
		cout << "没有找到该学生信息" << endl;
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
		cout << "没有找到该学生信息" << endl;
	else
		cout << "信息删除成功" << endl;
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
	cout << "学号" << '\t' << "姓名" << '\t';
	cout << "出生日期" << '\t';
	cout << "性别" << '\t' << "健康状况" << endl;
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
		cout << "没有找到该学生信息" << endl;
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
	cout << "学号" << '\t' << "姓名" << '\t';
	cout << "出生日期" << '\t';
	cout << "性别" << '\t' << "健康状况" << endl;
	cout << s.num << '\t' << s.name << '\t';
	cout << s.year << '-' << s.month << '-' << s.day << '\t';
	cout << s.sex << '\t' << s.health << endl;
}

#endif



