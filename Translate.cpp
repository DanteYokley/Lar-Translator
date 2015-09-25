#include <string>
#include <ctype.h>
#include "stdafx.h"
#include "Translate.h"


transClass::transClass()
{
	//toPrint[0], toPrint[1], toPrint[2], errorMessage = "";
}

void transClass::translateWhile(string translate)
{
	toPrint[0] += "C++: while (" + translate + ") {" + "\n" + "//INSERT STATEMENTS HERE" + "\n" + "}" + "\n" + "While loops in C++ are similar to those in Lars. You state that you are executing a while loop but you encase your condition within parentheses. You follow that up with your statements between two brackets. This lets the compiler know that the statements within the brackets are statements to be executed within the while loop." + "\n" + "\n";
	toPrint[1] += "Java: while (" + translate + ") {" + "\n" + "/*" + "\n" + "* INSERT STATEMENTS HERE" + "\n" + "*/" + "\n" + "}" + "\n" + "While loops in Java are similar to those in Lars. You state that you are executing a while loop but you encase your condition within parentheses. You follow that up with your statements between two brackets. This lets the compiler know that the statements within the brackets are statements to be executed within the while loop." + "\n" + "\n";
	toPrint[2] += "Python: while (" + translate + "):" + "\n" + "     #INSERT STATEMENTS HERE" + "\n" + "     #INSERT STATEMENTS HERE" + "\n" + "While loops in Python are similar to those in Lars. You state that you are executing a while loop but you encase your condition within parentheses. You follow that up with your statements after a colon. Python is a programming language with its syntax being based on spacing. This can get confusing because every statement that you want inside of a while loop must have the same space from the left of the editor." + "\n" + "\n";
	//toTranslate += "..........";
	//exit(0);
	//cin.get();
}

void transClass::translateArray(string translate, string arrayNums)
{
	toPrint[0] += "C++: int " + translate + "[] = {" + arrayNums + "};" + "\n Array declarations in C++ require more detail than Lars. You state that you are creating an array of integers (numbers) by prefacing the array name with 'int'. You follow that up with two empty brackets and an equal sign. This tells the compiler that you have created an empty array and you are ready to fill it with information. You then use two curly braces/brackets and place your array values inside just like you would do with Lars." + "\n" + "\n";
	toPrint[1] += "Java: int[] " + translate + " = {" + arrayNums + "};" + "\nArray declarations in Java require more detail than Lars. You state that you are creating an array of integers (numbers) by typing 'int'. You follow that up with two empty brackets, the name of the array, and an equal sign. This tells the compiler that you have created an empty array and you are ready to fill it with information. You then use two curly braces/brackets and place your array values inside just like you would do with Lars." + "\n" + "\n";
	toPrint[2] += "Python: " + translate + " = [" + arrayNums + "]" + "\n Array declarations in Python are incredibly similar to arrays in Lars. The only difference is that you place an equals sign in between the array name and the brackets." + "\n" + "\n";
	//cin.get();
}

void transClass::translateEmptyArray(string translate)
{
	toPrint[0] += "C++: int " + translate + "[];" + "\n Array declarations in C++ require more detail. You state that you are creating an array of integers (numbers) by prefacing the array name with 'int'. You follow that up with two empty brackets and an equal sign. This tells the compiler that you have created an empty array and you are ready to fill it with information. You then use two curly braces/brackets and place your array values inside just like you would do with Lars." + "\n" + "\n";
	toPrint[1] += "Java: int[] " + translate + ";" + "\n Array declarations in Java require more detail than Lars. You state that you are creating an array of integers (numbers) by typing 'int'. You follow that up with two empty brackets, the name of the array, and an equal sign. This tells the compiler that you have created an empty array and you are ready to fill it with information. You then use two curly braces/brackets and place your array values inside just like you would do with Lars." + "\n" + "\n";
	toPrint[2] += "Python: " + translate + "" + "\nArray declarations in Python are incredibly similar to arrays in Lars. The only difference is that you place an equals sign in between the array name and the brackets." + "\n" + "\n";
	//cin.get();
}

void transClass::translateFor(string translate)
{
	toPrint[0] += "C++: for(int i = 0; i < " + translate + "; i++) {" + "//INSERT STATEMENTS HERE" + "\n }" + "\n Initiating for loops in C++ can be confusing. You tell the compiler that you are creating a for loop and need to use three conditions to make the loop. Each condition is seperated by a semi-colon, which are used to end a statement. You first create a number for counting, create the limit/condition for the loop, and then you increment the number for counting at the end. In this case, 'i++' means that you that the 'i' variable and add 1 after each run through the loop. You once again use brackets to enclose what you want in the loop." + "\n" + "\n";
	toPrint[1] += "Java: for(int i = 0; i < " + translate + "; i++) {" + "/*" + "\n * INSERT STATEMENTS HERE" + "\n */" + "\n}" + "\n Initiating for loops in Java can be confusing. You tell the compiler that you are creating a for loop and need to use three conditions to make the loop. Each condition is seperated by a semi-colon, which are used to end a statement. You first create a number for counting, create the limit/condition for the loop, and then you increment the number for counting at the end. In this case, 'i++' means that you that the 'i' variable and add 1 after each run through the loop. You once again use brackets to enclose what you want in the loop." + "\n" + "\n";
	toPrint[2] += "Python: for x in range(0, " + translate + "):" + "\n #INSERT STATEMENTS HERE" + "\n" + "\n Initiating for loops in Python can seem simple but can get confusing. You have to use a variable in order to run this loop. You give a variable and state where you want the loop to start and how many times you want it to run. Be careful with your spacing!" + "\n" + "\n";
	//cin.get();
}

