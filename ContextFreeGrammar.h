#include"Lexical_Analysis.h"   
using namespace std;
 
string dataType[] = { "char","double","float","int","long","short","string" };
string returnType[] = { "char","double","float","int","long","short","string","void" };
bool mainflag = 0; 
 
class CFG
{
	public:
	bool DT(string token);
	bool RT(string token);
	bool SEMICO(string token);
	bool VAR(string token);
	bool FUNC(string token);
	bool O_BRAC(string token);
	bool C_BRAC(string token);
	bool F_BRAC(string token);
	bool COMMA(string token);
	bool COLLIN(string token);
	bool SPACE(string token);
	bool INT(string token);
	bool ASSIGN(string token);
	bool OPERATOR(string token);
	bool LOGIC(string token);
	bool COMPARE(string token);
	bool VAR_OP_VAR(string token1, string token2, string token3);
	bool LITERALS(string token);
	bool INC(string token);
	bool DEC(string token);
	bool CHAR(string token);
	bool DECLARE();
	bool INITIALIZE();
	bool IF();
	bool ELSE();
	bool EL_SEIF();
	bool FUNC_DECLARE();
	bool WHILE();
	bool FOR();
	bool MAIN();
	bool FUNC_WITH_DECLARE();
	bool FUNC_WITH_INITIALIZE();
	bool FUNC_CALL();
	bool SWITCH();
	bool BREAK();
	bool CASE();
	bool DEFAULT();
	bool COUT();
	bool CIN();
	bool RETURN();
	bool CheckALL();
	
};


bool CFG :: DT(string token) //Any Data Type
{
	for(int i=0;i<9;i++)
	{
		if(token==dataType[i]) { return 1; }
   	}
	
	return 0;
}
	
bool CFG :: RT(string token) //Any Return Type
{
	for(int i=0;i<9;i++)
	{
		if(token==returnType[i]) { return 1; }
   	}
	
	return 0;
}	
	
bool CFG :: SEMICO(string token) //SemiCollin -> ;
{
	if(token == ";") return 1;
	else return 0;
}
	
