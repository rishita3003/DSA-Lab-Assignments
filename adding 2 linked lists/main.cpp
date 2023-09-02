#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Sum of 2 lists and storing it in a linked list*/
/* declaring our data types in the class */

class node{
    public:
    int data;
    node* link;
};

/*user input for our linked list*/

void append(node**head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=NULL;

    if(*head_ref==NULL)
     {
         *head_ref=new_node;
         return;
     }
    node* ptr=*head_ref;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=new_node;
    return;
}

/* Push a new node at the start of the list */

void push(node** head_ref,int new_data){
    node* new_node=new node();
    new_node->data=new_data;
    new_node->link=*head_ref;
    *head_ref=new_node;
}

/* add the 2 lists formed */
node* addlist(node** head_ref1,node** head_ref2)
{
    node* ptr1=new node();
    node* ptr2=new node();
    ptr1=*head_ref1;
    ptr2=*head_ref2;

    int sum1=0;
    int sum2=0;

    while(ptr1->link!=NULL){
        sum1+=ptr1->data;
        sum1*=10;
        ptr1=ptr1->link;
    }
    sum1+=ptr1->data;

    while(ptr2->link!=NULL){
        sum2+=ptr2->data;
        sum2*=10;
        ptr2=ptr2->link;
    }
    sum2+=ptr2->data;

    int num3;
    num3=sum2+sum1;

    node* ptr=NULL;

    int temp;
    while(num3!=0){
        temp=num3%10;
        push(&ptr,temp);
        num3=num3/10;
    }

    return ptr;
}
/* print the list */

void printlist(node** head_ref){
    node* ptr=new node();
    ptr=*head_ref;

    if(*head_ref==NULL)
    {
        cout<<"list is empty!"<<endl;
        return;
    }

    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
    cout<<endl;
}


int main() {
    node* head1= NULL;
    node* head2=NULL;

    int n;
    cout<<"Enter the elements of list 1: ";
    while(1){
        cin>>n;
        if(n<0){
            break;
        }
        append(&head1,n);
    }

    cout<<"Enter the elements of list 2: ";
    while(1){
        cin>>n;
        if(n<0){
            break;
        }
        append(&head2,n);
    }
    cout<<"the first linked list is: ";
    printlist(&head1);
    cout<<"the second linked list is: ";
    printlist(&head2);
    node* head3=addlist(&head1,&head2);
    cout<<"the third linked list is: ";
   printlist(&head3);
}
