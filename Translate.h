
#ifndef _translate
#define _translate

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "general.h"

using namespace std;
using std::ifstream;

class transClass
{
public:
	transClass();
	void translateWhile(string translate);
	void translateIf(string translate);
	void translateArray(string translate, string arrayNums);
	void translateEmptyArray(string translate);
	void translateFor(string translate);
	void translateSay(string translate);
	void translateStatement(string translate, string state);
	void translateFunction(string translate, string function);
	void translateFunctionCall(string translate);
	string printError(string error);
	//void testFunct();
	string printTranslation(bool c, bool j, bool p);
	void clearTranslations();
	//string toPrint[3] = { "", "", "" };


private:
	//string toPrint = "";
	string toPrint[3];
	string toTranslate = "";
	string errorMessage = "";
};


#endif