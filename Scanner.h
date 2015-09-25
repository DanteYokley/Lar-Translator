#ifndef _scanner
#define _scanner

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "general.h"
#include "Table.h"
#include "FILEMNGR.H"

using namespace std;

class tokenClass
{
public:
	tokenClass();
	void display();
	int getType();
	int getSubtype();
	void setToken(int s, int st, string l);
	string lexeme;

private:
	int tokenType;
	int tokenSubtype;
};

//DOES NOT LIKE THESE CLASS INITIALIZATIONS

class scannerClass
{
public:
	scannerClass();
	tokenClass getToken();
	int getNextState(int row, char ch);
	int printLines();
	void printCurrentLine();
	void closeFile();
	void setExpressionStatus(bool newStatus);
	bool seeExpressionStatus();
	void s_TableAddFunct(string Lex);
	void s_TableAddVar(string Lex, int Kind, int Type);
	void s_TableAddTemp(string temp, int type);
	void s_TableDelTemps();
	void s_FillTable();
	void s_PrintTable();
	symbolCell* s_TableLookup(string Lex);


private:
	fileManagerClass theFile;
	string theLexeme;
	bool expressionStatus;
	tableClass theTable;
};

#endif
