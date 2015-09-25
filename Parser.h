
#ifndef _parser
#define _parser

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "scanner.h"
#include "pstack.h"
#include "Table.h"
#include "Translate.h"
#include "general.h"

using namespace std;
using std::ifstream;

class parseClass
{
public:
	parseClass();
	void parse_expr();
	char preParse(int topTerm, int token);
	bool validStatement(int sideArray[], int count);
	void parseLars();
	void larsStatement();
	void larsStatementTail();
	void arrayStatement();
	void followSay();
	void followArray();
	int compiledLines();
	string p_printError(string error);
	string p_printTranslation(bool c, bool j, bool p);
	void p_clearTranslation();

private:
	scannerClass scanner;
	pStackClass pstack;
	bool hasPopped;
	tokenClass token;
	string toConvert = "";
	string part1, part2, part3, part4, part5;
	transClass tran;
	bool hasEnded=false;
};


#endif