/*To do list: Task Manager which manages your priority order and due dates for different tasks.*/
/*It helps adding new tasks to your list and delete ones which are completed*/
/*It also let you search for a particular task in your list and check its due date!*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node {
public:
    string prior;
    string date;
    string task;
    node* link;
};

// Function to append a new node at the end of the linked list
void append(node** head_ref, string nprior, string new_date, string new_task) {
    node* new_node = new node();
    new_node->prior = nprior;
    new_node->date = new_date;
    new_node->task = new_task;
    new_node->link = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    node* ptr = *head_ref;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

// Function to push a new node at the end of the linked list
void push(node** head_ref, string nprior, string new_date, string new_task) {
    node* ptr = *head_ref;
    node* new_node = new node();
    new_node->prior = nprior;
    new_node->date = new_date;
    new_node->task = new_task;
    new_node->link = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

// Function to insert a new node at the front of the linked list
void insert(node** head_ref, string nprior, string new_date, string new_task) {
    node* new_node = new node();
    new_node->prior = nprior;
    new_node->date = new_date;
    new_node->task = new_task;
    new_node->link = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a new node at a specific position in the linked list
void inpos(node** head_ref, string nprior, string new_date, string new_task, int pos) {
    node* new_node = new node();
    new_node->prior = nprior;
    new_node->date = new_date;
    new_node->task = new_task;
    new_node->link = NULL;

    node* prev = *head_ref;
    node* ptr = *head_ref;

    while (pos != 1) {
        prev = ptr;
        ptr = ptr->link;
        pos--;
    }
    new_node->link = ptr;
    prev->link = new_node;
}

// Function to delete the last node from the linked list
void delend(node** head_ref) {
    if (*head_ref == NULL) {
        cout << "The list is empty already!" << endl;
        return;
    }
    node* ptr = *head_ref;
    node* prev = NULL;
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    if (prev != NULL) {
        prev->link = NULL;
    } else {
        *head_ref = NULL;
    }
    free(ptr);
    ptr = NULL;
}

// Function to delete a node at a given position
void delpos(node** head_ref, int pos) {
    if (*head_ref == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }
    if (pos == 1) {
        node* ptr = *head_ref;
        *head_ref = (*head_ref)->link;
        free(ptr);
    } else {
        node* prev = *head_ref;
        node* ptr = *head_ref;
        while (pos != 1) {
            prev = ptr;
            ptr = ptr->link;
            pos--;
        }
        prev->link = ptr->link;
        free(ptr);
        ptr = NULL;
    }
}

// Function to update the data of a node at a given position
void update(node** head_ref, string nprior, string new_date, string new_task, int pos) {
    node* ptr = *head_ref;
    while (pos != 1) {
        ptr = ptr->link;
        pos--;
    }
    ptr->prior = nprior;
    ptr->date = new_date;
    ptr->task = new_task;
}

// Function to search for a node with specific data and print its position
int search(node** head_ref, string nprior, string new_date, string new_task) {
    node* ptr = *head_ref;
    if (ptr == NULL) {
        cout << "The list is empty" << endl;
        return 0;
    }
    int pos = 1;
    while (ptr != NULL && (ptr->prior != nprior || ptr->date != new_date || ptr->task != new_task)) {
        ptr = ptr->link;
        pos++;
    }
    if (ptr == NULL) {
        cout << "Not found" << endl;
        return 0;
    }
}
//to print the linked list

void printlist(node** head_ref){
node* ptr=new node();
ptr=*head_ref;

if(*head_ref==NULL){
    cout<<"Right now, the list is empty!"<<endl;
    return;
}

while(ptr!=NULL){
    cout<<"Task: "<<ptr->task<<endl;
    cout<<"Priority: "<<ptr->prior<<endl;
    cout<<"Due Date: "<<ptr->date<<endl;

    ptr=ptr->link;
}
cout<<endl;
}

int main() {
    node* head=NULL;

    //to create a linked list first and then make changes in it
    string n_prior;
    string n_date;
    string n_task;

    cout<<"Enter the elements of the linked list(negative element to stop): ";
    while(true){
        cin>>n_prior>>n_date>>n_task;
        if(n_prior[0]=='-'){
        break;
    }
    append(&head, n_prior,n_date, n_task);

    }
    cout<<"The task list is entered is: "<<endl;
    //printing the user entered linked list
    printlist(&head);

    //operations on user created linked list
    cout<<"The task list after applying operations is: "<<endl;
    push(&head,"2","29/08","Make text editor");
    push(&head,"1","27/05","Linked List Assignment");
    push(&head,"3","8/09","Signal system quiz-> study");
    update(&head,"1","24/08","Discrete Math quiz->study",3);
    push(&head,"4","anytime","leisure time");
    printlist(&head);
    cout<<"Let's not waste time :)"<<endl;
    delpos(&head,4);
    printlist(&head);
    search(&head,"1","24/08","Discrete Math quiz->study");
    insert(&head,"2","29/08","FEC Game Theory Project");
    inpos(&head,"3","Tue,Thu,Sat","SA Badminton",3);
    push(&head,"1","everyday","bath");
    delend(&head);
    cout<<"Now my final task list is: "<<endl;
    printlist(&head);

}
