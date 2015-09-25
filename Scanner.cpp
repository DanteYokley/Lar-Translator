
#include "StdAfx.h"
#include "FILEMNGR.H"
#include "Scanner.h"
#include "GENERAL.H"
#include <string>
#include <ctype.h>

scannerClass::scannerClass()
{
	theLexeme = "";
}

tokenClass::tokenClass()
{

}

void scannerClass::closeFile()
{
	theFile.closeSourceProgram();
}

int scannerClass::printLines()
{
	return theFile.numLinesProcessed();
}

void tokenClass::setToken(int s, int st, string l)
{
	tokenType = s;
	tokenSubtype = st;
	lexeme = l;
}

void tokenClass::display()
{
	cout << lexeme + "     ";
	if (tokenType == 0)
		cout << "RELOP_T     ";
	else if (tokenType == 1)
		cout << "ASSIGN_T     ";
	else if (tokenType == 2)
		cout << "ADDOP_T     ";
	else if (tokenType == 3)
		cout << "MULOP_T     ";
	else if (tokenType == 4)
		cout << "COMMA_T     ";
	else if (tokenType == 5)
		cout << "IDENT_T     ";
	else if (tokenType == 8)
		cout << "METH_T     ";
	else if (tokenType == 99)
		cout << "EOF_T";
	else if (tokenType == 11)
		cout << "LBRACK_T     ";
	else if (tokenType == 12)
		cout << "RBRACK_T     ";
	else if (tokenType == 19)
		cout << "NUM_T     ";
	else if (tokenType == 22)
		cout << "STRING_T     ";
	else if (tokenType == 25)
		cout << "LPAREN_T     ";
	else if (tokenType == 26)
		cout << "RPAREN_T     ";
	else if (tokenType == 28)
		cout << "DO_T     ";
	else if (tokenType == 29)
		cout << "WHILE_T     ";
	else if (tokenType == 30)
		cout << "THEN_T     ";
	else if (tokenType == 32)
		cout << "TIMES_T     ";
	else if (tokenType == 33)
		cout << "IF_T     ";
	else if (tokenType == 34)
		cout << "ELSE_T     ";
	else if (tokenType == 38)
		cout << "SAY_T     ";
	else if (tokenType == 53)
		cout << "BOOL_T     ";
	else if (tokenType == 24)
		cout << "E";
	if (tokenSubtype == 9)
		cout << "LESS_ST" << endl;
	else if (tokenSubtype == 10)
		cout << "GREAT_ST" << endl;
	else if (tokenSubtype == 15)
		cout << "ASSIGN_ST" << endl;
	else if (tokenSubtype == 16)
		cout << "EQUAL_ST" << endl;
	else if (tokenSubtype == 17)
		cout << "ADD_ST" << endl;
	else if (tokenSubtype == 18)
		cout << "DIV_ST" << endl;
	else if (tokenSubtype == 20)
		cout << "MULT_ST" << endl;
	else if (tokenSubtype == 21)
		cout << "SUB_ST" << endl;
	else if (tokenSubtype == 23)
		cout << "MISC_ST" << endl;
	else if (tokenSubtype == 6)
		cout << "VAR_ST" << endl;
	else if (tokenSubtype == 13)
		cout << "ARR_ST" << endl;
	else if (tokenSubtype == 7)
		cout << "FUNCT_ST" << endl;
}

int scannerClass::getNextState(int row, char ch)
{
	static int table[4][21] = {
		2, 3, 2, 0, 0, 150, 104, 105, 106, 120, 121, 123, 124, 125, 126, 122, 107, 128, 128, 1, 151,
		1, 1, 1, 152, 1, 115, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 101, 151,
		2, 2, 2, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 151,
		119, 3, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119
	};
	int col;
	if (isalpha(ch))
		col = 0;
	else if (isdigit(ch))
		col = 1;
	else if (ch == '_')
		col = 2;
	else if (ch == '\n')
		col = 4;
	else if (isspace(ch))
		col = 3;
	else if (ch == EOF)
		col = 5;
	else if (ch == '=')
		col = 6;
	else if (ch == '<')
		col = 7;
	else if (ch == '>')
		col = 8;
	else if (ch == '+')
		col = 9;
	else if (ch == '-')
		col = 10;
	else if (ch == '(')
		col = 11;
	else if (ch == ')')
		col = 12;
	else if (ch == '[')
		col = 13;
	else if (ch == ']')
		col = 14;
	else if (ch == '*')
		col = 15;
	else if (ch == '/')
		col = 16;
	else if (ch == ',')
		col = 17;
	else if (ch == '?')
		col = 18;
	else if (ch == '"')
		col = 19;
	else
		col = 20;
	return(table[row][col]);
}

int tokenClass::getType()
{
	return tokenType;
}

int tokenClass::getSubtype()
{
	return tokenSubtype;
}

