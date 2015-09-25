#include "stdafx.h" 

#include "filemngr.h"


fileManagerClass::fileManagerClass()
{
	char filename[MAXCELLSPERSTRING];

	autoPrintStatus = false;

	cout << "Enter file name to compile: ";
	cin.getline(filename, MAXCELLSPERSTRING);
	fileToCompile.open(filename);

	if (fileToCompile.fail())
	{
		cout << "Error, the source file: " << filename << " was not opened." << endl;
		cout << "Press return to end program." << endl;
		cin.get();
		exit(1);
	}
	currentLineNumber = 0;
}

int fileManagerClass::getNextChar()
{
	if ((currentLineNumber == 0) ||
		(charToReadNext == strlen(currentLine)))
	{
		if (fileToCompile.peek() == EOF)
			return (EOF);
		fileToCompile.getline(currentLine, MAXCELLSPERSTRING);
		strcat_s(currentLine, "\n");
		currentLineNumber++;
		charToReadNext = 0;
	}
	if (autoPrintStatus == true)
	{
		printCurrentLine();
	}
	return(currentLine[charToReadNext++]);
}

void fileManagerClass::pushBack()
{
	if (charToReadNext > 0)
	{
		charToReadNext -= 1;
	}
}

void fileManagerClass::printCurrentLine()
{
	cout << currentLineNumber << " - " << currentLine;
}

void fileManagerClass::setPrintStatus(bool newStatus)
{
	autoPrintStatus = newStatus;
}

int fileManagerClass::numLinesProcessed()
{
	return currentLineNumber;
}
void fileManagerClass::closeSourceProgram()
{
	fileToCompile.close();
}
