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
			cout << "文字输入非法，请重新输入" << endl;
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
			cout << "文字输入非法，请重新输入" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].Compare(en);

			if (list_place != -1)
			{
				cout << "删除位置非法" << endl;
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
			cout << "文字输入非法，请重新输入" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].List_Compare(en);

			if (list_place == -2)
			{
				cout << "修改位置非法";
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
			cout << "文字输入非法，请重新输入" << endl;
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
				cout << "未找到该数据" << endl;
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