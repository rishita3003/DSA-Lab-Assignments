#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <set>
#define ll long long
#define inn int64_t
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
const ll num=1e9;
using namespace std;

//dfs --> multiple connected undirected graph
//recurrence
//count number of connected graphs

void dfs_rec(vector<int> adj[],int s,bool visited[]){
    if(visited[s]==true){
        return;
    }
    cout<<s<<" ";
    visited[s]=true;
    for(auto v:adj[s]){
        if(!visited[v]){
            dfs_rec(adj,v,visited);
        }
    }  
}

//make an array to mark visited vertices

void dfs(vector<int> adj[],int v){
    bool visited[v];
    fill(visited,visited+1,false);
    int count=0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs_rec(adj,i,visited);
            count++;
             cout<<endl;
        }
    }
    cout<<"The number of connected graphs are: "<<count<<endl;
}

//to make our graph by specifiying adjacents

void edge(vector<int> adj[],int u,int v){
    adj[u].pb(v);
    adj[v].pb(u);
}

//for user to declare there own graph edges

void user_input(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
    int x, y;
    cout<<"Enter the edge: ";
    cin>>x>>y;
    edge(adj,x,y);
    }
}

//print the graph

void print(<vector<int> adj[] ,int n){
    cout<<"The graph adjacency list: "<<endl;
    for(int i=0;i<n;i++){
            if(!adj[i].empty()){
           cout<<"vertex "<<i<<": ";
        for(int x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
            }
            else{
                return;
            }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int v;
    cout<<"Enter the number of vertices of the graph: ";
    cin>>v;
    vector<int> adj[v];
    user_input(adj,v);
    /*edge(adj,0,1);
    edge(adj,0,2);
    edge(adj,2,1);
    edge(adj,4,3);
    */
     dfs(adj,v);

}