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
	int Compare(string en)//�ҵ���ͬӢ��ʱ���ظ�����λ�ã��Ƚϴ�ʱ���رȽϴ�1��λ�ã�δ�ҵ���Ƚ�С����0
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
	int Insert(int i, string en, string ch)//����1��ʾ����ɹ� 0��ʾ����ʧ��
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

	int Delete(string en)//����1��ʾɾ���ɹ� 0��ʾɾ��ʧ��
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

	int Modify(string en, string ch)//����1��ʾ�޸ĳɹ� 0��ʾ�޸�ʧ��
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

	Node Get(string en)//����1��ʾ���ҳɹ� 0��ʾ����ʧ��
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