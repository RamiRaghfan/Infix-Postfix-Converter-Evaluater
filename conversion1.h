#ifndef CONVERSION1_H_INCLUDED
#define CONVERSION1_H_INCLUDED

#include <iostream>
#include <cstring>
#include <algorithm>
#include "MyStack.h"

class exprConverter{

public:
	Stack<char> stk;


	exprConverter(){}


//Main functions
/*------------------------------------------------------------*/

	int prcd(char c)
	{
		int priority = -1;
		switch(c){
			
			case '^': 
			priority = 3;
			break;

			case '*':
			case '/':
			priority = 2;
			break;

			case '+':
			case '-': 
			priority = 1;

			default:
			break;
		}

		return priority;
	}

	string infixToPrefix(string infixInput)
	{


		string output;
		string input = infixInput;
		reverseCorrect(input);

		size_t n = input.size();
		int j = 0; 

		for(int i = 0; i < n; i++)
		{
			char c = input[i];


			if(isOpParantheses(c))
			{
				stk.push(c);
			}

			if(isClParantheses(c))
			{				
				while(!stk.isEmpty() && !isOpParantheses(stk.peek()) )
				{
					output += stk.pop();
				}

				char x = stk.pop();
			}

			if(isOperand(c))
			{
				output += c;

			}

			if(isOperator(c))
			{
		
				while(stk.isEmpty() && stk.peek() >= prcd(c) )
				{
					output += stk.pop();
				}

				stk.push(c);
			}

		}

		while(!stk.isEmpty())
		{
			output += stk.pop();
		}

		reverse(output.begin(), output.end());

		return output;

	}//end for infixToPostfix function

	string prefixToInfix(string input)
	{

		Stack<string> outputStack;
		string output;

		size_t n = input.size();
		for(int i = n-1; i >= 0; i--)
		{
			if(isOperator(input[i]))
			{
				string s1,s2;
				s1 = outputStack.pop();
				s2 = outputStack.pop();

				string aux = '(' + s1 + input[i] + s2 + ')';
				outputStack.push(aux);
			}

			else
				
			{
				string s;
				s = s+input[i];
				outputStack.push(string(1, input[i]));
			}
		}

		while(!outputStack.isEmpty())
		{
			output += outputStack.pop();
		}

		return output;

	}



//Auxilliary functions
/*------------------------------------------------------------*/

	bool isClParantheses(char c)
	{
		if(c == ')' || c == ']' || c == '}') return true;

		return false;
	}

	bool isOpParantheses(char c)
	{
		if(c == '(' || c == '[' || c == '{') return true;

		return false;
	}

	void reverseCorrect(string &inputStr)
	{
		reverse(inputStr.begin(), inputStr.end());

		int n = inputStr.size();
		for(int i = 0; i < n; i++)
		{
			if(inputStr[i] == '(') inputStr[i] = ')';
					else if(inputStr[i] == ')') inputStr[i] = '(';

			if(inputStr[i] == '[') inputStr[i] = ']';
					else if(inputStr[i] == ']') inputStr[i] = '[';

			if(inputStr[i] == '{') inputStr[i] = '}';
					else if(inputStr[i] == '}') inputStr[i] = '{';				
		}
	}



	int isOperand(char c)
	{
		  if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))
		  {
		  	return 1;	
		  }
		  else
		  	return 0;
	}

	int isOperator(char c)
	{
		if(c == '^' || c == '+' || c == '-' || c == '*' || c == '/') return 1;
		
		return 0;
	}
	
};

#endif