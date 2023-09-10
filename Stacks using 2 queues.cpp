#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define ll long long
const ll num=1e9;

/* Implementing stacks using 2 queues */

class stacks{
    queue<int> q1,q2;
    
public:
//Push an element in the empty queue q2
void push(int x){
    q2.push(x);
    
    //Pushing all elements in q2 from q1, after the last element
    while(!(q1.empty())){
        q2.push(q1.front());
        q1.pop();
    }
    
    queue <int> q;
    q=q1;
    q1=q2;
    q2=q;
    //swap the queues names as we want to always keep q2 empty to push new element in it
}

//Popping, such that last element in is the first out(LIFO)
void pop(){
    if(q1.empty()){
        cout<<"the stack is empty!"<<endl;
        return;
    }
    q1.pop();
}

int top(){
    return (q1.empty()) ? -1:q1.front();
}

//size of the stack 
int size(){
    if(q1.empty()){
        return 0;
    }
    return q1.size();
}
};

int main(){
    stacks s; //s is the obejct of the class stack
    auto begin=high_resolution_clock::now();
    s.push(1);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-begin);
    cout<<"the time taken to push 1 in stack is "<<duration.count()<<" nanoseconds"<<endl;
    
    auto begin2=high_resolution_clock::now();
    s.push(10);
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(end2-begin2);
     cout<<"the time taken to push 10 in stack is "<<duration2.count()<<" nanoseconds"<<endl;

    auto begin3=high_resolution_clock::now();
    s.push(100000);
    auto end3=high_resolution_clock::now();
    auto duration3=duration_cast<nanoseconds>(end3-begin3);
     cout<<"the time taken to push 100000 in stack is "<<duration3.count()<<" nanoseconds"<<endl;
    
    auto begin4=high_resolution_clock::now();
    s.push(100);
    auto end4=high_resolution_clock::now();
    auto duration4=duration_cast<nanoseconds>(end4-begin4);
     cout<<"the time taken to push 100 in stack is "<<duration4.count()<<" nanoseconds"<<endl;
     
    cout<<"the top element right now is: "<<s.top()<<endl;
    cout<<"the size of the stack is: "<<s.size()<<endl;
    cout<<"the full stack right now is- "<<endl;
    
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<"after popping 3 elements now the size of the stack is: "<<s.size()<<endl;
}

/* We can observe from the above time taken by various push functions that the time does not depend on the size of the input but depend on which element is pushed before. The element which is pushed earlier,takes more time in push function */