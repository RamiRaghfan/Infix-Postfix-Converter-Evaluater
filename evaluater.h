#ifndef EVALUATER_H_INCLUDED
#define EVALUATER_H_INCLUDED

#include <bits/stdc++.h>
#include "conversion1.h"
#include "MyStack.h"

using namespace std;



struct Operand{
    char token;
    double value;
};
  


class expressionEvaluator{
public:
	Operand opArr[30];
	int opCount;

	expressionEvaluator()
	{ 
		opCount = 0;
	}

	void readOperands()
	{
		string reader;

		do{
			cin>>reader;
			opArr[opCount].token = reader[1];
			double aux = 0;

			try
			{
				aux  = stod(&reader[3]);	
			} 
			catch(...)
			{
				cout<<"Error parsing input!"<<endl;
			}

			opArr[opCount].value = aux;

			opCount++;

		}while(reader != "00");
	}


	void showOperands()
	{
		int i = 0;
		while(i < opCount-1)
		{
			cout << "(" <<opArr[i].token <<","<<opArr[i].value<<")"<<endl;
			i++;
		}
	}


	double applyOp(int a, int b, char op)
	{ 
		switch(op)
		{ 
			case '+': return a + b; 
			case '-': return a - b; 
			case '*': return a * b; 
			case '/': return a / b;
		} 

		return DBL_MIN;
	} 


	double evaluateInfix(string expression){ 
	exprConverter aux;

	// stack to store integer values. 
	Stack<double> values; 
	
	// stack to store operators. 
	Stack<char> ops; 

	

	int i; 
	for(i = 0; i < expression.length(); i++){ 
		
		Operand opr;

		if(expression[i] == '(')
		{ 
			ops.push(expression[i]); 
		} 
		

		else if(aux.isOperand(expression[i]))
		{ 
			double val = 0; 
			opr = getOperand(expression[i]);
			if(opr.token == '?') 
			{
				cout<<"Error, operand " << expression[i] << " is not defined!" << endl;
				break;
			}
			
			values.push(opr.value); 
		} 
		
		// Closing brace encountered, solve 
		// entire brace. 
		else if(expression[i] == ')') 
		{ 
			while(!ops.isEmpty() && ops.peek() != '(') 
			{ 
				double val2 = values.peek(); 
				values.pop(); 
				
				double val1 = values.peek(); 
				values.pop(); 
				
				char op = ops.peek(); 
				ops.pop(); 
				
				values.push(applyOp(val1, val2, op)); 
			} 
			
 
			if(!ops.isEmpty()) 
			{
				ops.pop(); 
			}
		} 
		
		// Current token is an operator. 
		else
		{ 
			while(!ops.isEmpty() && aux.prcd(ops.peek()) 
								>= aux.prcd(expression[i])){ 
				double val2 = values.peek(); 
				values.pop(); 
				
				double val1 = values.peek(); 
				values.pop(); 
				
				char op = ops.peek(); 
				ops.pop(); 
				
				values.push(applyOp(val1, val2, op)); 
			} 
 
			ops.push(expression[i]); 
		} 
	} 
	
	while(!ops.isEmpty()){ 
		double val2 = values.peek(); 
		values.pop(); 
				
		double val1 = values.peek(); 
		values.pop(); 
				
		char op = ops.peek(); 
		ops.pop(); 
				
		values.push(applyOp(val1, val2, op)); 
	} 
	
	// Top of 'values' contains result, return it. 
	return values.peek(); 
} 

double evaluatePrefix(string expression)
{
	Stack<double> calculator;
	size_t n = expression.size();
	exprConverter aux;

 
	for(int i = expression.size(); i >= 0; i--)
	{
		char c = expression[i];
		Operand opr;

		if( aux.isOperand(c) )
		{
			opr = getOperand(c);
			if(opr.token == '?') 
			{
				cout << "Error, operand: " << c << "is not defined!"<<endl;
				break;
			}

			calculator.push(opr.value);
		}

		else if(aux.isOperator(c))
		{
			double value1 = calculator.pop();
			double value2 = calculator.pop();

			calculator.push(applyOp(value1, value2, c));
		}
	}

	return calculator.peek();
}


	Operand getOperand(char token)
	{
		for(int i = 0; i < opCount; i++)
		{
			if(token == opArr[i].token)
			{
				return opArr[i];
			}
		}

		Operand x;
		x.token = '?';

		return x;
	}

	~expressionEvaluator(){}
};

#endif