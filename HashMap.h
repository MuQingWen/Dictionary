#include <iostream>
#include "LinkList.h"
using namespace std;
class Hash_Table
{
public:
	Hash_Table()
	{

	}

	~Hash_Table()
	{
		
	}

	void Hash_Insert(string en, string ch)
	{
		int hash_place;
		int list_place;

		if (H(en) < 0)
		{
			cout << "��������Ƿ�������������" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].Compare(en);

			if (list_place != -1)
			{
				List[hash_place].Insert(list_place, en, ch);
			}
		}

	}

	void Hash_Delete(string en)
	{
		int hash_place;
		int list_place;

		if (H(en) < 0)
		{
			cout << "��������Ƿ�������������" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].Compare(en);

			if (list_place != -1)
			{
				cout << "ɾ��λ�÷Ƿ�" << endl;
			}
			else if (list_place == -1)
			{
				List[hash_place].List_Delete(list_place);
			}
		}
	}

	void Hash_Modify(string en, string ch)
	{
		int hash_place;
		int list_place;

		if (H(en) < 0)
		{
			cout << "��������Ƿ�������������" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].List_Compare(en);

			if (list_place == -2)
			{
				cout << "�޸�λ�÷Ƿ�";
			}
			else if (list_place == -1)
			{
				List[hash_place].List_Modify(list_place,en,ch);
			}
		}
	}

	void Hash_Get(string en)
	{
		int hash_place;
		int list_place;

		if (H(en) < 0)
		{
			cout << "��������Ƿ�������������" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].List_Compare(en);

			if (list_place == -1)
			{
				List[hash_place].List_Get(list_place);
			}
			else
			{
				cout << "δ�ҵ�������" << endl;
			}
		}
	}

private:
	LinkList List[26];

	int H(string head)
	{
		int ch = (int)head.at(0);
		ch -= 97;
		ch = ch % 27;
		if (ch < 0)
		{
			return -1;
		}
		else
		{
			return ch;
		}
	}

};