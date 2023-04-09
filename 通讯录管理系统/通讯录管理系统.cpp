#include <iostream>
#include <string>
#define Max 1000
using namespace std;
//联系人结构体
struct Person {
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
//通讯录结构体 
struct Addressbooks
{
	struct Person personArray[Max];
	int m_size;
};
//添加联系人
void addPerson(Addressbooks* abs) {
	if (abs->m_size==Max) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		//性别
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while(true){
			//输入1 or 2 通过
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入违规,请重新输入" << endl;
		}
		//年龄
		while (true)
		{
			int age = 0;
			cout << "请输入年龄大小" << endl;
			cin >> age;
			if (age > 0 && age < 121) {
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
			cout << "年龄范围为1到120岁" << endl;
			cout << "年龄不符合范围,请重新输入" << endl;
		}
		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;
		//家庭住址
		string addr;
		cout << "请输入家庭住址" << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_addr = addr;
		//通讯录人数更新
		abs->m_size++;
		cout << "添加联系人成功" << endl;
		system("pause");//按任意键继续
		system("cls");//清屏
	}
}
//显示联系人
void ShowPerson(Addressbooks * abs) {
	if (abs->m_size == 0) {
		cout << "当前通讯录人数为0" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size;i++) {
			cout << "姓名： " << abs->personArray[i].m_name <<"\t";
			cout << "性别： " << (abs->personArray[i].m_sex == 1?"男":"女")<< "\t";
			cout << "年龄： " << abs->personArray[i].m_age << "\t";
			cout << "电话： " << abs->personArray[i].m_phone << "\t";
			cout << "住址： " << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}
//删除联系人
void DeletePerson(Addressbooks * abs) {
	string name;
	cout << "请输入你要删除的联系人姓名" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "未查到此人" << endl;
	}
	else {
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout<<"删除成功"<<endl;
	}
	system("pause");
	system("cls");
}
//查找指定联系人信息
void FindPerson(Addressbooks* abs) {
	string name;
	cout << "请输入你要查找的联系人信息" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名： " << abs->personArray[ret].m_name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_age << "\t";
		cout << "电话： " << abs->personArray[ret].m_phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改指定联系人信息
void modifyPerson(Addressbooks* abs) {
	string name;
	cout << "输入你要修改的联系人信息" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true) {
			//输入1 or 2 通过
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入违规,请重新输入" << endl;
		}
		while (true) {
				int age = 0;
				cout << "请输入年龄大小" << endl;
				cin >> age;
				if (age > 0 && age < 121) {
					abs->personArray[ret].m_age = age;
					break;
				}
				cout << "年龄范围为1到120岁" << endl;
				cout << "年龄不符合范围,请重新输入" << endl;
		}
			string phone;
			cout << "请输入联系电话：" << endl;
			cin >> phone;
			abs->personArray[ret].m_phone = phone;
			string addr;
			cout << "请输入家庭住址" << endl;
			cin >> addr;
			abs->personArray[ret].m_addr = addr;
			cout << "修改联系人成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}
//清空联系人
void clearPerson(Addressbooks* abs) {
	abs->m_size = 0;
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");
}
//菜单界面
void ShowMenu()
{
	cout << "***********************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "***********************" << endl;
}
int main()
{
	Addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while(true){
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addPerson(&abs);
			break;
		case 2://2.显示联系人
			ShowPerson(&abs);
			break;
		case 3://3.删除联系人
		/*{
			string aname;
			cout << "请输入你想删除的联系人姓名" << endl;
			cin >> aname;
			if (isExist(&abs, aname) == -1) {
				cout << "没有找到该联系人" << endl;
			}
			else {
				cout << "找到此人" << endl;
			}
		}*/
			DeletePerson(&abs);
			break;
		case 4://4.查找联系人
			FindPerson(&abs);
			break;
		case 5://5.修改联系人
			modifyPerson(&abs);
			break;
		case 6://6.清空联系人
			clearPerson(&abs);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次再次使用" << endl;
			system("pasuse");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}
