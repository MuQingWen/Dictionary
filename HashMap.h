#include <iostream>
using namespace std;
/*
��ϣ��洢�ṹ��
ԭ���������Ӣ�ĵ��ʵ�����ĸ�����жϣ����������������ͻ
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
			cout << "����λ�ô���" << endl;
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
			cout << "ɾ��λ�ô���" << endl;
		}
		else
		{
			q = p->next;
			x = q->En_Word;
			p->next = q->next;
			delete q;
			cout << "����" << x << "��ɾ��" << endl;
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
			cout << "�޸�λ�ô���" << endl;
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
			cout << "����λ�ô���" << endl;
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
			cout << "��������Ƿ�������������" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].List_Compare(en);

			if (list_place == -1)
			{
				cout << "�õ����Ѿ�����" << endl;
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
			cout << "��������Ƿ�������������" << endl;
		}
		else
		{
			hash_place = H(en);
			list_place = List[hash_place].List_Compare(en);

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