#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define ll long long
const ll num=1e9;

/* Queue implementation using 2 stacks */
/* FIFO */

class queues{
    stack<int> s1,s2;
    
public:

//Enqueue element in the stack s1
void enqueue(int x){
    s1.push(x);
}

//dequeue all elements from s1 to s2 
int dequeue(){
    if(s1.empty() && s2.empty()){
        return -1;
    }
     
    if(s2.empty()){
    while(!(s1.empty())){
        s2.push(s1.top());
        s1.pop();
    }
    }
    
    //to dequeue the first element of s1(or top element of s2)--> first element in s1 is first out
    int temp=s2.top();
    s2.pop();
    return temp;
}

//finding size of the queue
int size(){
    if(s1.empty() && s2.empty()){
        return 0;
    }
    else if(s1.empty()){
        return s2.size();
    }
    else{
        return s1.size();
    }
}
};

int main() {
    queues q;
    auto begin=high_resolution_clock::now();
    q.enqueue(3000);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-begin);
    cout<<"the time taken to push 3000 in queue is "<<duration.count()<<" nanoseconds"<<endl;
    
    auto begin2=high_resolution_clock::now();
    q.enqueue(10000);
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(end2-begin2);
     cout<<"the time taken to push 10000 in queue is "<<duration2.count()<<" nanoseconds"<<endl;
    
    auto begin3=high_resolution_clock::now();
    q.enqueue(1);
    auto end3=high_resolution_clock::now();
    auto duration3=duration_cast<nanoseconds>(end3-begin3);
     cout<<"the time taken to push 1 in queue is "<<duration3.count()<<" nanoseconds"<<endl;
     
    cout<<"the size of the queue is: "<<q.size()<<endl;
    cout<<"the queue right now is- "<<endl;
    cout<<q.dequeue()<<" "<<q.dequeue()<<" "<<q.dequeue()<<endl;
    cout<<"the size of the queue after dequeuing 3 elements: "<<q.size();
}

/* We can again observe here that irrespective of the size of the input, the time taken depends only on the order in which the elements are enqueued. Earlier enqueued element takes more or equal time than an element which is enqueued later */