#include <iostream>
#include <string>
#define Max 1000
using namespace std;
//��ϵ�˽ṹ��
struct Person {
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
//ͨѶ¼�ṹ�� 
struct Addressbooks
{
	struct Person personArray[Max];
	int m_size;
};
//�����ϵ��
void addPerson(Addressbooks* abs) {
	if (abs->m_size==Max) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		while(true){
			//����1 or 2 ͨ��
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "����Υ��,����������" << endl;
		}
		//����
		while (true)
		{
			int age = 0;
			cout << "�����������С" << endl;
			cin >> age;
			if (age > 0 && age < 121) {
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
			cout << "���䷶ΧΪ1��120��" << endl;
			cout << "���䲻���Ϸ�Χ,����������" << endl;
		}
		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;
		//��ͥסַ
		string addr;
		cout << "�������ͥסַ" << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_addr = addr;
		//ͨѶ¼��������
		abs->m_size++;
		cout << "�����ϵ�˳ɹ�" << endl;
		system("pause");//�����������
		system("cls");//����
	}
}
//��ʾ��ϵ��
void ShowPerson(Addressbooks * abs) {
	if (abs->m_size == 0) {
		cout << "��ǰͨѶ¼����Ϊ0" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size;i++) {
			cout << "������ " << abs->personArray[i].m_name <<"\t";
			cout << "�Ա� " << (abs->personArray[i].m_sex == 1?"��":"Ů")<< "\t";
			cout << "���䣺 " << abs->personArray[i].m_age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_phone << "\t";
			cout << "סַ�� " << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void DeletePerson(Addressbooks * abs) {
	string name;
	cout << "��������Ҫɾ������ϵ������" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "δ�鵽����" << endl;
	}
	else {
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout<<"ɾ���ɹ�"<<endl;
	}
	system("pause");
	system("cls");
}
//����ָ����ϵ����Ϣ
void FindPerson(Addressbooks* abs) {
	string name;
	cout << "��������Ҫ���ҵ���ϵ����Ϣ" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������ " << abs->personArray[ret].m_name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_phone << "\t";
		cout << "סַ�� " << abs->personArray[ret].m_addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs) {
	string name;
	cout << "������Ҫ�޸ĵ���ϵ����Ϣ" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		while (true) {
			//����1 or 2 ͨ��
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "����Υ��,����������" << endl;
		}
		while (true) {
				int age = 0;
				cout << "�����������С" << endl;
				cin >> age;
				if (age > 0 && age < 121) {
					abs->personArray[ret].m_age = age;
					break;
				}
				cout << "���䷶ΧΪ1��120��" << endl;
				cout << "���䲻���Ϸ�Χ,����������" << endl;
		}
			string phone;
			cout << "��������ϵ�绰��" << endl;
			cin >> phone;
			abs->personArray[ret].m_phone = phone;
			string addr;
			cout << "�������ͥסַ" << endl;
			cin >> addr;
			abs->personArray[ret].m_addr = addr;
			cout << "�޸���ϵ�˳ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");//�����������
	system("cls");//����
}
//�����ϵ��
void clearPerson(Addressbooks* abs) {
	abs->m_size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");
}
//�˵�����
void ShowMenu()
{
	cout << "***********************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
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
		case 1://1.�����ϵ��
			addPerson(&abs);
			break;
		case 2://2.��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��
		/*{
			string aname;
			cout << "����������ɾ������ϵ������" << endl;
			cin >> aname;
			if (isExist(&abs, aname) == -1) {
				cout << "û���ҵ�����ϵ��" << endl;
			}
			else {
				cout << "�ҵ�����" << endl;
			}
		}*/
			DeletePerson(&abs);
			break;
		case 4://4.������ϵ��
			FindPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6.�����ϵ��
			clearPerson(&abs);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´��ٴ�ʹ��" << endl;
			system("pasuse");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}