bool CFG :: VAR(string token) //Any Variable
{
	if(DT(token) && RT(token)) return 0;
	
	else
	{	
	
	for(int i=0;i<token.length();i++)
		{
			if((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || token[i] == '_') 
			continue;
			
			else
			return 0;
		}	
		
	return 1;	 
	
	}
}

bool CFG :: FUNC(string token) //Any Function
{
	if(DT(token) && RT(token)) return 0;
	
	else
	{	
	
	for(int i=0;i<token.length();i++)
		{
			if((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || token[i] == '_') 
			continue;
			
			else
			return 0;
		}	
		
	return 1;	 
	
	}
}
	
bool CFG :: O_BRAC(string token) //Open Brackets -> (
{
	if(token == "(") return 1;
	else return 0;
}

bool CFG :: C_BRAC(string token) //Close Brackets -> )
{
	if(token == ")") return 1;
	else return 0;
}
	
bool CFG :: F_BRAC(string token) //Full Brackets -> ()
{
	if(token == "()") return 1;
	else return 0;
}
	
bool CFG :: COMMA(string token) //Comma -> ,
{
	if(token == ",") return 1;
	else return 0;
}	

bool CFG :: COLLIN(string token) //Collin -> :
{
	if(token == ":") return 1;
	else return 0;
}	

bool CFG :: SPACE(string token)
{
if(token == "\n" || token == "\t" |token == "endl") return 1;
else return 0;
}

bool CFG :: INT(string token) //Any Interger
{
	for (int i = 0; i < token.size(); i++)
	{
		if (token[i] >= '0' && token[i] <= '9')
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

bool CFG :: ASSIGN(string token) //Assignment Operator -> =
{
	if(token == "=") return 1;
    else return 0;
}

bool CFG :: OPERATOR(string token) //Arthematic Operators -> +,-,*,/
{
     
    if(token == "+" || token== "-" || token == "/" || token == "*") return 1;
	else return 0;
}
	
bool CFG :: LOGIC(string token) //Logical Operators -> ||,&&
{
	if(token == "||" || token == "&&") return 1;
	else return 0;	
}

bool CFG :: COMPARE(string token) //Comparision Operator -> !=,<,>,<=,>=,==
{
	if(token == "!=" || token == "<" || token == ">" || token == "<=" || token == ">=" || token == "==") return 1;
	else return 0;
}
	
bool CFG :: VAR_OP_VAR(string token1, string token2, string token3) //Variable, Arthematic Operator, Variable
{
	if(VAR(token1)==1 || INT(token1)==1)
	{
		if(OPERATOR(token2)==1)
		{
			if(VAR(token3)==1 || INT(token3)==1) return 1;

			else return 0;
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: LITERALS(string token) //All literals
{
	return 1;
}

bool CFG :: INC(string token) //Increment Operator -> ++
{
	if(token == "++") return 1;
	else return 0;
}

bool CFG :: DEC(string token) //Decrement Operator -> --
{
	if(token == "--") return 1;
	else return 0;
}
	
bool CFG :: CHAR(string token) //Any Character
{
	int func_size = 0;
	if(token[func_size] == '\'')
	{
		++func_size;
		if(token[func_size]>='a' && token[func_size] <= 'z' || token[func_size]>='A' && token[func_size] <= 'Z' || token[func_size]>='0' && token[func_size] <= '9')
		{
			++func_size;
			if(token[func_size] == '\'')
			{
				func_size=0;
				return 1;
			}
		}
	}
	else return 0;
}

bool CFG:: DECLARE()
{
	//EX -> DT VAR SEMICO
	//DT -> Any Data Type
	//VAR -> Any Variable
	//SEMICO -> ;
	
	//EX -> DT VAR ASSIGN INT/VAR SEMICO
	//DT -> Any Data Type
	//VAR -> Any Variable
	//ASSIGN -> =
	//INT/VAR -> Integer/Variable
	//SEMICO -> ;
	
	//EX -> DT VAR ASSIGN INT/VAR OPERATOR INT/VAR SEMICO
	//DT -> Any Data Type
	//VAR -> Any Variable
	//ASSIGN -> =
	//INT/VAR -> Integer/Variable
	//OPERATOR -> +,-,*,/
	//INT/VAR -> Integer/Variable
	//SEMICO -> ;
	
	int func_size = 0;

	if(DT(input[func_size]) && func_size<token_size)
	{
		++func_size;
		if(VAR(input[func_size]) && func_size<token_size)
		{
			++func_size;
			if(SEMICO(input[func_size]))
			{	
				if(func_size == token_size)
					{ return 1; }
					else return 0;
			}

			else
			{
				if(ASSIGN(input[func_size]) && func_size<token_size)
				{
					++func_size;
					if((INT(input[func_size]) || VAR(input[func_size])) && func_size<token_size)
					{	
						++func_size;
						if(SEMICO(input[func_size]))
						{	
							if(func_size == token_size)
							{ return 1; }
							else return 0;
						}
						
						else
						{
							A:
							if(OPERATOR(input[func_size]) && func_size<token_size)
							{
								++func_size;
								if((INT(input[func_size]) || VAR(input[func_size])) && func_size<token_size)
								{
									++func_size;
									if(SEMICO(input[func_size]) && func_size == token_size)
									{
										return 1;
									}
									
									else goto A;
								}
								else return 0;
							}
							else return 0;			
						}
					}
					else return 0;
				}
				else return 0;
			}
		}
		else return 0;		
	}
	else return 0;
}

bool CFG :: INITIALIZE()
{
	int func_size = 0;

	if(VAR(input[func_size]) && func_size<token_size)
	{
		++func_size;
		if(SEMICO(input[func_size]))
		{	
			if(func_size == token_size)
				{ return 1; }
				else return 0;
		}

		else
		{
			if(ASSIGN(input[func_size]) && func_size<token_size)
			{
				++func_size;
				if((INT(input[func_size]) || VAR(input[func_size])) && func_size<token_size)
				{	
					++func_size;
					if(SEMICO(input[func_size]))
					{	
						if(func_size == token_size)
						{ return 1; }
						else return 0;
					}
					
					else
					{
						A:
						if(OPERATOR(input[func_size]) && func_size<token_size)
						{
							++func_size;
							if((INT(input[func_size]) || VAR(input[func_size])) && func_size<token_size)
							{
								++func_size;
								if(SEMICO(input[func_size]) && func_size == token_size)
								{
									return 1;
								}
								
								else goto A;
							}
							else return 0;
						}
						else return 0;			
					}
				}
				else return 0;
			}
			else return 0;
		}
	}
	else return 0;		
}

bool CFG :: IF()
{
	int func_size = 0;
	
	if(input[func_size] == "if" && func_size<token_size)
	{
		++func_size;
		if(O_BRAC(input[func_size]) &&func_size<token_size)
		{
			++func_size;
			if(INC(input[func_size]) && func_size<token_size)
			{
				++func_size;
				goto B;	
			}
			
			else
			{	
				B:
				if((INT(input[func_size]) || VAR(input[func_size]) || CHAR(input[func_size])) && func_size<token_size)
				{
					
					++func_size;
					if(C_BRAC(input[func_size]) &&func_size==token_size)
					{
						return 1;
					}
					
					
					else
					{
						A:
						if((OPERATOR(input[func_size]) || LOGIC(input[func_size]) || COMPARE(input[func_size]) || DEC(input[func_size]) || (ASSIGN(input[func_size]) && func_size==3)) &&func_size<token_size)
						{	
							++func_size;
							if((INT(input[func_size]) || VAR(input[func_size]) || CHAR(input[func_size])) && func_size<token_size)
							{			
								++func_size;
								if(C_BRAC(input[func_size]) &&func_size==token_size)
								{
									return 1;
								}
								else goto A;
							}
							else return 0;
						}
						
						else
						{
							if(INC(input[func_size]) && func_size<token_size)
							{
								++func_size;
								if(C_BRAC(input[func_size]) && func_size==token_size)
								{
									return 1;
								}
								else return 0;
									
							}
							else return 0;	
						}
					}
				
				}
				else return 0;
			}
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: ELSE()
{
	if(input[0] == "else" && token_size == 0)
		return 1;
		
	else return 0;	
}

bool CFG :: EL_SEIF()
{
	int func_size = 0;
	
	if(input[func_size] == "else" && func_size<token_size)
	{
		++func_size;
		if(input[func_size] == "if" && func_size<token_size)
		{
			++func_size;
			if(O_BRAC(input[func_size]) &&func_size<token_size)
			{
				++func_size;
				if(INC(input[func_size]) && func_size<token_size)
				{
					++func_size;
					goto B;	
				}
				
				else
				{	
					B:
					if((INT(input[func_size]) || VAR(input[func_size]) || CHAR(input[func_size])) && func_size<token_size)
					{
						
						++func_size;
						if(C_BRAC(input[func_size]) &&func_size==token_size)
						{
							return 1;
						}
						
						
						else
						{
							A:
							if((OPERATOR(input[func_size]) || LOGIC(input[func_size]) || COMPARE(input[func_size]) || DEC(input[func_size]) || (ASSIGN(input[func_size]) && func_size==3)) &&func_size<token_size)
							{	
								++func_size;
								if((INT(input[func_size]) || VAR(input[func_size]) || CHAR(input[func_size])) && func_size<token_size)
								{			
									++func_size;
									if(C_BRAC(input[func_size]) &&func_size==token_size)
									{
										return 1;
									}
									else goto A;
								}
								else return 0;
							}
							
							else
							{
								if(INC(input[func_size]) && func_size<token_size)
								{
									++func_size;
									if(C_BRAC(input[func_size]) && func_size==token_size)
									{
										return 1;
									}
									else return 0;
										
								}
								else return 0;	
							}
						}
					
					}
					else return 0;
				}
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;	
}

bool CFG :: FUNC_DECLARE()
{
	if(mainflag == 1)
		return 0;
	else
	{		
		int func_size = 0;
		
		if(RT(input[func_size]) && func_size<token_size)
		{
			++func_size;
			if(FUNC(input[func_size]) && func_size<token_size)
			{
				++func_size;
				if(O_BRAC(input[func_size]) && func_size<token_size)
				{
					A:
					++func_size;
					if(DT(input[func_size]) && func_size<token_size)
					{
						++func_size;
						if(VAR(input[func_size]) && func_size<token_size)
						{
							++func_size;
							if(C_BRAC(input[func_size]) && func_size==token_size)
							{
								return 1;
							}
							
							else
							{ 
								if(COMMA(input[func_size]) && func_size<token_size)
								{
									goto A;
								}
								
								else return 0;
							} 		
						}
						else return 0;
					}
					else return 0;
				}
				else return 0;	
			}
			else return 0;
		}
		else return 0;
	}
}

bool CFG::WHILE()
{
	int func_size = 0;
	
	if(input[func_size] == "while" && func_size<token_size)
	{
		++func_size;
		if(O_BRAC(input[func_size]) &&func_size<token_size)
		{
			++func_size;
			if(INC(input[func_size]) && func_size<token_size)
			{
				++func_size;
				goto B;	
			}
			
			else
			{	
				B:
				if((INT(input[func_size]) || VAR(input[func_size]) || CHAR(input[func_size])) && func_size<token_size)
				{
					
					++func_size;
					if(C_BRAC(input[func_size]) && func_size == token_size)
					{
						return 1;
					}
					
					else
					{
						A:
						if((OPERATOR(input[func_size]) || LOGIC(input[func_size]) || COMPARE(input[func_size]) || DEC(input[func_size]) || (ASSIGN(input[func_size]) && func_size==3)) &&func_size<token_size)
						{	
							++func_size;
							if((INT(input[func_size]) || VAR(input[func_size]) || CHAR(input[func_size])) && func_size<token_size)
							{			
								++func_size;
								if(C_BRAC(input[func_size]) &&func_size==token_size)
								{
									return 1;
								}
								else return 0;
							}
							else return 0;
						}
						
						else
						{
							if(INC(input[func_size]) && func_size<token_size)
							{
								++func_size;
								if(C_BRAC(input[func_size]) && func_size==token_size)
								{
									return 1;
								}
								else return 0;
									
							}
							else return 0;	
						}
					}
				
				}
				else return 0;
			}
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: FOR()
{
	int func_size = 0;
	if (input[func_size] == "for")
	{
		++func_size;
		if (O_BRAC(input[func_size]))
		{

			++func_size;
			if ((DT(input[func_size]) && (VAR(input[func_size + 1])))) ///(VAR(input[func_size])
			{
				++func_size;
				++func_size;
				if (ASSIGN(input[func_size]))
				{
					++func_size;
					if (INT(input[func_size]) || VAR(input[func_size]))
					{
						++func_size;
						if (SEMICO(input[func_size]))
						{
							++func_size;
							if (VAR(input[func_size]))
							{
								++func_size;
								if (COMPARE(input[func_size]))
								{

									++func_size;
									if ((INT(input[func_size])) || (VAR(input[func_size])))
									{
										++func_size;
										if (SEMICO(input[func_size]))
										{

											++func_size;

											if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
											{

												++func_size;

												if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
												{
													++func_size;
													if (C_BRAC(input[func_size]))
													{
														if (func_size == token_size)
														{
															return 1;
														}
													}
													else
														return 0;
												}
												else
													return 0;
											}
											//

											else
											{

												if (C_BRAC(input[func_size]))
												{
													if (func_size == token_size)
													{
														return 1;
													}
												}
												else
													return 0;
											}

											//
										}

										else
											return 0;
									}

									else
										return 0;
								}
								else
									return 0;
							}

							//

							else
							{

								if (SEMICO(input[func_size]))
								{
									++func_size;
									if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
									{
										++func_size;

										if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
										{
											++func_size;
											if (C_BRAC(input[func_size]))
											{
												if (func_size == token_size)
												{
													return 1;
												}
											}
											else
												return 0;
										}
										else
											return 0;
									}
									//inner
									else
									{

										if (C_BRAC(input[func_size]))
										{
											if (func_size == token_size)
											{
												return 1;
											}
										}
										else
											return 0;
									}
									//inner
								}
								else
									return 0;
							}

							//
						}

						else
							return 0;
					}
					else
						return 0;
				}
				else
					return 0;
			}

			//first if not varibale

			else
			{

				//

				if ((VAR(input[func_size])))
				{

					++func_size;
					if (ASSIGN(input[func_size]))
					{
						++func_size;
						if (INT(input[func_size]) || VAR(input[func_size]))
						{
							++func_size;
							if (SEMICO(input[func_size]))
							{
								++func_size;
								if (VAR(input[func_size]))
								{
									++func_size;
									if (COMPARE(input[func_size]))
									{

										++func_size;
										if ((INT(input[func_size])) || (VAR(input[func_size])))
										{
											++func_size;
											if (SEMICO(input[func_size]))
											{

												++func_size;

												if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
												{

													++func_size;

													if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
													{
														++func_size;
														if (C_BRAC(input[func_size]))
														{
															if (func_size == token_size)
															{
																return 1;
															}
														}
														else
															return 0;
													}
													else
														return 0;
												}
												//

												else
												{

													if (C_BRAC(input[func_size]))
													{
														if (func_size == token_size)
														{
															return 1;
														}
													}
													else
														return 0;
												}

												//
											}

											else
												return 0;
										}

										else
											return 0;
									}
									else
										return 0;
								}

								//

								else
								{

									if (SEMICO(input[func_size]))
									{
										++func_size;
										if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
										{
											++func_size;

											if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
											{
												++func_size;
												if (C_BRAC(input[func_size]))
												{
													if (func_size == token_size)
													{
														return 1;
													}
												}
												else
													return 0;
											}
											else
												return 0;
										}
										//inner
										else
										{

											if (C_BRAC(input[func_size]))
											{
												if (func_size == token_size)
												{
													return 1;
												}
											}
											else
												return 0;
										}
										//inner
									}
									else
										return 0;
								}

								//
							}

							else
								return 0;
						}
						else
							return 0;
					}
					else
						return 0;

					//
				}

				//
				if (SEMICO(input[func_size]))
				{
					++func_size;
					if (VAR(input[func_size]))
					{
						++func_size;
						if (COMPARE(input[func_size]))
						{
							++func_size;
							if (VAR(input[func_size]) || INT(input[func_size]))
							{

								++func_size;
								if (SEMICO(input[func_size]))
								{
									++func_size;
									if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
									{
										++func_size;

										if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
										{
											++func_size;
											if (C_BRAC(input[func_size]))
											{
												if (func_size == token_size)
												{
													return 1;
												}
											}
											else
												return 0;
										}
										else
											return 0;
									}
									//

									else
									{

										if (C_BRAC(input[func_size]))
										{
											if (func_size == token_size)
											{
												return 1;
											}
										}
										else
											return 0;
									}

									//
								}

								else
									return 0;
							}

							else
								return 0;
						}
						else
							return 0;
					}

					//

					else
					{

						if (SEMICO(input[func_size]))
						{
							++func_size;
							if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
							{
								++func_size;

								if (VAR(input[func_size]) || INC(input[func_size]) || DEC(input[func_size]))
								{
									++func_size;
									if (C_BRAC(input[func_size]))
									{
										if (func_size == token_size)
										{
											return 1;
										}
									}
									else
										return 0;
								}
								else
									return 0;
							}
							//inner
							else
							{

								if (C_BRAC(input[func_size]))
								{
									if (func_size == token_size)
									{
										return 1;
									}
								}
								else
									return 0;
							}
							//inner
						}
						else
							return 0;
					}

					//
				}
				else
					return 0;
			}
			//first if not varibale
		}
		else
			return 0;
	}
	else
		return 0;
}

bool CFG :: MAIN()
{
	int func_size = 0;
	
	if((input[func_size] == "int" || input[func_size] == "void") && func_size<token_size)
	{
		++func_size;
		if(input[func_size] == "main" && func_size<token_size)
		{
			++func_size;
			if(O_BRAC(input[func_size]) && func_size<token_size)
			{
				++func_size;
				if(C_BRAC(input[func_size]) && func_size==token_size)
				{
					mainflag = 1;
					return 1;
				}
				else
				{
					if(C_BRAC(input[func_size]) && func_size<token_size)
					{	
						++func_size;
						if((input[func_size] == "{") && func_size==token_size)
						{
							mainflag = 1;
							return 1;	
						}
						else return 0;
					}
					else return 0;	
				}
			}
			else return 0;	
		}
		else return 0;	
	}
	else return 0;
}

bool CFG :: FUNC_WITH_DECLARE()
{
	if(mainflag == 0)
	return 0;
	
	else
	{
		int func_size = 0;
		if(DT(input[func_size]) && func_size<token_size)
		{
			++func_size;
			if(VAR(input[func_size]) && func_size<token_size)
			{
				++func_size;
				if(ASSIGN(input[func_size]) && func_size<token_size)
				{
					++func_size;
					if(FUNC(input[func_size]) && func_size<token_size)
					{
						++func_size;
						if(O_BRAC(input[func_size]) && func_size<token_size)
						{
							X:
							++func_size;
							if((VAR(input[func_size]) ||  LITERALS(input[func_size]) ||  INT(input[func_size]) ||  CHAR(input[func_size])) && func_size<token_size) 
							{
								++func_size;
								if(C_BRAC(input[func_size]) && func_size<token_size)
								{
									++func_size;
									if(SEMICO(input[func_size]) && func_size==token_size)
									{
										return 1;
									}
									else return 0;
								}	
								
								else
								{
									if(COMMA(input[func_size]) && func_size<token_size)
									goto X;
									
									else return 0;
								}
								
							}	
							else return 0;
						}	
						else return 0;
					}	
					else return 0;	
				}
				else return 0;
			}
			else return 0;		
		}
		else return 0;
	}
}

bool CFG :: FUNC_WITH_INITIALIZE()
{
	if(mainflag == 0)
	return 0;
	
	else
	{
		int func_size = 0;
		if(VAR(input[func_size]) && func_size<token_size)
		{
			++func_size;
			if(ASSIGN(input[func_size]) && func_size<token_size)
			{
				++func_size;
				if(FUNC(input[func_size]) && func_size<token_size)
				{
					++func_size;
					if(O_BRAC(input[func_size]) && func_size<token_size)
					{
						X:
						++func_size;
						if((VAR(input[func_size]) ||  LITERALS(input[func_size]) ||  INT(input[func_size]) ||  CHAR(input[func_size])) && func_size<token_size) 
						{
							++func_size;
							if(C_BRAC(input[func_size]) && func_size<token_size)
							{
								++func_size;
								if(SEMICO(input[func_size]) && func_size==token_size)
								{
									return 1;
								}
								else return 0;
							}	
							
							else
							{
								if(COMMA(input[func_size]) && func_size<token_size)
								goto X;
								
								else return 0;
							}
							
						}	
						else return 0;
					}	
					else return 0;
				}	
				else return 0;	
			}
			else return 0;
		}
		else return 0;
	}
}

bool CFG :: FUNC_CALL()
{
	if(mainflag == 0)
	return 0;
	
	else
	{
		int func_size = 0;
		if(FUNC(input[func_size]) && func_size<token_size)
		{
			++func_size;
			if(O_BRAC(input[func_size]) && func_size<token_size)
			{
				X:
				++func_size;
				if((VAR(input[func_size]) ||  LITERALS(input[func_size]) ||  INT(input[func_size]) ||  CHAR(input[func_size])) && func_size<token_size) 
				{
					++func_size;
					if(C_BRAC(input[func_size]) && func_size<token_size)
					{
						++func_size;
						if(SEMICO(input[func_size]) && func_size==token_size)
						{
							return 1;
						}
						else return 0;
					}	
					
					else
					{
						if(COMMA(input[func_size]) && func_size<token_size)
						goto X;
						
						else return 0;
					}
					
				}	
				else return 0;
			}	
			else return 0;
		}	
		else return 0;
	}
}

bool CFG :: SWITCH()
{
	int func_size=0;
	if(input[func_size] == "switch"  &&  token_size>func_size)
	{
		++func_size;
		if(O_BRAC(input[func_size])  && token_size>func_size)
		{
			++func_size;
			if(VAR(input[func_size]) && token_size>func_size)
			{
				++func_size;
				if(C_BRAC(input[func_size]) && func_size==token_size)
				{				
					return 1;	 
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: BREAK()
{
	int func_size = 0;
	if(input[func_size] == "break" && token_size>func_size)
	{
		++func_size;
		if(SEMICO(input[func_size]) && func_size==token_size)
		{
			return 1;
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: CASE()
{
	int func_size = 0;
	if(input[func_size] == "case" && token_size>func_size)
	{
		++func_size;
		if((INT(input[func_size]) || CHAR(input[func_size]) || OPERATOR(input[func_size]) || VAR(input[func_size])) && token_size>func_size)  
		{
			++func_size;
			if(COLLIN(input[func_size]) && token_size==func_size)
			{
				return 1;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: DEFAULT()
{
	int func_size = 0;
	if(input[func_size] == "default" && token_size>func_size)
	{
		++func_size;
		if(COLLIN(input[func_size]) && func_size==token_size)
		{
			return 1;
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: COUT()
{
	int func_size = 0;
	
	if(input[func_size] == "cout" && func_size<token_size)
	{
		++func_size;
		if(input[func_size] == "<<" && func_size<token_size)
		{
			++func_size;
			A:
			if(LITERALS(input[func_size]) && func_size<token_size)
			{
				++func_size;
				if(SEMICO(input[func_size]) && func_size==token_size)
				{
					return 1;
				}
				else
				{
					if(input[func_size] == "<<" && func_size<token_size)
					{
						++func_size;
					    if(input[func_size] == "endl" && func_size<token_size)
							{
								++func_size;
							    if(SEMICO(input[func_size]) && func_size==token_size)
									{
										return 1;
									}
									else return 0;
							}
							else goto A;	
					}
					else goto A;	
				}
	
			}
			else return 0;
	
		}
		else return 0;
	}
	else return 0;
}

bool CFG ::CIN()
{
	int func_size = 0;
	if (input[func_size] == "cin")

		++func_size;
zx:
	if (input[func_size] == ">>")
	{
		++func_size;

		if (VAR(input[func_size]) || SPACE(input[func_size]))
		{
			++func_size;
			if (SEMICO(input[func_size]))
			{
				if (func_size == token_size)
				{
					return 1;
				}
				else
					return 0;
			}
			else
				goto zx;
		}
		else
			return 0;
	}
	else
		return 0;
}

bool CFG :: RETURN()
{
	int func_size = 0;
	if(input[func_size] == "return" && token_size>func_size)
	{
		++func_size;
		if((INT(input[func_size]) || CHAR(input[func_size]) || VAR(input[func_size])) && token_size>func_size)  
		{
			++func_size;
			if(COLLIN(input[func_size]) && token_size==func_size)
			{
				return 1;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

bool CFG :: CheckALL()
{
	if(DECLARE()) return 1;
	if(INITIALIZE()) return 1;
	if(IF()) return 1;
	if(ELSE()) return 1;
	if(EL_SEIF()) return 1;
	if(FUNC_DECLARE()) return 1;
	if(WHILE()) return 1;
	if(FOR()) return 1;
	if(MAIN()) return 1;
	if(FUNC_WITH_DECLARE()) return 1;
	if(FUNC_WITH_INITIALIZE()) return 1;
	if(FUNC_CALL())return 1;
	if(SWITCH()) return 1;
	if(BREAK()) return 1;
	if(CASE()) return 1;
	if(DEFAULT()) return 1;
	if(COUT()) return 1;
	if(CIN()) return 1;
	if(RETURN()) return 1;
	else return 0;
}
