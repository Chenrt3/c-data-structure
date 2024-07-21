#include"manage.h"

istream &operator >>(istream &in, managekind &m) {
	int n;
	in >> n;
	m = managekind(n);
	return in;
}

/*istream &operator>>(istream &in, BOSS &B) {
	in >> B.NUM;
}*/

BOSS::BOSS(int m_id, string m_name, int deptnum) {
	this->m_id = m_id;
	this->m_name = m_name;
	this->deptnum = deptnum;
	//vector<BOSS>NUM(MAXSIZE);
}

void Menu() {
		cout << "********************************************" << endl;
		cout << "*********  欢迎使用职工管理系统！ **********" << endl;
		cout << "*************  0.退出管理程序  *************" << endl;
		cout << "*************  1.增加职工信息  *************" << endl;
		cout << "*************  2.显示职工信息  *************" << endl;
		cout << "*************  3.删除离职职工  *************" << endl;
		cout << "*************  4.修改职工信息  *************" << endl;
		cout << "*************  5.查找职工信息  *************" << endl;
		cout << "*************  6.按照编号排序  *************" << endl;
		cout << "*************  7.清空所有文档  *************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
}


template<class T>//模板化处理传进来的不同等级的职工类
void BOSS::Select(T B,vector<BOSS>&vec)
{
	while (true) {
		cout << "选择序号:" << endl;
		cin >> B.kind;
		switch (B.kind) {
		case Add:B.AddPerson(vec); break;
		case DisPlay:B.PrintPerson(vec); break;
		case Delete:B.DeletePerson(vec); break;
		case Change:B.ChangePerson(vec); break;
		case Find:B.FindPerson(vec); break;
		case Sort:B.SortPerson(vec); break;
		case Empty:B.EmptyPerson(vec); break;
		case Quit:return; break;
		default:break;
		}
	}
}

void BOSS::AddPerson(vector<BOSS>&vec) {
	BOSS B;//无参构造函数没写，只写了有参构造函数，系统也不给你无参构造函数了,所以B不存在默认构造函数
	cout << "输入添加几个员工:" << endl;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "输入员工编号" << endl;
		cin >> B.m_id;
		cout << "输入员工姓名" << endl;
		cin >> B.m_name;
		cout << "输入部门编号" << endl;
		cin >> B.deptnum;
		vec.push_back(B);		
	}	
}

void BOSS::PrintPerson(vector<BOSS>&vec) {
	if (vec.empty())
		cout << "系统为空" << endl;
	vector<BOSS>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it) {
		cout << "输出员工编号:" << (*it).m_id << endl;
		cout << "输出员工姓名" <<(*it).m_name<< endl;
		cout << "输入部门编号" << (*it).deptnum << endl;
	}
}

void BOSS::DeletePerson(vector<BOSS>&vec) {
	if (vec.empty())
		cout << "系统为空" << endl;
	int temp = 0;
	cout << "输入想要删除的员工编号" << endl;
	int id;
	cin >> id;
	cout << "输入想要删除的员工姓名" << endl;
	string name;
	cin >> name;
	vector<BOSS>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it) {//迭代器要加括号当不加括号是，也就是函数不传入参数（void也是参数哦）的话，编译器将会理解成函数指针
		if ((*it).m_id == id && (*it).m_name ==name) {
			vec.erase(it);
			cout << "删除职工" << name << "信息成功" << endl;
			temp = 1;
			break;
		}
	}
	if (!temp) {
		cout << "删除的数据不存在" << endl;
	}
}

