#include <iostream>
using namespace std;
/*
哈希表存储结构：
原理：对输入的英文单词的首字母进行判断，采用拉链法解决冲突
*/

struct Node
{
	string En_Word;
	string Ch_word;
	Node* next;
};

class LinkList
{
public:
	LinkList()
	{
		first = new Node;
		first->next = nullptr;
	}

	~LinkList()
	{
		Node* p = first;
		while (first != nullptr)
		{
			first = first->next;
			delete p;
			p = first;
		}
	}

	void List_Insert(int i, string en, string ch)
	{
		int count = 0;
		Node* p = first;
		Node* s = nullptr;

		while (p != nullptr && count < i - 1)
		{
			p = p->next;
			count++;
		}

		if (p == nullptr)
		{
			cout << "插入位置错误" << endl;
		}
		else
		{
			s = new Node;
			s->En_Word = en;
			s->Ch_word = ch;
			s->next = p->next;
			p->next = s;
		}
	}

	void List_Delete(int i)
	{
		int count = 0;
		string x;
		Node* p = first;
		Node* q = nullptr;

		while (p != nullptr && count < i - 1)
		{
			p = p->next;
			count++;
		}

		if (p == nullptr || p->next == nullptr)
		{
			cout << "删除位置错误" << endl;
		}
		else
		{
			q = p->next;
			x = q->En_Word;
			p->next = q->next;
			delete q;
			cout << "数据" << x << "已删除" << endl;
		}
	}

	void List_Modify(int i, string en, string ch)
	{
		int count = 1;
		Node* p = first->next;

		while (p != nullptr && count < i)
		{
			p = p->next;
			count++;
		}

		if (p == nullptr)
		{
			cout << "修改位置错误" << endl;
		}
		else
		{
			p->Ch_word = ch;
			p->En_Word = en;
		}
	}

	void List_Get(int i)
	{
		int count = 1;
		Node* p = first->next;

		while (p != nullptr && count < i)
		{
			p = p->next;
			count++;
		}

		if (p == nullptr)
		{
			cout << "查找位置错误" << endl;
		}
		else
		{
			cout << p->En_Word << endl << p->Ch_word;
		}
	}

	int List_Compare(string en)
	{
		int count = 1;
		int flag = 0;
		Node* p = first->next;

		while (p != nullptr)
		{
			if (en.compare(p->En_Word) >= 0)
			{
				flag = 1;
				break;
			}
			p = p->next;
			count++;
		}

		if (flag == 1)
		{
			return -1;
		}
		else
		{
			return count;
		}
	}

private:
	Node* first;
};

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
			list_place = List[hash_place].List_Compare(en);

			if (list_place == -1)
			{
				cout << "该单词已经存在" << endl;
			}
			else
			{
				List[hash_place].List_Insert(list_place, en, ch);
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
			list_place = List[hash_place].List_Compare(en);

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
	int max_size = 26;
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