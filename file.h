#include <iostream>
#include "HashMap.h"
#include <fstream>
#include <string>
using namespace std;
class File
{
public:
	void File_Read()
	{
		string str;
		string en, ch;
		ifstream file("dictionary.txt");
		if (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, str);
				cout << str << endl;
			}
		}
		file.close();
	}
private:
	Hash_Table table;
};