void BOSS::ChangePerson(vector<BOSS>&vec) {
	if (vec.empty())
		cout << "系统为空" << endl;
	int temp = 0;
	cout << "输入想要修改的员工编号" << endl;
	int id;
	cin >> id;
	cout << "输入想要修改的员工姓名" << endl;
	string name;
	cin >> name;
	vector<BOSS>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it) {
		if ((*it).m_id == id && (*it).m_name == name) {
			cout << "输出员工编号:" << (*it).m_id << endl;
			cout << "输出员工姓名" << (*it).m_name << endl;
			cout << "输出部门编号" << (*it).deptnum << endl;
			temp = 1;
			cout << "输入新的员工编号:" << endl;
			cin >> (*it).m_id;
			cout << "输入新的员工姓名:" << endl;
			cin >> (*it).m_name;
			cout << "输入新的部门编号:" << endl;
			cin >> (*it).deptnum;
			break;
		}
	}
	if (!temp) {
		cout << "查找的数据不存在" << endl;
	}
}

void BOSS::FindPerson(vector<BOSS>&vec) {
	if (vec.empty())
		cout << "系统为空" << endl;
	int temp = 0;
	cout << "输入想要查找的员工编号" << endl;
	int id;
	cin >> id;
	cout << "输入想要查找的员工姓名" << endl;
	string name;
	cin >> name;
	vector<BOSS>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it) {
		if ((*it).m_id == id && (*it).m_name == name) {
			cout << "输出员工编号:" << (*it).m_id << endl;
			cout << "输出员工姓名" << (*it).m_name << endl;
			cout << "输出部门编号" << (*it).deptnum << endl;
			temp = 1;
			break;
		}
	}
	if (!temp) {
		cout << "查找的数据不存在" << endl;
	}
}

bool cmp(BOSS &a, BOSS &b) {
	return a.m_id > b.m_id;
}
void BOSS::SortPerson(vector<BOSS>&vec) {
	if (vec.empty())
		cout << "系统为空" << endl;
	sort(vec.begin(), vec.end(),cmp);
	PrintPerson(vec);
}

void BOSS::EmptyPerson(vector<BOSS>&vec) {
	vec.clear();
	if (vec.empty())
		cout << "清除为空" << endl;
}



void BOSS::SystemInit(vector<BOSS>&vec) {
	fstream infile;
	infile.open("E:\\学习资料\\c++\\qiyezhigongxitong\\Project1\\Project1\\manage.txt", ios::out);
	if (!infile) {
		cerr << "open error!" << endl;
		abort();
	}
	BOSS temp;
	while (true) {
		memset(&temp, 0, sizeof(temp));
		if (infile.read((char*)&temp, sizeof(BOSS))) {
			cout << "职工号" << temp.m_id << "职工姓名" << temp.m_name << "职工部门号" << temp.deptnum << endl;
			vec.push_back(temp);
		}
		else {
			infile.close();
			cout << "载入本地信息成功" << endl;
			break;
		}
	}
}

void BOSS::Outfile(vector<BOSS>&vec) {
	vector<BOSS>::iterator it;
	BOSS temp;
	fstream outfile;
	outfile.open("E:\\学习资料\\c++\\qiyezhigongxitong\\Project1\\Project1\\manage.txt", ios::out);
	if (!outfile) {
		cerr << "打开失败" << endl;//异常报错
		abort();
	}
	for (it = vec.begin(); it != vec.end(); it++) {
		temp.m_id = (*it).m_id;
		temp.m_name = (*it).m_name;
		temp.deptnum = (*it).deptnum;
		outfile.write((char*)&temp, sizeof (BOSS));
		cout << "输出员工编号:" << (*it).m_id << endl;
		cout << "输出员工姓名" << (*it).m_name << endl;
		cout << "输出部门编号" << (*it).deptnum << endl;
	}
	cout << "保存信息成功" << endl;
	outfile.close();
}

void Manager::AddPerson(vector<BOSS>&vec) {
	cout << "无权限访问" << endl;
}

void Manager::DeletePerson(vector<BOSS>&vec) {
	cout << "无权限访问" << endl;
}

void  Manager::ChangePerson(vector<BOSS>&vec){
	cout << "无权限访问" << endl;
}

void Manager::SortPerson(vector<BOSS>&vec) {
	cout << "无权限访问" << endl;
}

void Manager::EmptyPerson(vector<BOSS>&vec) {
	cout << "无权限访问" << endl;
}