#include <iostream>
#include "conversion1.h"


int main(){

	exprConverter converter;

	cout<<endl<<endl;
	
	string expr1 = "A+B(C-D)";
	string expr2 = "{(A+B)(C*[D-E])-F}/G";
	string expr3 = "*-A/BC-/AKL";
	string expr4 = "+AB-CD";

	cout << expr1 << "\t\t---To prefix--> "<< converter.infixToPrefix(expr1) << endl<<endl;
	cout << expr2 << "\t---To prefix--> "<< converter.infixToPrefix(expr2) << endl<<endl;
	cout<<"-------------------------------------"<<endl;
	cout << expr3 << "\t----To infix--> "<< converter.prefixToInfix(expr3) << endl<<endl;
	cout << expr4 << "\t\t----To infix--> "<< converter.prefixToInfix(expr4) << endl<<endl;	

	// converter2.prefixToInfix();
	// converter2.showConversion();


}