tokenClass scannerClass::getToken()
{
	int state = 0;
	char input;
	tokenClass myToken; 
	setExpressionStatus(true);
	do{
		input = theFile.getNextChar();
		theLexeme += input;
		state = getNextState(state, input);
		switch (state)
		{
		case 0:
			theLexeme = "";
			break;
		case 101:
			if ((theLexeme.length() - 2) > 50)
			{
				cout << "ERROR: STRING TOO LONG ";
				theFile.printCurrentLine();
				cout << theLexeme;
				theLexeme = "";
				state = 0;
				theFile.closeSourceProgram();
				cin.get();
				exit(0);
			}
			myToken.setToken(STRING_T, MISC_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 103:
			theFile.pushBack();
			theLexeme.erase(theLexeme.length() - 1, 1);
			if ((theLexeme.length()) > 12)
			{
				cout << "ERROR: IDENTIFIER TOO LONG ";
				theFile.printCurrentLine();
				cout << theLexeme;
				theLexeme = "";
				state = 0;
				theFile.closeSourceProgram();
				cin.get();
				exit(0);
			}
			if ((theLexeme.length()) == 1)
			{
				myToken.setToken(IDENT_T, VAR_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			if (_stricmp(theLexeme.c_str(), "do") == 0)
			{
				myToken.setToken(DO_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (_stricmp(theLexeme.c_str(), "while") == 0)
			{
				myToken.setToken(WHILE_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (_stricmp(theLexeme.c_str(), "for") == 0)
			{
				myToken.setToken(FOR_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (_stricmp(theLexeme.c_str(), "times") == 0)
			{
				myToken.setToken(TIMES_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (_stricmp(theLexeme.c_str(), "then") == 0)
			{
				myToken.setToken(THEN_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (_stricmp(theLexeme.c_str(), "if") == 0)
			{
				myToken.setToken(IF_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (_stricmp(theLexeme.c_str(), "say") == 0)
			{
				myToken.setToken(SAY_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (theLexeme == ",")
			{
				myToken.setToken(COMMA_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else
			{
				myToken.setToken(IDENT_T, FUNCT_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			break;
		case 104:
			myToken.setToken(ASSIGN_T, EQUAL_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 105:
			myToken.setToken(RELOP_T, LESS_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 106:
			myToken.setToken(RELOP_T, GREAT_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 107:
			myToken.setToken(MULOP_T, DIV_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 108:
			myToken.setToken(METH_T, ARR_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 109:
			myToken.setToken(METH_T, ARR_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 110:
			cout << "ERROR: IMPROPER ARRAY STATEMENT ";
			theFile.printCurrentLine();
			cout << theLexeme;
			theLexeme = "";
			state = 0;
			theFile.closeSourceProgram();
			cin.get();
			exit(0);
		case 113:
			cout << "UNKNOWN TOKEN: ";
			cout << theLexeme;
			theLexeme = "";
			state = 0;
			break;
		case 114:
			cout << "ERROR: FOUND ']' BEFORE '[' ";
			theFile.printCurrentLine();
			cout << theLexeme;
			theLexeme = "";
			state = 0;
			theFile.closeSourceProgram();
			cin.get();
			exit(0);
		case 115:
			cout << "ERROR: EOF found ";
			theFile.printCurrentLine();
			cout << theLexeme;
			theLexeme = "";
			state = 0;
			theFile.closeSourceProgram();
			cin.get();
			exit(0);
		case 116:
			theLexeme = "";
			state = 0;
			break;
		case 119:
			theFile.pushBack();
			theLexeme.erase(theLexeme.length() - 1, 1);
			if (theLexeme.length() > 4)
			{
				cout << "ERROR: INTEGER CONSTANT TOO LONG ";
				theFile.printCurrentLine();
				cout << theLexeme;
				theLexeme = "";
				state = 0;
				theFile.closeSourceProgram();
				cin.get();
				exit(0);
			}
			myToken.setToken(NUM_T, MISC_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 120:
			myToken.setToken(ADDOP_T, ADD_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 121:
			myToken.setToken(ADDOP_T, SUB_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 122:
			myToken.setToken(MULOP_T, MULT_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 123:
			myToken.setToken(LPAREN_T, MISC_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 124:
			myToken.setToken(RPAREN_T, MISC_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 125:
			myToken.setToken(LBRACK_T, MISC_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 126:
			myToken.setToken(RBRACK_T, MISC_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			break;
		case 150:
			myToken.setToken(EOF_T, MISC_ST, theLexeme);
			theLexeme = "";
			state = 0;
			return myToken;
			theFile.closeSourceProgram();
			break;
		case 128:
			if (theLexeme == ",")
			{
				myToken.setToken(COMMA_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (theLexeme == "?")
			{
				myToken.setToken(QUEST_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			else if (theLexeme == ".")
			{
				myToken.setToken(PERIOD_T, MISC_ST, theLexeme);
				theLexeme = "";
				state = 0;
				return myToken;
			}
			break;
		case 151:
			cout << "ERROR: UNRECOGNIZABLE SYNTAX ";
			theFile.printCurrentLine();
			cout << theLexeme;
			theLexeme = "";
			state = 0;
			theFile.closeSourceProgram();
			cin.get();
			exit(0);
		case 152:
			cout << "ERROR: STRING NOT FINISHED ";
			theFile.printCurrentLine();
			cout << theLexeme;
			theLexeme = "";
			state = 0;
			theFile.closeSourceProgram();
			cin.get();
			exit(0);
		}
	} while (1);
}

void scannerClass::printCurrentLine()
{
	theFile.printCurrentLine();
}

void scannerClass::setExpressionStatus(bool newStatus)
{
	expressionStatus = newStatus;
}

bool scannerClass::seeExpressionStatus()
{
	return expressionStatus;
}

void scannerClass::s_TableAddVar(string Lex, int Kind, int Type)
{
	theTable.tableAddVar(Lex, Kind, Type);
}

void scannerClass::s_TableAddTemp(string temp, int type)
{
	return theTable.tableAddTemp(temp, type);
}

void scannerClass::s_TableDelTemps()
{
	theTable.tableDelTemps();
}

void scannerClass::s_TableAddFunct(string Lex)
{
	theTable.tableAddFunct(Lex);
}

void scannerClass::s_FillTable()
{
	theTable.fillTable();
}

void scannerClass::s_PrintTable()
{
	theTable.tablePrint();
}

symbolCell* scannerClass::s_TableLookup(string Lex)
{
	return theTable.tableLookup(Lex);
}