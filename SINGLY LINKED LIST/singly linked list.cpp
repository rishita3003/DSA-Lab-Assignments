/*SINGLY LINKED LIST*/

//insertion -- beg,end,any pos
//deletion -- beg,end,any pos
//updation -- changing value of data
//search


#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

class node{
public:
    int data;
    node* link;
};

//user input in the list
void append(node**head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=NULL;

    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }

    node* ptr=new node();
    ptr=*head_ref;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=new_node;
    return;
}

//to insert data in front
void insert(node** head_ref,int new_data)
{
    //pointer to pointer head
    node* new_node=new node();
    //alloting memory to our new node

    new_node->data=new_data;
    new_node->link=(*head_ref);
    //next pointer is pointing to the previous head node
    (*head_ref)=new_node;
    //shifting our head node to the new node created
}

//insert data at any position
void inpos(node** head_ref,int new_data,int pos){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=NULL;

    node* prev=new node();
    prev=*head_ref;
    node* ptr=new node();
    ptr=*head_ref;

    while(pos!=1)
    {
        prev=ptr;
        ptr=ptr->link;
        pos--;
    }
    new_node->link=ptr;
    prev->link=new_node;


}

//to push data in the end of linked list
void push(node** head_ref,int new_data)
{
    node* ptr=new node();
    ptr=*head_ref;

    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=NULL;

    if(*head_ref==NULL){
        *head_ref=new_node;
    }
    //reaching the last link and then assigning the address of the newly created node
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=new_node;
}


//delete data from the linked list from start
void delend(node** head_ref)
{
    if(*head_ref==NULL){
        cout<<"the list is empty!"<<endl;
        return;
    }
    node* ptr=new node();
    ptr=*head_ref;
    node* prev=new node();
    prev=NULL;
    while(ptr->link!=NULL)
    {
        prev=ptr;
        ptr=ptr->link;
    }
    //ptr is the end node of our list which needs to be deleted
    //prev is the node before the end node
    //we want it to point to null as end node needs to be deleted
    prev->link=NULL;
    free(ptr);

}

//deleting node at given position and head node too
void delpos(node** head_ref,int pos){
    if(*head_ref==NULL){
        cout<<"the list is empty!"<<endl;
        return;
    }
    if(pos==1){
    node* ptr=new node();
    ptr=*head_ref;
    //ptr storing the address of the head pointer
    *head_ref=(*head_ref)->link;
    //to free the memory of our head pointer
    free(ptr);
    }

    else{
    node* prev=new node();
    node* ptr=new node();
    prev=*head_ref;
    ptr=*head_ref;
    while(pos!=1){
        prev=ptr;
        ptr=ptr->link;
        pos--;
    }
    prev->link=ptr->link;
    free(ptr);
    ptr=NULL;

    }

}

//to update
void update(node** head_ref,int new_data,int pos){
    node* ptr=new node();
    ptr=*head_ref;

    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }
    ptr->data=new_data;
}

int search(node** head_ref,int new_data){
    node* ptr=new node();
    ptr=*head_ref;

    if(ptr==NULL){
        cout<<"the list is empty"<<endl;
        return 0;
    }
    int pos=1;
    while(ptr!=NULL && ptr->data!=new_data ){
        ptr=ptr->link;
        pos++;
    }

    if(ptr==NULL) {
        cout<<"not found"<<endl;
        return 0;
    }

    cout<<"the position of "<<new_data<<" is "<<pos<<endl;
}

//to print the linked list
void printlist(node** head){
node* ptr=new node();
ptr=*head;
while(ptr!=NULL){
    cout<<ptr->data<<" ";
    ptr=ptr->link;
}
cout<<endl;
}

int main() {
    node* head=NULL;

    //to create a linked list first and then make changes in it
    int n;
    cout<<"enter the elements of the linked list(negative element to stop): ";
    while(true){
        cin>>n;
        if(n<0){
        break;
    }
    append(&head,n);

    }
    cout<<"the linked list is entered is: ";
    printlist(&head);

    //operations on user created linked list

    delend(&head);
    insert(&head,2);
    printlist(&head);
    struct timeval start,end;
    auto start_time = chrono::high_resolution_clock::now();
     push(&head,3);
    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    double time_taken = duration.count() * 1e-6; // Convert to seconds

    cout << "Time taken by push function is : " << fixed  << setprecision(10)<< time_taken;
    cout << " sec" << endl;

    insert(&head,4);
    printlist(&head);
    push(&head,5);
    inpos(&head,7,3);
    delpos(&head,4);
     struct timeval start2,end2;
   auto start_time2 = chrono::high_resolution_clock::now();
    delend(&head);
   auto end_time2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);
   double time_taken2 = duration.count() * 1e-6; // Convert to seconds
   cout << "Time taken by pop function is : "<< fixed  << setprecision(10)<< time_taken2;
    cout << " sec" << endl;

    update(&head,1,1);
    search(&head,10);
    search(&head,1);
    search(&head,2);
    search(&head,7);
 struct timeval start3,end3;
   auto start_time3 = chrono::high_resolution_clock::now();
    printlist(&head);
   auto end_time3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end_time3 - start_time3);
   double time_taken3 = duration.count() * 1e-6; // Convert to seconds
   cout << "Time taken by printlist function is : "<< fixed  << setprecision(10)<< time_taken3;
    cout << " sec" << endl;

}
