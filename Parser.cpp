
#include "stdafx.h"
#include "general.h"
#include "parser.h"
#include "Scanner.h"
#include <string>
#include <ctype.h>

parseClass::parseClass()
{

}

bool parseClass::validStatement(int sideArray[], int count)
{
	/*cout << "Checking statement: ";
	scanner.printCurrentLine();
	cout << "Has a count of " << count << endl;*/
	if (count == 3)
	{
		if (sideArray[0] == E && sideArray[2] == E)
		{
			/*if (scanner.seeExpressionStatus() == true)
			{
			cout << "E-> E ";
			if (sideArray[1] == ADD_ST)
			cout << "+";
			else if (sideArray[1] == SUB_ST)
			cout << "-";
			else if (sideArray[1] == MULT_ST)
			cout << "*";
			else if (sideArray[1] == DIV_ST)
			cout << "/";
			else if (sideArray[1] == EQUAL_ST)
			cout << "=";
			else if (sideArray[1] == LESS_ST)
			cout << "<";
			else if (sideArray[1] == GREAT_ST)
			cout << ">";
			cout << " E" << endl;
			}*/
			return true;
		}
		else if (sideArray[0] == RPAREN_T && sideArray[1] == E && sideArray[2] == LPAREN_T)
		{
			/*if (scanner.seeExpressionStatus() == true)
			{
			//cout << "E->(E)\n";
			}*/
			return true;
		}
		else if (sideArray[0] == RBRACK_T && sideArray[1] == E && sideArray[2] == LBRACK_T)
		{
			/*if (scanner.seeExpressionStatus() == true)
			{
			//cout << "E->(E)\n";
			}*/
			return true;
		}
	}
	else if (count == 1)
	{
		/*if (sideArray[0] == IDENT_T && scanner.seeExpressionStatus() == true)
		{
		//cout << "E-> id" << endl;
		}
		else if (sideArray[0] == NUM_T && scanner.seeExpressionStatus() == true)
		{
		//cout << "E-> integer-constant" << endl;
		}*/
		return true;
	}
	return false;
}

void parseClass::parse_expr()
{
	tokenClass newToken;
	newToken.setToken(COMMA_T, MISC_ST, ",");
	pstack.push(newToken);
	//tokenClass token;
	//token = scanner.getToken();
	int topTerm = pstack.returnTopMostTerminal();
	while (1)
	{
		//cout << "Top Most Terminal: " << pstack.returnTopMostTerminal() << endl;
		//cout << "Token: " << token.getType() << endl;
		//token.display();
		if (token.getType() == ASSIGN_T)
			toConvert += token.lexeme;
		if (pstack.returnTopMostTerminal() == COMMA_T && token.getType() == COMMA_T || token.getType() == DO_T || token.getType() == ASSIGN_T || token.getType() == THEN_T || token.getType() == TIMES_T || token.getType() == LBRACK_T || token.getType() == RBRACK_T)
			return;
		if (token.getType() == PERIOD_T)
		{
			hasEnded = true;
			return;
		}
		else if (token.getType() == EOF_T)
		{
			//cout << "LARS has just compiled " << scanner.printLines() << " lines of code and terminated inside the parser."<<endl;
			//scanner.s_PrintTable();
			//cin.get();
			//exit(0);
			if (hasEnded==false)
				//tran.printError("ERROR: Missing [.] to end statement.");
			return;
		}
		else
		{
			toConvert += token.lexeme;
			topTerm = pstack.returnTopMostTerminal();
			if (preParse(topTerm, token.getType()) == '<' || preParse(topTerm, token.getType()) == '=')
			{
				pstack.push(token);
				token = scanner.getToken();
			}
			else if (preParse(topTerm, token.getType()) == '>')
			{
				int x = 0;
				int popped;
				int newArray[15];
				int lastTermPopped;
				hasPopped = false;
				do
				{
					popped = pstack.pop();
					if (popped != E)
					{
						hasPopped = true;
						lastTermPopped = popped;
					}
					newArray[x] = popped;
					x++;
				} while (hasPopped == false || pstack.isThereATerminalOnTop() == false || preParse(pstack.returnTopMostTerminal(), lastTermPopped) != '<');
				if (validStatement(newArray, x) == true)
				{
					newToken.setToken(E, MISC_ST, "E");
					pstack.push(newToken);
				}
				else
				{
					token.display();
					tran.printError("Syntax Error: Invalid right hand side ");
					//scanner.printCurrentLine();
					//cin.get();
					//exit(0);
				}
			}
			else
			{
				tran.printError("Syntax Error: Invalid Expression Line ");
				//scanner.printCurrentLine();
				//cin.get();
				//exit(0);
			}
		}
	}
}

