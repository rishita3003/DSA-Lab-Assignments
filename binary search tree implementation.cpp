#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <set>
#include <queue>
#include <chrono>
#define ll long long
#define inn int64_t
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
const ll num=1e9;
using namespace std;
using namespace std::chrono;

//binary search tree

class Node{
    public:
    int key;
    Node* left;
    Node* right;

    //constructor
    Node(int k){
        this->key=k; //cuz we are making node of node* type
        this->left=NULL;
        this->right=NULL;
    }

bool search(int ele,Node* root){
    if(root==NULL){
        return false;
    }
    if(ele==root->key){
        return true;
    }
    if(ele<root->key){
        return search(ele,root->left);
    }
    else{
        return search(ele,root->right);
    }
}

//Inserting a new node in the tree

void insert(Node** root,int ele){
    if(*root==NULL){
        *root= new Node(ele);
        return;
    }

    if(ele==(*root)->key){
        cout<<"Element is already there in tree"<<endl;
        return;
    }
    if(ele>(*root)->key){
        insert(&((*root)->right),ele);
    }
    else{
        insert(&((*root)->left),ele);
    }
   return;
}
    /* recursive without double pointer
    Node *insert(Node *root, int x){
    if(root==NULL)
        return new Node(x);
    if(root->key<x)
        root->right=insert(root->right,x);
    else if(root->key>x)
        root->left=insert(root->left,x);
    return root;
    } */

    /*interative
    while(temp!=NULL){
        Node* prev=temp;
        if(temp->key==ele){
            cout<<"Element is already there in tree"<<endl;
            break;
        }
        if(temp->key<ele){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }

    */
 

//get successor function only for delete function(i.e. when right child is not null), it does not handle cases for getting general successor
Node* get_successor(Node* root){
    Node* curr=root->right;
    while(curr->left!=NULL && curr!=NULL){
        curr=curr->left;
    }
    return curr;
}

//deleting a node in the tree

//Node* used to prevent the use of Node** root (double pointer to root to store changes)
Node* delnode(Node* root,int ele){
    if(root==NULL){
        return root;
    }
    else if(root->key>ele){
        root->left=delnode(root->left,ele);
    }
    else if(root->key<ele){
        root->right=delnode(root->right,ele);
    }
    //case when root->key==element, so now we check for it having 1 child or both children
    else{
        if(root->left==NULL){
            Node* curr=root->right;
            delete root;
            return curr;
        }
        else if(root->right==NULL){
            Node* curr=root->left;
            delete root;
            return curr;
        }
        //both children non empty
        else{
            Node* succ=get_successor(root);
            root->key=succ->key;
            //calling delete function again to delete the successor key in right subtree
            root->right=delnode(root->right,succ->key);
        }
    }
}

//size of tree
//O(n) --> time complexity and O(h)(in recursive) , O(width)(in iterative, by queue)--> Auxilliary space

int size(Node* root){
    if(root==NULL){
            return 0;
    }
    return (size(root->left)+size(root->right)+1);
    }

int count_min=0;
//minimum element in the binary search tree

int mini(Node* root){
    while(root->left!=NULL){
        count_min++;
        root=root->left;
    }
    count_min++;
    return root->key;
}

int count_max=0;
//maximum element in the binary search tree

int maxi(Node* root){
    while(root->right!=NULL){
        count_max++;
        root=root->right;
    }
    count_max++;
    return root->key;
}

//floor
//O(H)--> time and O(1)-->extra space

int floor(Node* root,int ele){
    int res=-1;
    while(root!=NULL){
        if(root->key==ele){
            return root->key;
        }
        else if(root->key>ele){
            root=root->left;
        }
        else{
            res=root->key;
            root=root->right;
        }
    }
    return res;
}

//ceiling

int ceil(Node* root,int ele){
    int res=-1;
    while(root!=NULL){
        if(root->key==ele){
            return root->key;
            }
        else if(root->key<ele){
            root=root->right;
        }
        else{
            res=root->key;
            root=root->left;
        }
    }
    return res;
}

//checking if right and left subtree extend to same height or not

bool symmetric(){
    if(count_max==count_min){
        return true;
    }
    return false;
}

void print_inorder(Node* root){
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
    cout<<root->key<<" ";
    print_inorder(root->right);
}

void print_postorder(Node* root){
    if(root==NULL){
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->key<<" ";
}

void print_preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->key<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}

};

//time complexity: O(height) auxilliary space: O(height)
// for iterative soln: O(height) space: O(1)

int main(){
    ios::sync_with_stdio(false);
    Node* root=new Node(10); //*root is our instance of node class
    cout<<root->key<<endl;
    /*if(root->right==NULL && root->left==NULL){
        cout<<"YES"<<endl;
    }*/
    root->insert(&root,20);
    //cout<<root->right->key<<endl;
    root->insert(&root,15);
    root->insert(&root,5);
    root->insert(&root,40);
    root->insert(&root,25);
    cout<<"Maximum element in the tree is: "<<root->maxi(root)<<endl;
    cout<<"Minimum element in the tree is: "<<root->mini(root)<<endl;

    cout<<"Is the tree symmetric(Yes/No)? "<<endl;
    if(root->symmetric()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    root->delnode(root,40);
    cout<<"Maximum element in the tree is: "<<root->maxi(root)<<endl;
    cout<<"The binary tree inorder is as follows: ";
    root->print_inorder(root);
    cout<<endl;
    cout<<"The binary tree postorder is as follows: ";
    root->print_postorder(root);
    cout<<endl;
    cout<<"The binary tree preorder is as follows: ";
    root->print_preorder(root);
    cout<<endl;

    cout<<"Size of the tree is: "<<root->size(root)<<endl;
    cout<<"Floor is: "<<root->floor(root,18)<<endl;
    cout<<"Ceil is: "<<root->ceil(root,18)<<endl;
}

