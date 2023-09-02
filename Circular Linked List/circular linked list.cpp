/*circular linked list*/

//insertion --> start, any pos, end
//deletion -->end and any pos
//updation
//searching


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    node* link;
    int data;

};

//user input in the list

void append(node**head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;


    if(*head_ref==NULL){
        *head_ref=new_node;
        new_node->link=new_node;
        return;
    }

    node* ptr=new node();
    ptr=*head_ref;

    while(ptr->link!=*head_ref){
        ptr=ptr->link;
    }
    new_node->link=*head_ref;
    ptr->link=new_node;

    return;
}


//insert a node at beginning of the list

void push(node** head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=*head_ref;

    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
    new_node->link=new_node;
    *head_ref=new_node;
    return;
    }
    else
    {
        while(ptr->link!=*head_ref){
            ptr=ptr->link;
        }
        *head_ref=new_node;
        ptr->link=new_node;

        return;

}
}

//insert between two nodes in the list

void inpos(node** head_ref, int new_data, int prev_data){
    node* new_node=new node;
    new_node->data=new_data;

    node* ptr=new node();
    ptr=*head_ref;

    while(ptr->data!=prev_data){
        ptr=ptr->link;
    }
    new_node->link=ptr->link;
    ptr->link=new_node;

}

//insert at the end of the circular linked list

void inend(node** head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;

    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
    new_node->link=new_node;
    *head_ref=new_node;
    return;
    }
    else{
    while(ptr->link!=(*head_ref)){
            ptr=ptr->link;
    }
        ptr->link=new_node;
       new_node->link= *head_ref;
        return;
    }
}

//deletion of last node

void delend(node **head_ref){
    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
        cout<<"the list is empty!"<<endl;
        return;
    }

    node* prev=new node();
    prev=*head_ref;

    while(ptr->link!=*head_ref){
        prev=ptr;
        ptr=ptr->link;
    }
    prev->link=*head_ref;
    ptr=NULL;
    free(ptr);

}


//deletion of any node

void delpos(node ** head_ref,int new_data){
    if(*head_ref==NULL){
        cout<<"The list is already empty!"<<endl;
        return;
    }
    else if((*head_ref)->data==new_data && (*head_ref)->link==*head_ref){
            free(*head_ref);
            *head_ref=NULL;
            return;
        }
    else if((*head_ref)->data==new_data){
        node* ptr=new node();
        ptr=*head_ref;
        while(ptr->link!=*head_ref){
            ptr=ptr->link;
        }
        ptr->link=(*head_ref)->link;
        node* prev=new node();
        prev=*head_ref;
        (*head_ref)=(*head_ref)->link;
        free(prev);
        prev=NULL;
        return;
    }
    else{
        node* ptr=new node();
        ptr=*head_ref;
        node* prev=new node();
        prev=*head_ref;

        while(ptr->data!=new_data ){
            prev=ptr;
            ptr=ptr->link;
        }
        prev->link=ptr->link;
        free(ptr);
        ptr=NULL;
        return;
    }
}

//updating the list

void update(node** head_ref,int pos,int new_data){
    node* new_node=new node();
    new_node=*head_ref;

    while(pos!=1){
        new_node=new_node->link;
        pos--;
    }
    new_node->data=new_data;
    return;

}

//searching in the list

int search(node** head_ref,int new_data){
    node* ptr=new node();
    ptr=*head_ref;

    if(ptr==NULL){
        cout<<"the list is empty"<<endl;
        return 0;
    }
    int pos=1;
    while(ptr->link!=*head_ref && ptr->data!=new_data ){
        pos++;
        ptr=ptr->link;
    }

    if(ptr->link==*head_ref && ptr->data!=new_data) {
        cout<<new_data<<" is not found"<<endl;
        return 0;
    }

    else{
    cout<<"the position of "<<new_data<<" is "<<pos<<endl;
    return 0;
    }
}


//Print the circular linked list

void printlist(node** head_ref){
    if(*head_ref==NULL){
        cout<<"list is emtpy!"<<endl;
        return;
    }
    else{
    node* ptr=new node();
    ptr=(*head_ref);
    while(ptr->link!=(*head_ref)){
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
    cout<<ptr->data<<" ";
    }
    cout<<endl;
    return;
}


int main() {
  node* head=NULL;

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

  push(&head,5);
  push(&head,2);
  push(&head,3);
  printlist(&head);
  inend(&head,6);
  inpos(&head,7,3);
  delend(&head);
  delpos(&head,7);
  printlist(&head);
  delpos(&head,3);
  push(&head,7);
  push(&head,5);
  printlist(&head);
  push(&head,-10);
  push(&head,-1);
  update(&head,1,6);
  search(&head,11);
  search(&head,-10);
  search(&head,2);

  printlist(&head);
  return 0;
}
/*circular linked list*/

//insertion --> start, any pos, end
//deletion -->end and any pos
//updation
//searching


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    node* link;
    int data;

};

