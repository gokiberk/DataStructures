//
//  DoubleStack.h
//  CS201 HW4
//
//  Created by Gökberk Keskinkılıç on 12.05.2021.
//

#ifndef DoubleStack_h
#define DoubleStack_h

#include <stdio.h>
using namespace std;


class DoubleStack{

public:
    DoubleStack();
    DoubleStack(const DoubleStack& aStack);
    ~DoubleStack();

    bool isEmpty() const;
    bool push( double newItem);
    bool pop();
    bool pop( double& stackTop);
    bool getTop( double& stackTop) const;
    char getTop() const;

private:
    struct DoubleStackNode{     // a node on the stack
        double item;                // a data item on the stack
        DoubleStackNode *next;      // pointer to next node
    };

    DoubleStackNode *topPtr;    // pointer to first node in the stack
};



#endif /* DoubleStack_h */
