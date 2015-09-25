#include "stdafx.h"
#include "table.h"
#include <string>
#include <ctype.h>

tableClass::tableClass()
{
	//top = NULL;
}

tableCell::tableCell()
{
	firstSymbol = NULL;
	nestLevel = 0;
	nextOffset = 0;
}
symbolCell::symbolCell()
{
	next = NULL;
}

symbolCell* tableClass::tableLookup(string Lex)
{
	symbolCell *tempSymbol = top->firstSymbol;

	if (tempSymbol != NULL)
	{
		string temp;
		while (tempSymbol)
		{
			temp = tempSymbol->symbolName;
			if (_stricmp(Lex.c_str(), temp.c_str()) == 0)
			{
				return tempSymbol;
			}
			tempSymbol = tempSymbol->next;
		}
		return NULL;
	}
	else
		return NULL;
}

void tableClass::tableAddVar(string Lex, int Kind, int Type)
{
	symbolCell *tempSymbol = top->firstSymbol;

	if (tempSymbol != NULL)
	{
		string temp;
		while (tempSymbol)
		{
			temp = tempSymbol->symbolName;
			if (_stricmp(Lex.c_str(), temp.c_str()) == 0)
			{
				tempSymbol->symbolKind = Kind;
				tempSymbol->symbolType = Type;
				tempSymbol->symbolChange = "Variable Changed";
			}
			tempSymbol = tempSymbol->next;
		}
		return;
	}
	//else
		//cout << "ERROR: Could not find the variable '" << Lex << "' in the table. Please double check your variable." << endl;
}

void tableClass::tableAddFunct(string Lex)
{
	symbolCell *tempCell = new symbolCell;
	tempCell->next = top->firstSymbol;
	tempCell->symbolName = Lex;
	tempCell->symbolNestLevel = 0;
	tempCell->symbolNextOffset = top->nextOffset;
	tempCell->symbolChange = "New Function";
	top->nextOffset++;
	top->firstSymbol = tempCell;
}

void tableClass::tableAddTemp(string temp, int type)
{
	symbolCell *tempCell = new symbolCell;
	tempCell->next = top->firstSymbol;
	tempCell->symbolName = temp;
	tempCell->symbolNestLevel = 0;
	tempCell->symbolType = type;
	tempCell->symbolNextOffset = top->nextOffset;
	top->nextOffset++;
	top->firstSymbol = tempCell;
}

void tableClass::tableDelTemps()
{
	symbolCell *tempSymbol = top->firstSymbol;
	if (tempSymbol != NULL)
	{
		string tempString;
		tempString = tempSymbol->symbolName;
		while (tempString[0] == '$')
		{
			symbolCell *tempToDel = tempSymbol;
			top->nextOffset--;
			tempSymbol = tempSymbol->next;
			top->firstSymbol = tempSymbol;
			delete tempToDel;
			tempString = tempSymbol->symbolName;
		}
	}
}

void tableClass::fillTable()
{
	string fill = "abcdefghijklmnopqrstuvwxyz";
	symbolCell *tempCell = new symbolCell;
	tempCell->symbolName = fill[0];
	tempCell->symbolNestLevel = 0;
	tempCell->symbolKind = VAR_ST;
	tempCell->symbolType = NUM_T;
	tempCell->symbolNextOffset = 0;
	tempCell->symbolChange = "Empty";
	top->nextOffset = 1;
	top->firstSymbol = tempCell;
	tempCell->next = NULL;
	for (int i = 1; i < fill.length(); i++)
	{
		symbolCell *tempCell = new symbolCell;
		tempCell->next = top->firstSymbol;
		tempCell->symbolName = fill[i];
		tempCell->symbolNestLevel = 0;
		tempCell->symbolKind = VAR_ST;
		tempCell->symbolType = NUM_T;
		tempCell->symbolNextOffset = top->nextOffset;
		tempCell->symbolChange = "Empty";
		top->nextOffset++;
		top->firstSymbol = tempCell;
	}
}

void tableClass::tablePrint()
{
	cout << "**********************************" << endl;
	
	symbolCell *printSymbol = top->firstSymbol;

	if (printSymbol != NULL)
	{
		while (printSymbol)
		{
			cout << printSymbol->symbolName << ": " << printSymbol->symbolChange << endl;
			printSymbol = printSymbol->next;
		}
		cout << "**********************************" << endl;
		return;
	}
}