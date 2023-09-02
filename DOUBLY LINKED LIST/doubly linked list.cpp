/*doubly linked list*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* link;
    node* prev;
};

//user input in the list --> new nodes added in the front of the existing
void append(node**head_ref,int new_data){
   node* new_node=new node();
    new_node->data=new_data;
    new_node->link=NULL;
    new_node->prev=NULL;

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
    new_node->prev=ptr;
    return;
}

//inserting/pushing node at the start of the list

void push(node** head_ref,int new_data){
    node *new_node=new node();
    new_node->data=new_data;
    new_node->link=*(head_ref);
    new_node->prev=NULL;

    if(*(head_ref)!=NULL)
    {
        (*head_ref)->prev=new_node;
    }
    *(head_ref)=new_node;
    //head is now pointing to the new node
}

//inserting  a node at the some random position of the list

void inpos(node** head_ref,int new_data,int pos){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=NULL;

    node* ptr=new node();
    ptr=*head_ref;
    node* pre=new node();
    pre=*head_ref;

    while(pos!=1){
        pre=ptr;
        ptr=ptr->link;
        pos--;

    }
    pre->link=new_node;
    new_node->link=ptr;
    new_node->prev=pre;
    //new node links are now set in between the list at the desired position
    return;

}

//inserting a node at the end of the list

void inend(node** head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=NULL;

    if(*head_ref==NULL){
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }

    node*ptr=new node();
    ptr=*head_ref;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=new_node;

    new_node->prev=ptr;
    return;

}

// deleting 1st or any position node from the list

void delpos(node** head_ref,int pos){
    node* ptr=new node();
    ptr=*head_ref;
    node* pre=new node();
    pre=*head_ref;

    if(pos==1){
        *head_ref=ptr->link;
       free(ptr);

        return;
    }

    while(pos!=1){
        pre=ptr;
        ptr=ptr->link;
        pos--;
    }
    pre->link=ptr->link;
    ptr->link->prev=pre;

    ptr=NULL;
    free(ptr);
    //making the pointer null means we are deleting the data in the pointer
    //free the pointer means that we are freeing the pointer from the links it has with the list
}

void delend(node** head_ref){
    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
        cout<<"The list is already is empty"<<endl;
    }

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->prev->link=NULL;
    free(ptr);
    ptr=NULL;

    return;
}

//update the list element

void update(node** head_ref,int new_data,int pos){
    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL){
        cout<<"the list is empty!"<<endl;
        return;
    }

    if(pos==1){
        ptr->data=new_data;
        return;
    }

    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }
    ptr->data=new_data;

}

//search an element in the data

void search(node** head_ref,int new_data){
    node* ptr=new node();
    ptr=*head_ref;

    int pos=1;
    while(ptr!=NULL && ptr->data!=new_data){
        ptr=ptr->link;
        pos++;
    }

    if(ptr==NULL){
        cout<<new_data<<" not found!"<<endl;
        return;
    }
    else{
        cout<<"the position of "<<new_data<<" is "<<pos<<endl;
        return;
    }



}

//printing the linked list formed

void printlist(node** head_ref){
    if(*head_ref==NULL){
        cout<<"list is emtpy!"<<endl;
        return;
    }
    node* ptr=new node();
    ptr=*(head_ref);
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
    cout<<endl;

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

    //operations on user created linked list

    inend(&head,5);
    inend(&head,4);
    printlist(&head);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printlist(&head);
    inpos(&head,5,2);
    delpos(&head,1);
    delpos(&head,3);
    delend(&head);
    printlist(&head);
    update(&head,7,2);
    update(&head,7,1);
    search(&head,5);
    search(&head,2);

    printlist(&head);
}
