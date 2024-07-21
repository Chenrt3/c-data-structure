#include"phone.h"

istream& operator >>(istream& in, Phonekind &P) {//重载>>使可以输入枚举类型
	int n;
	in >> n;
	P = Phonekind(n);
	return in;
}

void showMenu()
{
	cout << "通讯录功能如下:\n" << endl;
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void Phone::Select(Phone P) {//选择菜单
	string number;
	while (true) {
		cout << "输入序号:" << endl;
		cin >> P.kind;
		switch (P.kind) {
		case(Add): AddPerson(&P); break;
		case(Display):DisplayPerson(&P,number); break;
		case(Delete): 
			cout << "输入号码:" << endl;
			cin >> P.number;
			number = P.number;
			DeletePerson(&P,number); break;
		case(Find): 
			cout << "输入号码:" << endl;
			cin >> P.number;
			number = P.number;
			FindPerson(&P, number); break;
		case(Change): ChangePerson(&P,number); break;
		case(Empty): EmptyPerson(&P); break;
		case(Quit): QuitPerson(); break;
		default: break;
		}
	}
}

Phone::Phone() {//构造函数初始化私有变量
	this->age = -1;
	this->name = new char;
	this->number = new char[11];
	this->sex = -1;
	this->address = new char;
	this->size = 0;
}

Phone Phone::Init(Phone *P) {//链表初始化
	Phone *head = new Phone;
	head->next= NULL;
	P = head;
	P->size = 0;
	return (*P);
}

Phone* Phone::AddPerson(Phone *P) {//添加联系人
	Phone *head =P;
	Phone *newnode = new Phone;
	newnode->next = NULL;
	cout << "请输入联系人的姓名:" << endl;
	cin >> newnode->name;
	cout << "请输入联系人的年龄:" << endl;
	cin >> newnode->age;
	cout << "请输入联系人的性别:" << endl;
	cin >> newnode->sex;
	cout << "请输入联系人的地址:" << endl;
	cin >> newnode->address;
	cout << "请输入联系人的电话号码:" << endl;
	cin >> newnode->number;
		while (head->next != NULL) {
			head = head->next;
			if (Phone::FindPerson(head, newnode->number)!=NULL) {
				cout << "出现一样的号码" << endl;
				return head;
			}
		}
		head->next = newnode;//尾插法插入数据，头节点为空指向首节点
		head = newnode;
	return P;
}

int Phone::DisplayPerson(Phone *P, string number) {
	Phone *head = P;
	if (head->next== NULL) {
		cout << "通讯录为空" << endl;
		return ERROR;
	}
	while (head->next!=NULL) {
		head = head->next;
		cout << "姓名:" << head->name << "年龄:" << head->age << "性别:" << head->sex << "地址:" << head->address << "电话号码:" << head->number << endl;
	}
	return OK;
}

Phone* Phone::DeletePerson(Phone *P, string number) {
	Phone *head = P;
	if (head->next == NULL)
		cout << "通讯录为空" << endl;
	else {
		while (head->next!= NULL) {
			if (head->next->number == number) {
				Phone*temp = head->next;
				head->next = temp->next;
				cout << "已删除联系人" << endl;
				delete temp;
				break;
			}
			head = head->next;
		}
	}
	if (head == NULL)
		cout << "无此联系人" << endl;
	return P;
}



Phone* Phone::FindPerson(Phone *P, string number) {
	Phone *head = P;
	Phone *temp = P; 
		while (temp->next != NULL) {
			temp = temp->next;
			if (temp->number == number) {
				cout << "姓名:" << head->name << "年龄:" << head->age << "性别:" << head->sex << "地址:" << head->address << "电话号码:" << head->number << endl;
			}
			break;
		}
	if (temp->next == NULL) {
	cout << "无此联系人" << endl;
	return NULL;
	}
	return P;
}

Phone* Phone::ChangePerson(Phone *P,string number) {
	Phone *head = P;
	Phone *temp = P;
	if (head->next == NULL)
		cout << "通讯录为空" << endl;
	while (temp->next != NULL) {
		temp = temp->next;
		if (temp->number == number) {
			cout << "姓名:" << head->name << "年龄:" << head->age << "性别:" << head->sex << "地址:" << head->address << "电话号码:" << head->number << endl;
		}
		break;
	}
	cout << "输入要修改的数据:" << endl;
	cout << "请输入联系人的姓名:" << endl;
	cin >> temp->name;
	cout << "请输入联系人的年龄:" << endl;
	cin >> temp->age;
	cout << "请输入联系人的性别:" << endl;
	cin >> temp->sex;
	cout << "请输入联系人的地址:" << endl;
	cin >> temp->address;
	cout << "请输入联系人的电话号码:" << endl;
	cin >> temp->number;
	cout << "修改成功" << endl;
	return P;
}


Phone* Phone::EmptyPerson(Phone *P) {
	Phone *head = P;
	Phone *temp = NULL;
	while (head->next!= NULL) {
		temp = head->next;
		head->next = head->next->next;
		free(temp);
	}
	P = NULL;
	cout << "已清空联系人" << endl;
	return P;
}


void Phone::QuitPerson() {
	cout << "欢迎下次使用" << endl;
	showMenu();
}