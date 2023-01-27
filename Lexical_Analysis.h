#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;

string input[100];
int token_size = 0;

class Lex_Analysis
{
public:
	void filing();
	void Lex_Analysis_Main();
};

void Lex_Analysis::filing()
{
	fstream ile;
	ile.open("Lexical_input.txt", ios::in);
	string str;

	while (ile >> str)
	{
		input[token_size] = str;
		++token_size;
	}

	--token_size;
	ile.close();
}

void Lex_Analysis::Lex_Analysis_Main()
{
	int i = 0;
	char input[100];

	fstream fptr;
	fptr.open("input.txt", ios::in);

	fstream fp;
	fp.open("Lexical_input.txt", ios::out);

	if (!fp)
		cout << "Not found";

	while (fptr.getline(input, 100))
	{
		fflush(stdin);
		bool check = true;
		int n = strlen(input);
		for (int i = 0; i < n; i++)
		{
			if (input[i] == ' ')
			{
				continue;
			}

			if (input[i] == '\'')
			{
				i++;

				if (input[i + 1] == '\'')
				{
					fp << input[i] << " ";
					i++;
				}

				else
				{
					cout << "\nClosing Quotes Not found..!\n";
					check = false;
					break;
				}
			}
			else
				if (input[i] == '\"')
				{
					++i;
					while (input[i] != '\"')
					{
						if (i >= n)
						{
							cout << "\nClosing Quotes Not found..!\n";
							check = false;
							break;
						}
						fp << input[i];
						++i;
					}
					fp << " ";
				}
				else
					if (input[i] >= '0' && input[i] <= '9')
					{
						while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
						{
							fp << input[i];
							++i;
						}
						--i;
						fp << " ";
					}
					else
						if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
						{
							while ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
							{
								fp << input[i];
								++i;
							}
							--i;
							fp << " ";
						}
						else
							if (input[i] == '[' || input[i] == '{' || input[i] == '(' || input[i] == ']' || input[i] == '}' || input[i] == ')' || input[i] == ';' || input[i] == ':' || input[i] == '?' || input[i] == '#' || input[i] == ']' || input[i] == '}' || input[i] == ')' || input[i] == '_' || input[i] == '%' || input[i] == ',')
							{
								fp << input[i] << " ";
							}
							else
								if ((input[i] == '+' && (input[i + 1] == '+' || input[i + 1] == '=')) || (input[i] == '-' && (input[i + 1] == '-' || input[i + 1] == '=')) || (input[i] == '*' && input[i + 1] == '=') || (input[i] == '/' && input[i + 1] == '=') || (input[i] == '<' && (input[i + 1] == '<' || input[i + 1]=='=')) || (input[i] == '>' && (input[i + 1] == '>' || input[i+1]=='=')) || (input[i] == '|' && input[i + 1] == '|') || (input[i] == '&' && input[i + 1] == '&') || (input[i] == '=' && input[i + 1] == '=') || (input[i] == '!' && input[i + 1] == '='))
								{
									fp << input[i] << input[i + 1] << " ";
									++i;
								}
								else
									if ((input[i] == '+' && input[i + 1] != '=' && input[i + 1] != '+') || (input[i] == '-' && input[i + 1] != '=' && input[i + 1] != '-') || (input[i] == '*' && input[i + 1] != '=') || (input[i] == '/' && input[i + 1] != '=') || (input[i] == '<' && input[i + 1] != '<' && input[i+1]!='=') || (input[i] == '>' && input[i + 1] != '>' && input[i+1]!='=') || (input[i] == '=' && input[i + 1] != '=') || (input[i] == '!' && input[i + 1] != '='))
									{
										fp << input[i] << " ";
									}
		}
		fp.close();

		if (check)
		{
			filing();
		}
	}

	fptr.close();
}

