------------------------------------------------------------------------------
This is a demo project to test notation conversion algortithms, and expression evaluation.
C++ COMPILER g++ or IDE REQUIRED FOR THIS TO WORK.
------------------------------------------------------------------------------
------------------------------------------------------------------------------

There are two already written driver programs for demonstration.
MainConvert.cpp -- for converting between Infix Postfix notations, and vice versa.
EvaluateMain.cpp -- for evaluating arithmetic expressions in infix or prefix form.


Functions descriptions:
convrsion1.h

int isOperand(char c) 
Takes a char as input, returns 1 if the input agrument is an "operand", 
AKA an English alphabet character
------------------------------------------------------------------------------
int isOperator(char c)
Takes a char as input, returns 1 if input argument is an (arithmetic) operator, 
returns 0 otherwise
------------------------------------------------------------------------------

int prcd(char c)
Takes input as char, specifically an arithmetic operator,
returns a number that represents the precedence of an operator over others,
the higher precedence the higher the number returned
------------------------------------------------------------------------------

string infixToPrefix(string infixInput)
Takes input as a string, an infix arithmetic expression, for instance:

>> A+B(C-D)

Is an infix expression, it converts it to its prefix notation using stack, 
the conversion algorithm is a very standard one.

Result of previous example as input

>> +AB-CD

This alrgorithm  is compatible with all types of parantheses, 
and spaces do not affect it*

*further testing required for limits
------------------------------------------------------------------------------

string prefixToInfix(string input)

Takes input as a string, a prefix expression, for instance:

>> +AB-CD

Is a prefix expression, using a standard algorithm with stacks (similar as previous function),
it converts it to an infix expression.

>> (A+B)(C-D)

Spaces do not affect the input, because they are always ignored thanks to some helper functions

------------------------------------------------------------------------------
------------------------------------------------------------------------------


void reverseCorrect(string &inputStr)
	
Takes a string as a input and reverses it using C++ STL, after it has been reversed, 
it is traversed character by character and every occurrance of any parathasis will flip this parathesis' open side.


------------------------------------------------------------------------------

The following are two helper functions that take a character (char) as input and returns bool.

bool isClParantheses(char c)  : returns true if the passed argument is a closed parathesis,
returns false otherwise.

bool isOpParantheses(char c)  : returns true if the passed argument is an open parathesis, 
returns false otherwise.

------------------------------------------------------------------------------

The following are two helper functions that take a character (char) as input and returns an int.

int isOperand(char c)  : returns true if the passed argument is an operand,
false otherwise

int isOperator(char c) : returns true if the passed argument is an arithmetic operator,
false otherwise.

------------------------------------------------------------------------------
END OF conversion.h


Function descriptions for evaluater.h

void readOperands()

This function waits for an operand and its value as input in console with this form:
>> (Token, Value)
then stores it in a structure for later use.

Each newline will make the program wait for new input until " 00 " is entered, 
the reading will then stop.
------------------------------------------------------------------------------

void showOperands()

Displays on the console all the stored operands and their associated value in this form

>>(Token, Value)
------------------------------------------------------------------------------


double applyOp(int a, in b, char op)

Takes 2 integers and 1 character as input, the character represents arithmetic operation
depending on the operator, the operation of 'op' will be applied
------------------------------------------------------------------------------

double evaluateInfix(string expression)

Takes a string as input, then traverses it character by character and evaluates the 
expression using 2 stacks, for operands, and for operators. 

The algorithm strictly needs parantheses between pairs of operands to work, 
because they are used as a way for the program to know when to stop reading the expression, 
and to evaluate one pair and continue with it.  

------------------------------------------------------------------------------

double evaluatePrefix(string expression)

Takes a string expression as input, then traverses the string in reverse character by character,
storing any operand in a stack, and when an operator is read, two operands are taken from the stack and applied the operator that was read, the result is stored back in the operand stack.
This repeats until the stack is empty and the result will be sitting on top of the stack.

------------------------------------------------------------------------------


Operand getOperand(char token)

Using a char as an argument, it will search in the Operand structure for the operand token

>>(Token, Value)

If found, it will return a copy of the pair (Token, Value). 
If not found, will return ('?', Arbitrary Value).

------------------------------------------------------------------------------



