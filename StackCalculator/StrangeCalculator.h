//
//  StrangeCalculator.hpp
//  CS201 HW4
//
//  Created by Gökberk Keskinkılıç on 10.05.2021.
//

#ifndef StrangeCalculator_h
#define StrangeCalculator_h

#include <stdio.h>
#include <string>
#include "Stack.h"
using namespace std;

string infix2prefix( const string exp );
double evaluatePrefix( const string exp );
bool isBalancedInfix( const string exp );
void evaluateInputPrefixExpression( );

string reverse( string str);
int precedence (char ch);

class StrangeCalculator{
    
private:
    
public:
    
};

#endif /* StrangeCalculator_h */
