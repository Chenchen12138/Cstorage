// C++第三次上机.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
const int N = 50;
using namespace std;
class employee
{
protected:
	string name;
	long int number;
	char level;
	double salary;
public:
	employee()
	{
		name = "no name";
		number = 0;
		level = 'C';
		salary = 0;
	}
	employee(string nam, long int num, char le,double sa)
	{
		name = nam;
		number = num;
		level = le;
		salary = sa;
	}

	employee(employee &a)
	{
		name = a.name;
		number = a.number;
		level = a.level;
		salary = a.salary;
	}
	void display()
	{
		cout << "Name:" << name << endl 
			<< "Number:" << number<< endl 
			<< "Level:" << level << endl << 
			"Salary:" << salary << endl << endl;
	}
	virtual void pay(int day)
	{
		if (level == 'A') salary = 3000;
		if (level == 'B') salary = 2500;
		if (level == 'C') salary = 2000;
		salary += (31 - day)*N;
	}
};
class manager :virtual public employee
{
protected:
	double BasicBonus;
	double coefficient;
public:
	manager()
	{
		BasicBonus = 0;
		coefficient = 0;
	}
	manager(string name, long int number, char level, double salary, double b=0, double c=0)
		:employee(name, number, level, salary)
	{
		BasicBonus = b;
		coefficient = c;
	}
	virtual void pay(int a = 0)
	{
		if (level == 'A') salary = 3000;
		if (level == 'B') salary = 2500;
		if (level == 'C') salary = 2000;
		salary += BasicBonus * coefficient;
	}
};
class technician :virtual public employee
{
protected:
	double extramoney;
	double hours;
	double done_percent;
public:
	technician(string name, long number, char level, double salary, double e=0 ,double h=0,double p=0)
		:employee(name, number, level, salary)
	{
		extramoney = e;
		hours = h;
		done_percent = p;
	}
	virtual void pay(int a = 0)
	{
		if (level == 'A') salary = 3000;
		if (level == 'B') salary = 2500;
		if (level == 'C') salary = 2000;
		salary += extramoney * hours * done_percent;
	}
};
class salesman :virtual public employee
{
protected:
	double salenumber;
	double sale_percent;
public:
	salesman(string name, long number, char level, double salary, double sn=0, double sp=0)
		:employee(name, number, level, salary)
	{
		salenumber = sn;
		sale_percent = sp;
	}
	virtual void pay()
	{
		if (level == 'A') salary = 3000;
		if (level == 'B') salary = 2500;
		if (level == 'C') salary = 2000;
		salary += salenumber * sale_percent;
	}
};
class develop_manager :virtual public technician, virtual public manager
{
public:
	develop_manager(string name, long number, char level, double salary, double e = 0, double h = 0, double p = 0, double b = 0, double c = 0)
		:employee(name, number, level, salary),technician(name, number, level, salary,e,h,p),manager(name, number, level, salary,b,c){}
	virtual void pay(int a = 0) 
{
		if (level == 'A') salary = 3000;
		if (level == 'B') salary = 2500;
		if (level == 'C') salary = 2000;
		salary += (extramoney * hours * done_percent) / 2 + (BasicBonus * coefficient) / 2;
}
};
class sales_manager :virtual public manager, virtual public salesman
{
public:
	sales_manager(string name, long number, char level, double salary, double b = 0, double c = 0, double sn = 0, double sp = 0)
		:employee(name, number, level, salary),manager(name, number, level, salary,b,c),salesman(name, number, level, salary,sn,sp){}
	virtual void pay(int a = 0)
	{
		if (level == 'A') salary = 3000;
		if (level == 'B') salary = 2500;
		if (level == 'C') salary = 2000;
		salary += salenumber * sale_percent + BasicBonus / 2;
	}
};
int main()
{
	employee *pt;
	technician te("Tom", 1, 'B',0 , 5, 10, 0.3);
	pt = &te;
	pt->pay(0);
	salesman sa("Nick", 2, 'A',0 , 100, 0.6);
	pt = &sa;
	pt->pay(5);
	develop_manager de("Honey", 3, 'B',0 , 100, 0.3, 5, 100, 0.7);
	pt = &de;
	pt->pay(0);
	sales_manager sal("CK", 4, 'A',0 , 100, 0.2, 100, 0.5);
	pt = &sal;
	pt->pay(0);
	te.display();
	cout << "\n";
	sa.display();
	cout << "\n";
	de.display();
	cout << "\n";
	sal.display();
	cin.get();
	return 0;
}
