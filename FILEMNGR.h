#ifndef _filemngr
#define _filemngr

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "general.h"

using namespace std;
using std::ifstream;

class fileManagerClass
{
public:
	fileManagerClass();
	int getNextChar();
	void closeSourceProgram();
	void pushBack();
	void printCurrentLine();
	void setPrintStatus(bool newStatus);
	int numLinesProcessed();

private:
	bool autoPrintStatus;
	char currentLine[MAXCELLSPERSTRING];
	int charToReadNext;
	int currentLineNumber;
	ifstream fileToCompile;
};

#endif
