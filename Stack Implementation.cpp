#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <chrono>
using namespace std::chrono;

/* implementation of stack */

class stacks{
    public:
    int data;
    stacks* link;
};

void push(int new_data,stacks** top){
    stacks* new_top=new stacks();
    new_top->data=new_data;
    new_top->link=*top;
    *top=new_top;
    cout<<new_data<<" pushed to stack"<<endl;
}

void pop(stacks** top){
    if(*top==NULL){
        cout<<"the stack is empty"<<endl;
    }
    stacks* temp=NULL;
    temp=*top;
    *top=(*top)->link;
    free(temp);
    temp=NULL;
}

void isEmpty(stacks** top){
    if(top==NULL){
        cout<<"The stack is empty!"<<endl;
        return;
    }
    else{
        cout<<"Stack is not empty!"<<endl;
    }
}

int peek(stacks** top){
    if(*top==NULL){
        cout<<"The stack is empty";
        return 0;
    }
    return ((*top)->data);
}

void print(stacks** top){
    stacks* ptr=new stacks();
    ptr=*top;
    cout<<"Element in the stack are: ";
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
    cout<<endl;
}

int main() {
    stacks* top=NULL;
    
    auto begin=high_resolution_clock::now();
    push(50,&top);
    push(100,&top);
    push(20,&top);
    push(30,&top);
    push(450,&top);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-begin);
    cout<<"the time taken by push function in stacks is: "<<duration.count()<<" nanoseconds "<<endl;
    print(&top);
    
    auto begin2=high_resolution_clock::now();
    pop(&top);
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(end2-begin2);
    cout<<"the time taken by pop function in stacks is: "<<duration2.count()<<" nanoseconds "<<endl;
    cout<<"on popping our stack"<<endl;
    print(&top);
    cout<<"our top element of the stack is "<<peek(&top)<<endl;
    isEmpty(&top);
    
// On comparing the time taken by push and pop functions by my implementation and by the implementation of STL shows that STL takes less time to perform these functions and thus, is more optimized.
}