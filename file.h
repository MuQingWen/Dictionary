#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HashMap.h"
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
class File
{
public:
	int File_Read()
	{
		string str;
		string en, ch;
		char word[100];
		char* cache[100];
		ifstream file("dictionary.txt");
		if (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, str);
				strcpy_s(word, str.c_str());
				en = strtok_s(word, "   ", cache);
				ch = strtok_s(NULL, "   ", cache);
				table.Hash_Insert(en, ch);
			}
			file.close();
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
	void file_Get()
	{
		string en;
		cout << "请输入你要查询的单词:";
		cin >> en;
		table.Hash_Get(en);
	}
private:
	Hash_Table table;
};
