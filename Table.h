#ifndef _table
#define _table

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "general.h"
//#include "filemngr.h"

using namespace std;
using std::ifstream;

class symbolCell
{
public:
	symbolCell();
	string symbolName;
	int symbolKind;
	int symbolType;
	int symbolNestLevel;
	int symbolNextOffset;
	string symbolChange;
	symbolCell *next;
};

class tableCell
{
public:
	tableCell();
	string name;
	string nestName;
	int nestLevel;
	int nextOffset;
	symbolCell *firstSymbol;
};

class tableClass
{
public:
	tableClass();
	void tableAddVar(string Lex, int Kind, int Type);
	void tableAddFunct(string Lex);
	void tableAddTemp(string temp, int type);
	void tableDelTemps();
	void fillTable();
	symbolCell* tableLookup(string Lex);
	void tablePrint();

private:
	tableCell *top = new tableCell;
};

#endif