void transClass::translateIf(string translate)
{
	toPrint[0] += "C++: if(" + translate + ") {" + "\n //INSERT STATEMENTS HERE" + "\n }" + "\n If statements in C++ are just as easy as in Lars (if you can understand the brackets and semi-colons!). The difference is that you encase your condition in parentheses and encase your following statements in brackets." + "\n" + "\n";
	toPrint[1] += "Java: if(" + translate + ") {" + "\n /*" + "\n * INSERT STATEMENTS HERE" + "\n */" + "\n }" + "\n If statements in Java are just as easy as in Lars (if you can understand the brackets and semi-colons!). The difference is that you encase your condition in parentheses and encase your following statements in brackets." + "\n" + "\n";
	toPrint[2] += "Python: if" + translate + " " + "\n      #INSERT STATEMENTS HERE" + "\n Python if statements are incredibly simple, aside from the spacing. After typing your condition, you type in your statements on the next line!" + "\n" + "\n";
	//cin.get();
}

void transClass::translateSay(string translate)
{
	toPrint[0] += "C++: cout << " + translate + " << endl;" + "\n Say/Print statements in C++ are rather simple. Instead of using 'say', you use 'cout<<'. 'Cout' stands for 'console output' and that is follow by '<<' because you are pushing out a series of words. Adding 'endl' at the end creates a new line after your statement." + "\n" + "\n";
	toPrint[1] += "Java: System.out.println(" + translate + ");" + "\n Say/Print statements in Java use a command 'System.out.println' which it telling the system to output the string within the parenthese and then to print out a new line right after." + "\n" + "\n";
	toPrint[2] += "Python: print " + translate + "\n Say/Print statements in Python work in the same way that it works in Lars. The only difference is that you use 'print' instead of 'say'." + "\n" + "\n";
	//cin.get();
}

void transClass::translateStatement(string translate, string state)
{
	toPrint[0] += "C++: " + translate + " " + state + ";" + "\n Statements normally work in the same way for most languages. In C++, you just end the statement with a semi-colon to let the compiler know that you've made a statement." + "\n" + "\n";
	toPrint[1] += "Java: " + translate + " " + state + ";" + "\n Statements normally work in the same way for most languages. In Java, you just end the statement with a semi-colon to let the compiler know that you've made a statement." + "\n" + "\n";
	toPrint[2] += "Python: " + translate + " " + state + "\n Statements normally work in the same way for most languages. In Python, however, you just write in the same way you would with Lars. Just mind the spacing after!" + "\n" + "\n";
	//cin.get();
}

void transClass::translateFunction(string translate, string function)
{
	toPrint[0] += "C++: void " + translate + "() { \n" + function + ";" + "\n }" + "\n Writing a function in C++ is simple. You start off by stating what sort of function you want it to be. All of the funcitons in Lars are void funcitons, meaning that the function does not return a value of any sort. The other function types are int, double, string, and boolean. You then list the parameters you want your function to have within parentheses. You then use brackets to encase what you want your function to do." + "\n" + "\n";
	toPrint[1] += "Java: public void " + translate + "() { \n" + function + ";" + "\n }" + "\n Writing a function in Java is simple and it works similar to C++. You start off by stating whether or not you want your function to be public or private, meaning that it can or cannot be accessed by other classes (that's something else to learn on your own!). You follow that with the kind of function you want it to be. All of the funcitons in Lars are void funcitons, meaning that the function does not return a value of any sort. The other function types are int, double, string, and boolean. You then list the parameters you want your function to have within parentheses. You then use brackets to encase what you want your function to do." + "\n" + "\n";
	toPrint[2] += "Python: def " + translate + "() :" + "\n     " + function + "\n Python functions are similar to how you call functions. The only difference is that you place 'def' before the call, which tells the compiler that you are defining a function." + "\n" + "\n";
	//cin.get();
}

void transClass::translateFunctionCall(string translate)
{
	toPrint[0] += "C++: " + translate + "();" + "\n Function calls in C++ is very simple. Just write out the name of the function and end with parenthese and a semi-colon. This tells the compiler that you are calling your function that take 0 parameters." + "\n" + "\n";
	toPrint[1] += "Java: " + translate + "();" + "\n Function calls in Java is very simple. Just write out the name of the function and end with parenthese and a semi-colon. This tells the compiler that you are calling your function that take 0 parameters." + "\n" + "\n";
	toPrint[2] += "Python: " + translate + "()" + "\n Function calls in Python is very simple. Just write out the name of the function and end with parenthese and a semi-colon. This tells the compiler that you are calling your function that take 0 parameters." + "\n" + "\n";
	//cin.get();
}

string transClass::printError(string error)
{
	errorMessage += error + "\n";
	return errorMessage;
}


string transClass::printTranslation(bool c, bool j, bool p)
{
	if (c == true)
		toTranslate += toPrint[0];
	if (j == true)
		toTranslate += toPrint[1];
	if (p == true)
		toTranslate += toPrint[2];
	//toTranslate += "Come on";
	return toTranslate;
}

void transClass::clearTranslations()
{
	errorMessage, toPrint[0], toPrint[1], toPrint[2] = "";
}

