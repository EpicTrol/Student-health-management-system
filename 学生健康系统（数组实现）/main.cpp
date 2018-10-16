#include "student.h"


int main()
{
	student s;
	int choice, p, num, year, month, day;
	string name, sex, health, len;
	Array<student> m;

	do
	{
	    cout << "-----------------------------------------------------------"<<endl;
		cout << "欢迎使用学生健康情况管理系统" << endl;
		cout << "请输入数字来执行相对应的操作" << endl;
		cout << "1、新建一个学生健康表" << endl;
		cout << "2、往学生健康表中添加学生信息" << endl;
		cout << "3、在健康表删除学生信息" << endl;
		cout << "4、从文件中读取健康表信息" << endl;
		cout << "5、向文件写入学生健康表信息" << endl;
		cout << "6、在健康表中查询学生信息（按学生学号来进行查找）" << endl;
		cout << "7、在屏幕中输出全部学生信息" << endl;
		cout << "8、退出" << endl;
		cout << "-----------------------------------------------------------"<<endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "请输入要添加学生的数量" << endl;
			cin >> p;
			m.create(p);
			cout << "创建成功" << endl;
			break;
		case 2:
			cout << "请输入学生学号" << endl;
			cin >> num;
			cout << "请输入学生姓名" << endl;
			cin >> name;
			cout << "请输入学生的出生日期" << endl;
			cin >> year >> month >> day;
			cout << "请输入学生性别" << endl;
			cin >> sex;
			cout << "请输入学生的健康情况" << endl;
			cin >> health;
			s = student(num, name, year, month, day, sex, health);
			m.add(s);
			break;
		case 3:
			cout << "请输入要删除的学生学号" << endl;
			cin >> num;
			m.del(num);
			break;
		case 4:
		    cout<<"学生信息为："<<endl;
			m.read();
			break;
		case 5:
			m.write();
			break;
		case 6:
			cout << "请输入要查找的学生学号" << endl;
			cin >> num;
			m.Search(num);
			break;
		case 7:
			m.showall();
			break;
		case 8:
			exit(0);
			break;
		default:
			cout << "输入的数字错误，请重新输入正确的数字" << endl;
			break;
		}
	} while (choice != 8);

	return 0;
}
