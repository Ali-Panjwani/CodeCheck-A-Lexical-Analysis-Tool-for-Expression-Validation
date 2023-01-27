#include<iostream>
#include<fstream>
#include"stack.h"
using namespace std;

char instructions[1000];
int total_Lenght;
int position=0;

void EndBracesChecker()
{
	stack st;
	for (int i = 0; i < total_Lenght; i++)
	{
		if (instructions[i] == '{' || instructions[i] == '[' || instructions[i] == '(')
		{
			st.push(instructions[i]);
		}
		else if (instructions[i] == ')' && st.GetHeadData() == '(')
		{
			st.pop();
		}
		else if (instructions[i] == '}' && st.GetHeadData() == '{')
		{
			st.pop();
		}
		else if (instructions[i] == ']' && st.GetHeadData() == '[')
		{
			st.pop();
		}
		else
		{
			continue;
		}
	}
	if (st.isempty())
	{
		cout << "All Brackets Checked" << endl;
	}
	else
	{
		cout << "Ending Brackets not found...!" << endl;
		exit(1);
	}
}

void StartBracesChecker()
{
	fstream fp;
	fp.open("code.txt");
	if (!fp)
		cout << "not found";

	char ch;
	total_Lenght = 0;
	while (1)
	{
		if (fp.eof())
			break;
		ch = fp.get();
		if (ch == '\n')
		{
			instructions[total_Lenght] = '$';
		}
		else if (ch == '\t')
		{
			continue;
		}
		else
		{
			instructions[total_Lenght] = ch;
		}
		++total_Lenght;
	}
	for (int j = 0; j < total_Lenght; j++)
	{
		if ((instructions[j] == 'f' && instructions[j + 1] == 'o' && instructions[j + 2] == 'r') || (instructions[j] == 'i' && instructions[j + 1] == 'f') || (instructions[j] == 'e' && instructions[j + 1] == 'l' && instructions[j + 2] == 's' && instructions[j + 3] == 'e') || (instructions[j] == 'w' && instructions[j + 1] == 'h' && instructions[j + 2] == 'i' && instructions[j + 3] == 'l' && instructions[j + 4] == 'e') || (instructions[j]=='s' && instructions[j+1]=='w' && instructions[j+2]=='i' && instructions[j+3]=='t' && instructions[j+4]=='c' && instructions[j+5]=='h') || (instructions[j] == 'e' && instructions[j + 1] == 'l' && instructions[j + 2] == 's' && instructions[j + 3] == 'e' && instructions[j+4]=='i' && instructions[j+5]=='f'))
		{
			int k = j;
			while (instructions[k] != '$')
			{
				++k;
			}
			if (instructions[k - 1] == '{' || instructions[k + 1] == '{')
			{
				continue;
			}
			else
			{
				cout << "Opening Brackets Not found...!";
				exit(0);
			}
		}
	}
}

 /* void Lining()
{
	StartBracesChecker();
	EndBracesChecker();

	fstream fp;
	fp.open("input.txt",ios::out);
	if (!fp)
		cout << "Not Found..!";

		for (int k= position; instructions[k] != '$'; k++,position=k)
		{
			fp << instructions[k];
		}
		cout << position;
		fp.close();

}
*/