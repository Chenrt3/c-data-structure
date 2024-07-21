#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<stdlib.h>
#include<cstring>
typedef int Status;
typedef enum { Quit, Add, DisPlay, Delete, Change, Find, Sort, Empty } managekind;
#define OK 1
#define ERROR -1
//#define MAXSIZE 100
using namespace std;

class Employee;
class Manager;
class BOSS {
public:
	managekind kind;
	BOSS() = default;//无参构造函数没写，只写了有参构造函数，系统也不给你无参构造函数了,所以B不存在默认构造函数
	BOSS(int m_id, string m_name, int deptnum);//构造函数初始化
	friend istream &operator >>(istream &in, managekind &m);
	template<class T>
	void Select(T B, vector<BOSS>&vec);
	virtual void AddPerson(vector<BOSS>&vec);
	virtual void PrintPerson(vector<BOSS>&vec);
	virtual void DeletePerson(vector<BOSS>&vec);
	virtual void ChangePerson(vector<BOSS>&vec);
	virtual void FindPerson(vector<BOSS>&vec);
	virtual void SortPerson(vector<BOSS>&vec);
	friend bool cmp(BOSS &a, BOSS &b);
	virtual void EmptyPerson(vector<BOSS>&vec);
	virtual void SystemInit(vector<BOSS>&vec);
	virtual void Outfile(vector<BOSS>&vec);
private:
	int m_id;
	string m_name;
	int deptnum;
	//vector<int>NUM;//在类内先定义，在构造函数里初始化
};

class Manager:public BOSS {
public:
	virtual void AddPerson(vector<BOSS>&vec);
	virtual void DeletePerson(vector<BOSS>&vec);
	virtual void ChangePerson(vector<BOSS>&vec);
	virtual void SortPerson(vector<BOSS>&vec);
	virtual void EmptyPerson(vector<BOSS>&vec);
};

class Employee:public Manager {
	
};

void  Menu();
