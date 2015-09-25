
#include "stdafx.h"
#include "pstack.h"
#include <string>
#include <ctype.h>

pStackClass::pStackClass()
{
	top = NULL;
}

void pStackClass::push(tokenClass theToken)
{
	StackCell *tempCell = new StackCell;
	tempCell->next = top;
	top = tempCell;
	tempCell->type = theToken.getType();
	tempCell->subtype = theToken.getSubtype();
}

int pStackClass::pop()
{
	if (top == NULL)
	{
		cout << "Stack is empty";
		return NULL;
	}
	StackCell *first = top;
	int val;
	if (first->type == MULOP_T || first->type == ADDOP_T || first->type == RELOP_T)
		val = first->subtype;
	else
		val = first->type;
	top = first->next;
	delete first;
	return val;
}

int pStackClass::returnTopMostTerminal()
{
	int val;
	StackCell *tempCell = new StackCell;
	tempCell = top;
	tempCell->type = top->type;
	while (tempCell->type == E)
	{
		tempCell = tempCell->next;
	}
	val = tempCell->type;
	return val;
}

bool pStackClass::isThereATerminalOnTop()
{
	if (top == NULL)
	{
		cout << "Top is NULL" << endl;
		return false;
	}
	if (top->type == E)
		return false;
	else
		return true;
}