
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    top=-1;
}
void Stack::push(char x)
{
    if(top<MAX)
        arr[++top] = x;
//    else
//        cout<<"Stack is full\n";
}

void Stack::pop()
{
    if (top > 0)
    {
        top--;
    }

}

char Stack::tip()
{
    if (top < 0)
    {
        //cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = arr[top];
        return x;
    }
}
bool Stack::isfull()
{
    return (top = MAX-1);
}
bool Stack::isEmpty()
{
    return (top==-1);
}
