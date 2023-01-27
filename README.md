# CodeCheck-Lexical-Analysis-Tool-for-Expression-Validation

This project is a C++-based program that utilizes lexical analysis to verify the syntax of programming expressions written in the C++ language.

Project Functionalities and Specifications:
- The project is a C++-based program that uses lexical analysis to verify the syntax of programming expressions written in the C++ language.
- The project is able to identify and analyze various C++ language programming statements, including variable declarations, initializations, control statements, function declarations and calls, and return statements.
- The project utilizes header files such as "Stack.h", "File_Checker.h", "Lexical_Analysis.h" and "ContextFreeGrammar.h" to perform various tasks related to the analysis of a C++ language programming expression.
- The "Main.cpp" file coordinates the tasks by performing lexical analysis on the input expression and checking for syntax errors. If the syntax is correct, the expression is parsed, otherwise, the program terminates with a syntax error message.

This project is capable of identifying and analyzing various C++ language programming statements, including:
- Variable declarations, such as "int a;"
- Variable initializations, such as "int a = 5;" or "int a = 2 + 3;"
- IF, ELSE and ELSE IF statements, such as "if(a)" or "if(a < 4)" or "if(a > b)"
- Function declarations, such as "int func()" or "int func(char a)" or "int func(char a, char b)"
- WHILE statements, such as "while(a > b)"
- FOR statements, such as "for(int i = 0; i <= 10; i++)" or "for(int i = 0;; i++)"
- MAIN statements, such as "int main()" or "void main()"
- Variable declarations or initializations with functions, such as "int a = func();" or "a = func(b);"
- Function calls, such as "func();" or "func(a);"
- Switch cases statements, such as "switch(a)" or "case 1:" or "break;"
- cout and cin statements, such as "cout<<"Hello World";"
- Return statements, such as "return 0" or "return a;"

The project utilizes several header files to perform various tasks related to the analysis of a C++ language programming expression:
- "Stack.h" contains functions related to stack data structure
- "File_Checker.h" performs checks on opening and closing brackets of code
- "Lexical_Analysis.h" reads input from "input.txt" file, tokenizes expression, and writes tokenized version to "Lexical_input.txt"
- "ContextFreeGrammar.h" verifies syntax of different statements such as declarations, initializations, and for loop expressions
- "Main.cpp" coordinates tasks by performing lexical analysis on input expression, and checking for syntax errors. If syntax is correct, expression is parsed, otherwise program terminates with syntax error message.
