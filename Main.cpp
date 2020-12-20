#include <iostream>
#include "LinkList.h"
using namespace std;

int main()
{
	LinkList list;
	int op;
	int com;
	int flag;
	string en, ch;
	Node cache;

	while (1)
	{
		system("cls");
		cout << "1z2s3g4c5b" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "������ӵĵ��ʺ�����:" << endl << "Ӣ��:";
			cin >> en;
			cout << endl << "����:";
			cin >> ch;
			com = list.Compare(en);
			if (com == 0)
			{
				flag = list.Insert(1, en, ch);
				if (flag == 1)
				{
					cout << endl << "����ɹ�" << endl;
				}
				else
				{
					cout << endl << "����ʧ��" << endl;
				}
			}
			else if (com > 0)
			{
				flag = list.Insert(com, en, ch);
				if (flag == 1)
				{
					cout << endl << "����ɹ�" << endl;
				}
				else
				{
					cout << endl << "����ʧ��" << endl;
				}
			}
			else
			{
				cout << endl << "�Ѵ��ڸõ���" << endl;
			}
			list.sort();
			system("pause");
			break;
		case 2:
			cout << "������Ҫɾ���ĵ���";
			cin >> en;
			flag = list.Delete(en);
			if (flag == 1)
			{
				cout << endl << "ɾ���ɹ�" << endl;
			}
			else
			{
				cout << endl << "ɾ��ʧ��" << endl;
			}
			system("pause");
			break;
			
		case 3:
			cout << "������Ҫ�ĵĵ���";
			cin >> en;
			cout << endl << "������Ҫ�ĵ�����";
			cin >> ch;
			flag = list.Modify(en, ch);
				if (flag == 1)
				{
					cout << endl << "�޸ĳɹ�" << endl;
				}
				else
				{
					cout << endl << "�޸�ʧ��" << endl;
				}
			system("pause");
			break;
			
			case 4:
			cout << "������Ҫ��ĵ���";
			cin >> en;
			cache = list.Get(en);
			if (cache.En_Word.empty())
			{
				cout << endl << "��ѯʧ��" << endl;
			}
			else
			{
				cout << endl << "���ʣ�" << cache.En_Word << "   " << "����:" << cache.Ch_word << endl;
			}
			system("pause");
			break;
		
		case 5:
			list.ergodic();
			system("pause");
		default:
			break;
		}
		
	}
	return 0;
}