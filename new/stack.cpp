#include <iostream>
#include<stdlib.h>
using namespace std;

 //for exit()
////////////////////////////////////////////////////////////////
class Stack{
    protected: 
        enum { MAX = 3 };
        int st[MAX];
        int top;
    public:
        Stack(){ top = -1; }
        void push(int var)
        { 
            st[++top] = var; 
        }
        int pop()
        { 
            return st[top--]; 
        }
};

class Stack2 : public Stack
{
    public:
    void push(int var)
    {
        if(top >= MAX-1)
        { 
            cout << "Error: stack is full"; 
            exit(1);
            
        }
        Stack::push(var);
    }
    int pop()
    {
        if(top < 0)
        { 
            cout << "Error: stack is empty"; 
            exit(1);
           
        }
        return Stack::pop();
    }
};

int main(int argc,char *argv[]){
}