char parseClass::preParse(int topTerm, int token)
{
	static char table[10][10] =
	{ '>', '<', '<', '<', '>', '<', '<', '<', '>', 'E',
	'>', '>', '<', '<', '>', '<', '<', '<', '>', 'E',
	'>', '>', '>', '<', '>', '<', '<', '<', '>', 'E',
	'<', '<', '<', '<', '=', '<', '<', '<', '>', 'E',
	'>', '>', '>', 'E', '>', '=', '=', 'E', '>', 'E',
	'>', '>', '>', '>', '>', '=', '=', 'E', '>', 'E',
	'>', '>', '>', 'E', '>', '=', '=', 'E', '>', 'E',
	'>', '>', '>', 'E', '>', 'E', 'E', 'E', '>', 'E',
	'<', '<', '<', '<', 'E', '<', '<', '<', '=', 'E',
	'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E' };
	int col;
	int row;
	if (topTerm == RELOP_T || topTerm == ASSIGN_T || topTerm == EQUAL_ST || topTerm == LESS_ST || topTerm == GREAT_ST)
		row = 0;
	else if (topTerm == ADDOP_T || topTerm == ADD_ST || topTerm == SUB_ST)
		row = 1;
	else if (topTerm == MULOP_T || topTerm == MULT_ST || topTerm == DIV_ST)
		row = 2;
	else if (topTerm == LPAREN_T || topTerm == RBRACK_T)
		row = 3;
	else if (topTerm == RPAREN_T || topTerm == LBRACK_T)
		row = 4;
	else if (topTerm == COMMA_T || topTerm == DO_T || topTerm == THEN_T || topTerm == IF_T || topTerm == QUEST_T)
		row = 8;
	else if (topTerm == IDENT_T || topTerm == WHILE_T || topTerm == STRING_T || topTerm == SAY_T)
		row = 5;
	else if (topTerm == NUM_T)
		row = 6;
	else if (topTerm == BOOL_T)
		row = 7;
	else
		row = 9;
	if (token == RELOP_T || token == ASSIGN_T || token == EQUAL_ST || token == LESS_ST || token == GREAT_ST)
		col = 0;
	else if (token == ADDOP_T || token == ADD_ST || token == SUB_ST)
		col = 1;
	else if (token == MULOP_T || token == MULT_ST || token == DIV_ST)
		col = 2;
	else if (token == LPAREN_T || token == LBRACK_T)
		col = 3;
	else if (token == RPAREN_T || token == RBRACK_T)
		col = 4;
	else if (token == COMMA_T || token == DO_T || token == THEN_T || token == IF_T || token == QUEST_T)
		col = 8;
	else if (token == IDENT_T || token == WHILE_T || token == STRING_T || token == SAY_T)
		col = 5;
	else if (token == NUM_T)
		col = 6;
	else if (topTerm == BOOL_T)
		col = 7;
	else
		col = 9;
	return(table[row][col]);
}

void parseClass::parseLars()
{
	scanner.s_FillTable();
	token = scanner.getToken();
	larsStatement();
	//cout << "This: " << token.lexeme << endl;
	larsStatementTail();
	//scanner.s_PrintTable();
}

