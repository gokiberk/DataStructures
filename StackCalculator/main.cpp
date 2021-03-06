//
//  main.cpp
//  CS201 HW4
//
//  Created by Gökberk Keskinkılıç on 6.05.2021.
//

//#include <iostream>
//using namespace std;
//#include "StrangeCalculator.h"
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    cout << "Hello, this is HW4!\n";
//
//    cout << "prefix of: 5+6*7 is: " << infix2prefix("5+6*7") << endl;
//    cout << "prefix of: 5+6*(7/2) is: " << infix2prefix("5+6*(7/2)") << endl;
//    cout << "prefix of: (5+6)*(7/2) is: " << infix2prefix("(5+6)*(7/2)") << endl;
//    cout << "prefix of: (5+6)*(7/2)-5+7*(8*2) is: " << infix2prefix("(5+6)*(7/2)-5+7*(8*2)") << endl << endl;
//
//    cout << "result of: 5+6 is: " << evaluatePrefix( infix2prefix("5+6")) << endl;
//    cout << "result of: 5+6*7 is: " << evaluatePrefix( infix2prefix("5+6*7")) << endl;
//    cout << "result of: 5+6*(7/2) is: " << evaluatePrefix(infix2prefix("5+6*(7/2)")) << endl;
//    cout << "result of: (5+6)*(7/2) is: " << evaluatePrefix( infix2prefix("(5+6)*(7/2)")) << endl;
//    cout << "result of: (5+6)*(7/2)-5+7*(8*2) is: " << evaluatePrefix(infix2prefix("(5+6)*(7/2)-5+7*(8*2)")) << endl << endl;
//
//    cout << isBalancedInfix( "((5+7" ) << endl;
//    cout << isBalancedInfix( "((5+7)))" ) << endl;
//    cout << isBalancedInfix( "(5+4" ) << endl;
//    cout << isBalancedInfix( "(5+4)*3-4*(9+8))" ) << endl; cout << isBalancedInfix( "(5+4)*3-(4*(9+8))" ) << endl;
//
//    evaluateInputPrefixExpression( );
//
//    return 0;
//}


#include <iostream>
using namespace std;
#include "StrangeCalculator.h"

int main(){
    cout << "prefix of: 9+3 is: " << infix2prefix("9+3") << endl;
    cout << "prefix of: 9-3*5 is: " << infix2prefix("9-3*5") << endl;
    cout << "prefix of: 3+2-3/(7*2) is: " << infix2prefix("3+2-3/(7*2)") << endl;
    cout << "prefix of: (4+2)/(5/3) is: " << infix2prefix("(4+2)/(5/3)") << endl;
    cout << "prefix of: (8-6)/(3*4)+4+9/(3*6) is: " << infix2prefix("(8-6)/(3*4)+4+9/(3*6)") << endl;


    cout<< "Checkpoint 1" << endl;
    cout << "result of: 9+3 is: " << evaluatePrefix( infix2prefix("9+3")) << endl;
    cout << "result of: 9-3*5 is: " << evaluatePrefix( infix2prefix("9-3*5")) << endl;
    cout << "result of: 3+2-3/(7*2) is: " << evaluatePrefix(infix2prefix("3+2-3/(7*2)")) << endl;
    cout << "result of: (4+2)/(5/3) is: " << evaluatePrefix( infix2prefix("(4+2)/(5/3)")) << endl;
    cout << "result of: (8-6)/(3*4)+4+9/(3*6) is: " << evaluatePrefix(infix2prefix("(8-6)/(3*4)+4+9/(3*6)")) << endl;

    cout << "Checkpoint 2" << endl;
    cout << isBalancedInfix( "(((4+7()(" ) << endl;
    cout << isBalancedInfix( "(()4+9/2)))" ) << endl;
    cout << isBalancedInfix( "((5+)4(" ) << endl;
    cout << isBalancedInfix( "((5+2)(*4/4*()3+8)" ) << endl;
    cout << isBalancedInfix( "(((5+4)*3-3/(4+5)))" ) << endl;


    cout << "Checkpoint 3" << endl;
    evaluateInputPrefixExpression();
    evaluateInputPrefixExpression();


    return 0;
}
