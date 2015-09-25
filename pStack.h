
#ifndef _pstack
#define _pstack

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "scanner.h"
#include "general.h"

using namespace std;
using std::ifstream;

class StackCell
{
public:
	int type;
	int subtype;
	StackCell *next;

private:
	//scannerClass scanner;
};

class pStackClass
{
public:
	pStackClass();
	void push(tokenClass theToken);
	int pop();
	bool isThereATerminalOnTop();
	int returnTopMostTerminal();

private:
	StackCell *top;
};

#endif