#include "evaluater.h"
#include <iostream>

int main()
{
	cout<<"Enter some operands, to finish enter 00"<<endl;
	expressionEvaluator evaluator;
	evaluator.readOperands();

	cout << "You entered: "<<endl;
	evaluator.showOperands();

	double result;

	string expr;

	cout<<"Enter a Prefix expression"<<endl;
	cin>>expr;
	result = evaluator.evaluatePrefix(expr);
	cout << expr <<" = " << result << endl;

	cout<<"Enter another Prefix expression"<<endl;
	cin>>expr;
	result = evaluator.evaluatePrefix(expr);
	cout << expr <<" = " << result << endl;


	cout<<"Enter an Infix expression"<<endl;
	cin>>expr;
	result = evaluator.evaluateInfix(expr);
	cout << expr <<" = " << result << endl;

	cout<<"Enter another Infix expression"<<endl;
	cin>>expr;
	result = evaluator.evaluateInfix(expr);
	cout << expr << "= " << result << endl;


}