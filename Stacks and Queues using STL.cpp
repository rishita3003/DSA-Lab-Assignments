#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
#define ll long long
const ll num=1e9;
using namespace std::chrono;

/*Stacks and Queues using STL */ 

int main() {
    stack <int> s;
    queue<int> q;
    
    auto start = high_resolution_clock::now();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(22);
    s.push(23);
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(stop-start);
    cout<<"the time taken by push function in stack is: "<<duration.count()<<" nanoseconds "<<endl;
    s.push(25);
    s.push(5);
    auto begin=high_resolution_clock::now();
    s.pop();
    auto end=high_resolution_clock::now();
    auto duration3=duration_cast<nanoseconds>(end-begin);
    cout<<"the time taken by pop function in stack is: "<<duration3.count()<<" nanoseconds "<<endl;
    s.pop();
    
    cout<<"the stack is- "<<endl;
    //printing the stack
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    
    auto start2=high_resolution_clock::now();
    q.push(45);
    q.push(46);
    q.push(47);
    q.push(45);
    q.push(8);
    auto stop2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(stop2-start2);
    cout<<"the time taken by push function of queue is: "<<duration2.count()<<" nanoseconds "<<endl;
    q.push(80);
    
    auto begin2=high_resolution_clock::now();
    q.pop();
    auto end2=high_resolution_clock::now();
    auto duration4=duration_cast<nanoseconds>(end2-begin2);
    cout<<"the time taken by pop function of queue is: "<<duration4.count()<<" nanoseconds "<<endl;
    q.pop();
    
    cout<<"the queue is- "<<endl;
    while(!(q.empty())){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}