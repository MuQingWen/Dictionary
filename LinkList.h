#include <iostream>
using namespace std;

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
	void ergodic()
	{
		Node* p = first->next;
		while (p!=nullptr)
		{
			cout << p->En_Word << ' ' << p->Ch_word << endl;
			p = p->next;
		}
	}
	void sort()
	{
		Node* p;
		Node* q;
		string cache;
		for (p = first->next; p != nullptr; p = p->next)
		{
			for (q = p->next; q != nullptr; q = q->next)
			{
				if (p->En_Word > q->En_Word)
				{
					cache = q->En_Word;
					q->En_Word = p->En_Word;
					p->En_Word = cache;
					cache = q->Ch_word;
					q->Ch_word = p->Ch_word;
					p->Ch_word = cache;
				}
			}
		}
	}
	int Compare(string en)//找到相同英文时返回负数的位置，比较大时返回比较大1的位置，未找到或比较小返回0
	{
		int count = 1;
		Node* p = first->next;
		while (p != nullptr)
		{
			if (en == p->En_Word)
			{
				return -count;
			}
			else if (en != p->En_Word)
			{
				if (this->Compare_all(en) == 1)
				{
					return -count;
				}
				return count+1;
			}
		}
		if (p == nullptr)
		{
			return 0;
		}
	}
	int Compare_all(string en)
	{
		int count = 1;
		Node* p = first->next;
		while (p != nullptr)
		{
			if (en == p->En_Word)
			{
				return 1;
			}
			else
			{
				p = p->next;
			}
		}
		return 0;
	}
	int Insert(int i, string en, string ch)//返回1表示插入成功 0表示插入失败
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
			return 0;
		}
		else
		{
			s = new Node;
			s->En_Word = en;
			s->Ch_word = ch;
			s->next = p->next;
			p->next = s;
			return 1;
		}
	}

	int Delete(string en)//返回1表示删除成功 0表示删除失败
	{
		Node* p = first;
		Node* q = nullptr;

		while (p != nullptr)
		{
			if (p->next == nullptr)
			{
				return 0;
			}
			if (p->next->En_Word == en)
			{
				q = p->next;
				p->next = q->next;
				delete q;
				return 1;
			}
			p = p->next;
		}
		return 0;
	}

	int Modify(string en, string ch)//返回1表示修改成功 0表示修改失败
	{
		Node* p = first;
		Node* q = nullptr;

		while (p != nullptr)
		{
			if (p->next == nullptr)
			{
				return 0;
			}
			if (p->next->En_Word == en)
			{
				p->next->Ch_word = ch;
				return 1;
			}
			p = p->next;
		}
		return 0;
	}

	Node Get(string en)//返回1表示查找成功 0表示查找失败
	{
		Node cache;
		Node* p = first;
		Node* q = nullptr;

		while (p != nullptr)
		{
			if (p->next == nullptr)
			{
				return cache;
			}
			if (p->next->En_Word == en)
			{
				cache = *(p->next);
				return cache;
			}
			p = p->next;
		}
		return cache;
	}



private:
	Node* first;
};