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
			cout << "输入添加的单词和中文:" << endl << "英文:";
			cin >> en;
			cout << endl << "中文:";
			cin >> ch;
			com = list.Compare(en);
			if (com == 0)
			{
				flag = list.Insert(1, en, ch);
				if (flag == 1)
				{
					cout << endl << "插入成功" << endl;
				}
				else
				{
					cout << endl << "插入失败" << endl;
				}
			}
			else if (com > 0)
			{
				flag = list.Insert(com, en, ch);
				if (flag == 1)
				{
					cout << endl << "插入成功" << endl;
				}
				else
				{
					cout << endl << "插入失败" << endl;
				}
			}
			else
			{
				cout << endl << "已存在该单词" << endl;
			}
			list.sort();
			system("pause");
			break;
		case 2:
			cout << "请输入要删除的单词";
			cin >> en;
			flag = list.Delete(en);
			if (flag == 1)
			{
				cout << endl << "删除成功" << endl;
			}
			else
			{
				cout << endl << "删除失败" << endl;
			}
			system("pause");
			break;
			
		case 3:
			cout << "请输入要改的单词";
			cin >> en;
			cout << endl << "请输入要改的中文";
			cin >> ch;
			flag = list.Modify(en, ch);
				if (flag == 1)
				{
					cout << endl << "修改成功" << endl;
				}
				else
				{
					cout << endl << "修改失败" << endl;
				}
			system("pause");
			break;
			
			case 4:
			cout << "请输入要查的单词";
			cin >> en;
			cache = list.Get(en);
			if (cache.En_Word.empty())
			{
				cout << endl << "查询失败" << endl;
			}
			else
			{
				cout << endl << "单词：" << cache.En_Word << "   " << "中文:" << cache.Ch_word << endl;
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