//
//  StrangeCalculator.cpp
//  CS201 HW4
//
//  Created by Gökberk Keskinkılıç on 10.05.2021.
//

#include "StrangeCalculator.h"
#include "Stack.h"
#include "DoubleStack.h"
#include "string"
#include <stdio.h>
#include <iostream>
using namespace std;

/**
 @brief Method to convert infix expression to prefix
 */
string infix2prefix( const string exp ){
    string infix, output;
    Stack myStack = Stack();
    
    // 1) reverse the infix
    infix = reverse( exp);
    // 2) adding parantheses to both ends bc this is how I implemented to make sure to empty stacks
    infix = ')' + infix + '(';
    // 3) converting it kind of a postfix, but paranthese handling is different
    for ( int i = 0; i < infix.length(); i++){
        char c = infix[i];
        // If it is operand, add it to output.
        if ( isdigit( c))
            output += c;
 
        // If it is ‘)‘, push to stack, since it is reversed infix expression
        else if ( c == ')')
            myStack.push(')');
 
        // If it is ‘(’, pop and add it to output from the stack until reaching ')‘.
        else if (c == '(') {
            while (myStack.getTop() != ')') {
                char tmp;
                myStack.getTop(tmp);
                output += tmp;
                myStack.pop();
            }
            // Remove ')' from the stack
            myStack.pop();
        }
        // It is operator
        else {
            while( precedence( c) < precedence( myStack.getTop()) ){
                char tmp;
                myStack.getTop(tmp);
                output += tmp;
                myStack.pop();
            }
                // Push current Operator on stack
                myStack.push( c);
        }
    }
    // 4) reverse and print
    return reverse( output);

}

/**
 @brief Method to calculate prefix expression's value
 */
double evaluatePrefix( const string exp ){
    string tmp = reverse(exp);
    DoubleStack dst = DoubleStack();
    for( int i = 0; i < tmp.length(); i ++){
        char c = tmp[i];
        // c is an operand
        if ( isdigit( c) ){
            dst.push( c - '0'); // subtract 0 to get char's original value
        }
        // c is an operator
        else{
            double c1, c2, res = 0;
            dst.pop( c1);
            dst.pop( c2);
            if( c == '+')
                res = c1 + c2;
            else if( c == '-')
                res = c1 - c2;
            else if( c == '*')
                res = c1 * c2;
            else if( c == '/')
                res = c1 / c2;
            dst.push( res);
        }
    }
    double output;
    dst.pop( output);
    return output;
}

/**
 @brief Method to check symmetry
 */
bool isBalancedInfix( const string exp ){
    Stack st = Stack();
    for( int i = 0; i < exp.length(); i++ ){
        if( exp[i] == '(' )
            st.push( exp[i]);
        else if ( exp[i] == ')' ){
            if ( !st.isEmpty())
                st.pop();
            else
                return false;
        }
    }
    return st.isEmpty();
}

/**
 @brief Method to reverse the infix expression
 */
string reverse( string str){
    string tmp = str;
    int n = (int)(tmp.length());
  
    for (int i = 0; i < n / 2; i++)
        swap(tmp[i], tmp[n - i - 1]);
    
    return tmp;
}

/**
 @brief Method to check precedence
 */
int precedence (char ch){
    if( ch == '+' || ch == '-')
        return 1;
    else if( ch == '*' || ch == '/')
        return 2;
    else
        return -1;
}

/**
 @brief Method to prompt a message to user get input
 */
void evaluateInputPrefixExpression( ){
    string exp;
    cout << "Enter an infix expression: " << endl;
    
    getInput: getline( cin, exp);
    
    //exp.erase( remove( exp.begin(), exp.end(), ' '), exp.end());
    cout<<exp;
    if(exp.length() != 0){
        if ( isBalancedInfix( exp ) ){
            cout << "\nprefix of: " << exp << " is: " << infix2prefix( exp ) << endl;
            cout << "\nresult of: " << exp << " is: " << evaluatePrefix( infix2prefix( exp ) ) << endl;
        }
        else{
            cout << "Expression is not balanced in terms of parantheses usage. Please check your input and try again!\nNew input: " << endl;
            goto getInput;
        }
    }
    else{
        cout << "You haven't typed in anything!\nNew input: " << endl;
        goto getInput;
    }
}