void parseClass::larsStatement()
{
	if (token.getType() == WHILE_T)
	{
		token = scanner.getToken();
		parse_expr();
		tran.translateWhile(toConvert);
		toConvert = "";
		cout << token.lexeme << endl;
		if (token.getType() == DO_T)
		{
			token = scanner.getToken();
			larsStatement();
			return;
		}
		else
		{
			tran.printError("ERROR: Expected [do]");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
	}
	else if (token.getSubtype() == FUNCT_ST)
	{
		scanner.s_TableAddFunct(token.lexeme);
		part1 = token.lexeme;
		token = scanner.getToken();
		if (token.getType() == ASSIGN_T)
		{
			token = scanner.getToken();
			//cout << "RIGHT?" << endl;
			parse_expr();
			tran.translateFunction(part1, toConvert);
			toConvert = "";
			part1 = "";
			//token = scanner.getToken();
			larsStatementTail();
		}
		else if (token.getType() == COMMA_T)
		{
			tran.translateFunctionCall(part1);
			part1 = "";
			larsStatementTail();
		}
		else if (token.getType() == EOF_T)
		{
			tran.translateFunctionCall(part1);
			part1 = "";
			return;
		}
		else
		{
			tran.printError("ERROR: Expected [=] OR [,]");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
	}
	else if (token.getSubtype() == VAR_ST || token.getType() == NUM_T)
	{
		bool isVar = false;
		if (token.getSubtype() == VAR_ST)
		{
			isVar = true;
			scanner.s_TableAddVar(token.lexeme, VAR_ST, NUM_T);
		}
		part1 = token.lexeme;
		//tran.printError(token.lexeme);
		parse_expr();
		//tran.printError(token.lexeme);
		//tran.printError("TEST")
		if (token.getType() == ASSIGN_T && isVar == true)
		{
			token = scanner.getToken();
			//toConvert = "";
			parse_expr();
			//tran.printError("TEST");
			tran.translateStatement("", toConvert);
			part1 = "";
			toConvert = "";
			larsStatementTail();
		}
		else if (token.getType() == ASSIGN_T && isVar == false)
		{
			tran.printError("ERROR: Can't assign a value to a number");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
		else if (token.getType() == LBRACK_T && isVar == true)
		{
			arrayStatement();
			followArray();
			tran.translateArray(part1, part2);
			part1, part2 = "";
		}
		else if (token.getType() == LBRACK_T && isVar == false)
		{
			tran.printError("ERROR: Can't create an array and set it to a number");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
		else
		{
			toConvert = "";
			part1 = "";
			larsStatementTail();
		}
	}
	else if (token.getType() == IF_T)
	{
		token = scanner.getToken();
		parse_expr();
		if (token.getType() == THEN_T)
		{
			tran.translateIf(toConvert);
			toConvert = "";
			token = scanner.getToken();
			larsStatement();
		}
		else
		{
			tran.printError("ERROR: Expected [then]");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
	}
	else if (token.getType() == FOR_T)
	{
		token = scanner.getToken();
		parse_expr();
		if (token.getType() == TIMES_T)
		{
			token = scanner.getToken();
			if (token.getType() == DO_T)
			{
				tran.translateFor(toConvert);
				toConvert = "";
				token = scanner.getToken();
				larsStatement();
			}
			else
			{
				tran.printError("ERROR: Expected [do]");
				//scanner.printCurrentLine();
				//cin.get();
				//exit(1);
			}
		}
		else
		{
			tran.printError("ERROR: Expected [times]");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
	}
	else if (token.getType() == SAY_T)
	{
		token = scanner.getToken();
		followSay();
	}
	else if (token.getType() == EOF_T)
		return;
	else
	{
		tran.printError("ERROR: Expected a beginning statement.");
		//scanner.printCurrentLine();
		//cin.get();
		//exit(1);
	}
}

void parseClass::larsStatementTail()
{
	if (token.getType() == COMMA_T)
	{
		token = scanner.getToken();
		larsStatement();
	}
	else if (token.getType() == EOF_T)
	{
		return;
	}
	else
	{
		tran.printError("ERROR: Need a [,] to seperate statements");
		//scanner.printCurrentLine();
		//cin.get();
		//exit(1);
	}
}

void parseClass::arrayStatement()
{
	if (token.getType() == LBRACK_T)
	{
		token = scanner.getToken();
		//cout << "WHY" << endl;
		if (token.getType() == NUM_T || token.getSubtype() == VAR_ST)
		{
			parse_expr();
			//tran.translateArray(part1, toConvert);
			part2 += toConvert;
			toConvert = "";
			//part1 = "";
		}
		else if (token.getType() == RBRACK_T)
		{
			tran.translateEmptyArray(part1);
			token = scanner.getToken();
			return;
		}
		else
		{
			tran.printError("ERROR: Expected valid expression");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
	}
	else
	{
		tran.printError("ERROR: Expected array statement");
		//scanner.printCurrentLine();
		//cin.get();
		//exit(1);
	}
}

void parseClass::followArray()
{
	if (token.getType() == COMMA_T)
	{
		token = scanner.getToken();
		if (token.getType() == E)
		{
			token = scanner.getToken();
			followArray();
		}
		else if (token.getType() == NUM_T || token.getSubtype() == VAR_ST)
		{
			parse_expr();
			part2 += toConvert;
			followArray();
		}
		else
		{
			tran.printError("ERROR: Expected a valid expression");
			//scanner.printCurrentLine();
			//cin.get();
			//exit(1);
		}
	}
	else if (token.getType() == RBRACK_T)
	{
		token = scanner.getToken();
		return;
	}
	else
	{
		return;
	}
}

void parseClass::followSay()
{
	if (token.getType() == STRING_T)
	{
		part1 = token.lexeme;
		tran.translateSay(part1);
		part1 = "";
		token = scanner.getToken();
		if (token.getType() == COMMA_T)
		{
			larsStatementTail();
		}
		else
		{
			return;
		}
	}
	else
	{
		tran.printError("ERROR: Expected a [string]");
		//scanner.printCurrentLine();
		//cin.get();
		//exit(1);
	}
}

int parseClass::compiledLines()
{
	return scanner.printLines();
}

string parseClass::p_printError(string error)
{
	return tran.printError(error);
}

string parseClass::p_printTranslation(bool c, bool j, bool p)
{
	return tran.printTranslation(c, j, p);
}

void parseClass::p_clearTranslation()
{
	tran.clearTranslations();
}
