#include<iostream>
#include<stdlib.h>  

using namespace std;

typedef struct pair_num{
  int one,two;  
}pair;

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

class new_stack: public Stack2
{
    public:
        void push(struct pair_num);
        struct pair_num pop();         
};

void new_stack::push(struct pair_num p){
    this->Stack2::push(p.one);
    this->Stack2::push(p.two);
}

struct pair_num new_stack::pop(){
    struct pair_num p;
    p.two=this->Stack2::pop();
    p.one=this->Stack2::pop();   
    return p;
} 


int main(int argc, char *argv[]){
    new_stack ns;
    struct pair_num p1;
    char ch=',';
    cout<<"Enter data to push a,b: ";
    cin>>p1.one>>ch>>p1.two;
    ns.push(p1);
    cout<<"\nData pushed";
    struct pair_num p2;
    p2=ns.pop();
    cout<<"\nDat-a poped: "<<p2.one<<","<<p2.two;
    return 0;
}