//user input in the list

void append(node**head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;


    if(*head_ref==NULL){
        *head_ref=new_node;
        new_node->link=new_node;
        return;
    }

    node* ptr=new node();
    ptr=*head_ref;

    while(ptr->link!=*head_ref){
        ptr=ptr->link;
    }
    new_node->link=*head_ref;
    ptr->link=new_node;

    return;
}


//insert a node at beginning of the list

void push(node** head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=*head_ref;

    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
    new_node->link=new_node;
    *head_ref=new_node;
    return;
    }
    else
    {
        while(ptr->link!=*head_ref){
            ptr=ptr->link;
        }
        *head_ref=new_node;
        ptr->link=new_node;

        return;

}
}

//insert between two nodes in the list

void inpos(node** head_ref, int new_data, int prev_data){
    node* new_node=new node;
    new_node->data=new_data;

    node* ptr=new node();
    ptr=*head_ref;

    while(ptr->data!=prev_data){
        ptr=ptr->link;
    }
    new_node->link=ptr->link;
    ptr->link=new_node;

}

//insert at the end of the circular linked list

void inend(node** head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;

    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
    new_node->link=new_node;
    *head_ref=new_node;
    return;
    }
    else{
    while(ptr->link!=(*head_ref)){
            ptr=ptr->link;
    }
        ptr->link=new_node;
       new_node->link= *head_ref;
        return;
    }
}

//deletion of last node

void delend(node **head_ref){
    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
        cout<<"the list is empty!"<<endl;
        return;
    }

    node* prev=new node();
    prev=*head_ref;

    while(ptr->link!=*head_ref){
        prev=ptr;
        ptr=ptr->link;
    }
    prev->link=*head_ref;
    ptr=NULL;
    free(ptr);

}


//deletion of any node

void delpos(node ** head_ref,int new_data){
    if(*head_ref==NULL){
        cout<<"The list is already empty!"<<endl;
        return;
    }
    else if((*head_ref)->data==new_data && (*head_ref)->link==*head_ref){
            free(*head_ref);
            *head_ref=NULL;
            return;
        }
    else if((*head_ref)->data==new_data){
        node* ptr=new node();
        ptr=*head_ref;
        while(ptr->link!=*head_ref){
            ptr=ptr->link;
        }
        ptr->link=(*head_ref)->link;
        node* prev=new node();
        prev=*head_ref;
        (*head_ref)=(*head_ref)->link;
        free(prev);
        prev=NULL;
        return;
    }
    else{
        node* ptr=new node();
        ptr=*head_ref;
        node* prev=new node();
        prev=*head_ref;

        while(ptr->data!=new_data ){
            prev=ptr;
            ptr=ptr->link;
        }
        prev->link=ptr->link;
        free(ptr);
        ptr=NULL;
        return;
    }
}

//updating the list

void update(node** head_ref,int pos,int new_data){
    node* new_node=new node();
    new_node=*head_ref;

    while(pos!=1){
        new_node=new_node->link;
        pos--;
    }
    new_node->data=new_data;
    return;

}

//searching in the list

int search(node** head_ref,int new_data){
    node* ptr=new node();
    ptr=*head_ref;

    if(ptr==NULL){
        cout<<"the list is empty"<<endl;
        return 0;
    }
    int pos=1;
    while(ptr->link!=*head_ref && ptr->data!=new_data ){
        pos++;
        ptr=ptr->link;
    }

    if(ptr->link==*head_ref && ptr->data!=new_data) {
        cout<<new_data<<" is not found"<<endl;
        return 0;
    }

    else{
    cout<<"the position of "<<new_data<<" is "<<pos<<endl;
    return 0;
    }
}


//Print the circular linked list

void printlist(node** head_ref){
    if(*head_ref==NULL){
        cout<<"list is emtpy!"<<endl;
        return;
    }
    else{
    node* ptr=new node();
    ptr=(*head_ref);
    while(ptr->link!=(*head_ref)){
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
    cout<<ptr->data<<" ";
    }
    cout<<endl;
    return;
}


int main() {
  node* head=NULL;

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

  push(&head,5);
  push(&head,2);
  push(&head,3);
  printlist(&head);
  inend(&head,6);
  inpos(&head,7,3);
  delend(&head);
  delpos(&head,7);
  printlist(&head);
  delpos(&head,3);
  push(&head,7);
  push(&head,5);
  printlist(&head);
  push(&head,-10);
  push(&head,-1);
  update(&head,1,6);
  search(&head,11);
  search(&head,-10);
  search(&head,2);

  printlist(&head);
  return 0;
}
