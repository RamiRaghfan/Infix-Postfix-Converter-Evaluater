# Notation Conversion and Expression Evaluation Demo Project

This is a demo project for testing notation conversion algorithms and expression evaluation. A C++ compiler (g++ or an IDE) is required for this to work.

## Features

There are two driver programs included for demonstration:

- `MainConvert.cpp`: For converting between Infix and Postfix notations, and vice versa.
- `EvaluateMain.cpp`: For evaluating arithmetic expressions in infix or prefix form.

## Functions Descriptions

### convrsion1.h

#### `int isOperand(char c)`
Takes a char as input, returns 1 if the input argument is an "operand" (an English alphabet character).

#### `int isOperator(char c)`
Takes a char as input, returns 1 if the input argument is an (arithmetic) operator, returns 0 otherwise.

#### `int prcd(char c)`
Takes input as char (specifically an arithmetic operator), returns a number that represents the precedence of an operator over others. The higher the precedence, the higher the number returned.

#### `string infixToPrefix(string infixInput)`
Converts an infix arithmetic expression to its prefix notation using a stack. This algorithm is compatible with all types of parentheses, and spaces do not affect it.

*Example:*
Input: `A+B(C-D)`  
Output: `+AB-CD`  

#### `string prefixToInfix(string input)`
Converts a prefix expression to an infix expression. Spaces in the input are always ignored.

*Example:*
Input: `+AB-CD`  
Output: `(A+B)(C-D)`  

### Helper Functions

#### `void reverseCorrect(string &inputStr)`
Reverses a string using C++ STL and flips every occurrence of any parenthesis.

#### `bool isClParantheses(char c)`
Returns `true` if the passed argument is a closed parenthesis, `false` otherwise.

#### `bool isOpParantheses(char c)`
Returns `true` if the passed argument is an open parenthesis, `false` otherwise.

#### `int isOperand(char c)`
Returns `true` if the passed argument is an operand, `false` otherwise.

#### `int isOperator(char c)`
Returns `true` if the passed argument is an arithmetic operator, `false` otherwise.

## evaluater.h Functions Descriptions

### `void readOperands()`
Reads operands and their values as input in the form `(Token, Value)` and stores them for later use. Input stops when " 00 " is entered.

### `void showOperands()`
Displays all stored operands and their values in the form `(Token, Value)`.

### `double applyOp(int a, int b, char op)`
Applies an arithmetic operation (represented by 'op') to two integers.

### `double evaluateInfix(string expression)`
Evaluates an infix expression using two stacks. The algorithm requires parentheses between pairs of operands.

### `double evaluatePrefix(string expression)`
Evaluates a prefix expression by traversing the string in reverse, applying operators to operands stored in a stack.

### `Operand getOperand(char token)`
Searches for the operand token in the Operand structure and returns it. If not found, returns ('?', Arbitrary Value).
