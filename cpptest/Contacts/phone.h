#pragma once
#ifndef _phone_H
#define _phone_H
#include<iostream>
#include<string>
#define ERROR -1;
#define OK 1;
#define MAX 100;
typedef enum { Quit, Add, Display, Delete, Find, Change, Empty } Phonekind;//退出，增加，显示，删除，查找，改变，清空
typedef int Status;
using namespace std;

class Phone {
public:
	int size;
	Phone *next;
	Phonekind kind;//枚举变量
	friend istream& operator >>(istream& in, Phonekind &P);//重载>>使可以输入枚举类型
	Phone();//构造函数初始化私有变量
	Phone Init(Phone *P);
	Phone* AddPerson(Phone *P);
	int DisplayPerson(Phone *P, string number);
	Phone* DeletePerson(Phone *P, string number);
	Phone* FindPerson(Phone *P, string number);
	Phone* ChangePerson(Phone *P,string number);
	Phone* EmptyPerson(Phone *P);
	void QuitPerson();
	void Select(Phone P);
private:
	string name;
	int sex;
	int age;
	string number;
	string address;
};

void showMenu();
#endif