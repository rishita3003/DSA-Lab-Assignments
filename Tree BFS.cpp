#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <set>
#include<queue>
#define ll long long
#define inn int64_t
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
const ll num=1e9;
using namespace std;

class node{
    public:
    int key;
    node* left;
    node* right;
    node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};

//level order traversal --> line by line --> BFS

void level_order(node* root){
    if(root==NULL){
        return;
    }
    //keep updating the queue and keep printing the first element of it
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    //changing condition of q.empty() as on seeing null that will satisfy!
    while(q.size()>1){
        node* curr=q.front();
        q.pop();
        if(curr==NULL){
            q.push(curr);
            cout<<endl;
            continue;
        }

        cout<<curr->key<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
            }
        }
    }


int main(){
    node* root=new node(10);
    root->left=new node(15);
    root->right=new node(20);
    root->left->left=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root->right->left->left=new node(60);
    root->right->left->right=new node(70);

    cout<<"The line by line level order traversal of the tree is: "<<endl;
    level_order(root);
}

