#include <iostream>
#define ll long long
#include <chrono>
using namespace std::chrono;
using namespace std;
const ll num = 1e9 + 7;
const ll table_size = 10;

// Define a structure for nodes in the linked lists
typedef struct node {
    int key;
    struct node* next;
} node;

// Hash function using division method
int myhash(int key) {
    key = key % table_size;
    return key;
}

// Array of linked lists for the hash table
node* hash_table[table_size] = { NULL };

// Function to insert a key into the hash table
void insert(int key) {
    node* newnode = new node();
    newnode->key = key;
    newnode->next = NULL;

    int index = myhash(key);

    if (hash_table[index] == NULL) {
        // If the bucket is empty, insert the new node
        hash_table[index] = newnode;
    }
    else {
        // Handle collision by adding the new node at the beginning of the list
        newnode->next = hash_table[index];
        hash_table[index] = newnode;
    }
}

// Function to retrieve a key from the hash table
void retrieve(int key) {
    int index = myhash(key);
    node* ptr = hash_table[index];

    while (ptr != NULL) {
        if (ptr->key == key) {
            cout << "The index of " << key << " in the table is: " << (key % table_size) << endl;
            return;
        }
        ptr = ptr->next;
    }

    cout << key << " is not found." << endl;
}

// Function to remove a key from the hash table
void remove(int key) {
    int index = myhash(key);
    node* ptr = hash_table[index];
    node* prev = hash_table[index];

    if (ptr == NULL) {
        cout << "The list at this index does not exist! " << endl;
        return;
    }
    else if (ptr->key == key) {
        // If the key is at the beginning of the list
        hash_table[index] = ptr->next;
        delete ptr;
        return;
    }
    else {
        while (ptr != NULL) {
            if (ptr->key == key) {
                prev->next = ptr->next;
                delete ptr;
                return;
            }
            else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
}

// Function to print the entire hash table
void print() {
    cout << "The Hash Table is: " << endl;
    for (ll i = 0; i < table_size; i++) {
        node* ptr = hash_table[i];
        if (hash_table[i] == NULL) {
            if (i != table_size - 1) {
                continue;
            }
            else {
                cout << "Reached the end of the table." << endl;
                return;
            }
        }

        while (ptr != NULL) {
            cout << ptr->key << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main() {
    auto start=high_resolution_clock::now();
    insert(4);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"The time taken to insert an element in the hash table is: "<<duration.count()<<" nanoseconds"<<endl;
    insert(6);
    insert(44);
    insert(86);
    auto start2=high_resolution_clock::now();
    remove(86);
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(end2-start2);
    cout<<"The time taken to remove an element in the hash table is: "<<duration2.count()<<" nanoseconds"<<endl;
    
    auto start4=high_resolution_clock::now();
    print();
    auto end4=high_resolution_clock::now();
    auto duration4=duration_cast<nanoseconds>(end4-start4);
     cout<<"The time taken to print the elements in the hash table is: "<<duration4.count()<<" nanoseconds"<<endl;
    
    
    auto start3=high_resolution_clock::now();
    retrieve(44);
    auto end3=high_resolution_clock::now();
    auto duration3=duration_cast<nanoseconds>(end3-start3);
     cout<<"The time taken to retrieve an element from the hash table is: "<<duration3.count()<<" nanoseconds"<<endl;
    retrieve(14);

    return 0;
}
