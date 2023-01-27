#include<iostream>
#include"File_Checker.h"
using namespace std;

int main()
{
	StartBracesChecker();
	EndBracesChecker();

	int k;
	fstream fp;
	fp.open("input.txt",ios::out);
	if (!fp)
		cout << "Not Found..!";
		
		A:
		for ( k = position; instructions[k] != '$'; k++)
		{
			fp << instructions[k];
		}
	
		fp.close();
	
	Lex_Analysis L;
	L.Lex_Analysis_Main();

  	CFG cfg;
 
 	int x = cfg.CheckALL();
	if(x)
	{
		cout << "\nInstruction Compiled Succesfully..!"<<endl;
	 	input[100] = {'\0'};
		token_size = 0;
		position = k;
		goto A; 

	}
	else
	{
		cout << "Syntax Error in Code"<<endl;
		exit(0);
 	}
	
  
}

 
