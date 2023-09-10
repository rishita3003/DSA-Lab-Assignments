#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <chrono>
using namespace std::chrono;

/* implementation of queue */

class queues{
    public:
    int data;
    queues* link;
};

void enqueue(int new_data,queues** head,queues** tail){
    queues* new_node=new queues();
    new_node->data=new_data;
    new_node->link=NULL;
    if(*tail==NULL){
        *head=*tail=new_node;
        return;
    }
    (*tail)->link=new_node;
        *tail=new_node;
      
}

void dequeue(queues** head,queues** tail){
    if(*head==NULL){
        cout<<"the queue is already empty"<<endl;
        return;
    }
    queues* temp=new queues();
    temp=*head;
    *head=(*head)->link;
    free(temp);
    temp=NULL;
}

void print(queues** head,queues** tail){
    if(*tail==NULL){
        cout<<"The queue is empty"<<endl;
        return;
    }
    queues* temp;
    temp=*head;
    cout<<"Elements of the queue are: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
    
}

int main() {
    queues* head=NULL;
    queues* tail=NULL;
    head=tail;
    auto begin=high_resolution_clock::now();
    enqueue(56,&head,&tail);
    enqueue(32,&head,&tail);
    enqueue(1,&head,&tail);
    enqueue(77,&head,&tail); 
    enqueue(50,&head,&tail);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-begin);
    cout<<"the time taken by enqueue/push function of queue is: "<<duration.count()<<" nanoseconds"<<endl;
    print(&head,&tail);
    
    auto begin2=high_resolution_clock::now();
    dequeue(&head,&tail);
    auto end2=high_resolution_clock::now();
     auto duration2=duration_cast<nanoseconds>(end2-begin2);
    cout<<"the time taken by dequeue/pop function of queue is: "<<duration.count()<<" nanoseconds"<<endl;
    enqueue(3,&head,&tail);
    enqueue(23,&head,&tail);
    
    print(&head,&tail);
}