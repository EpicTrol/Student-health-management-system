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
		cout << "��ӭʹ��ѧ�������������ϵͳ" << endl;
		cout << "������������ִ�����Ӧ�Ĳ���" << endl;
		cout << "1���½�һ��ѧ��������" << endl;
		cout << "2����ѧ�������������ѧ����Ϣ" << endl;
		cout << "3���ڽ�����ɾ��ѧ����Ϣ" << endl;
		cout << "4�����ļ��ж�ȡ��������Ϣ" << endl;
		cout << "5�����ļ�д��ѧ����������Ϣ" << endl;
		cout << "6���ڽ������в�ѯѧ����Ϣ����ѧ��ѧ�������в��ң�" << endl;
		cout << "7������Ļ�����ȫ��ѧ����Ϣ" << endl;
		cout << "8���˳�" << endl;
		cout << "-----------------------------------------------------------"<<endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "������Ҫ���ѧ��������" << endl;
			cin >> p;
			m.create(p);
			cout << "�����ɹ�" << endl;
			break;
		case 2:
			cout << "������ѧ��ѧ��" << endl;
			cin >> num;
			cout << "������ѧ������" << endl;
			cin >> name;
			cout << "������ѧ���ĳ�������" << endl;
			cin >> year >> month >> day;
			cout << "������ѧ���Ա�" << endl;
			cin >> sex;
			cout << "������ѧ���Ľ������" << endl;
			cin >> health;
			s = student(num, name, year, month, day, sex, health);
			m.add(s);
			break;
		case 3:
			cout << "������Ҫɾ����ѧ��ѧ��" << endl;
			cin >> num;
			m.del(num);
			break;
		case 4:
		    cout<<"ѧ����ϢΪ��"<<endl;
			m.read();
			break;
		case 5:
			m.write();
			break;
		case 6:
			cout << "������Ҫ���ҵ�ѧ��ѧ��" << endl;
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
			cout << "��������ִ���������������ȷ������" << endl;
			break;
		}
	} while (choice != 8);

	return 0;
}
