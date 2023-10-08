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

//dfs for single connected undirected graph
//recurrence

class dfs_graph{
    
private:
int v=5;
vector<vector<int>> adj;
int s;

public:
void vectors(){
    cout<<"Enter the source node of the graph: ";
    cin>>s;
    for(int i=0;i<v;i++){
        adj.pb({});
    }
    return;
}

//make an array to mark visited vertices

void dfs_g(){
    bool visited[v];
    fill(visited,visited+v,false);
    dfs_rec(s,visited);
}

void dfs_rec(int s,bool visited[]){
    if(visited[s]==true){
        return;
    }
    cout<<s<<" ";
    visited[s]=true;
    for(auto v:adj[s]){
        if(!visited[v]){
            dfs_rec(v,visited);
        }
    }
}

//to make our graph by specifiying adjacents

void edge(int u,int v){
    adj[u].pb(v);
    adj[v].pb(u);
}

//for user to declare there own graph edges
//enter a negative value or value greater than v to exit

void user_input(){
    int x,y;
    cout<<"Edge: ";
    cin>>x>>y;
    if(x>=0 && y>=0 && x<v && y<v){
    adj[x].pb(y);
    adj[y].pb(x);
    }
    else{
        return;
    }
    while(x>=0 && y>=0 && x<v && y<v){
     cout<<"Edge: ";
    int x,y;
    cin>>x>>y;
    if(x>=0 && y>=0 && x<v && y<v){
    adj[x].pb(y);
    adj[y].pb(x);
    }
    else{
        return;
    }
    }
}
};

int main(){
    ios::sync_with_stdio(false);

    dfs_graph dfs;
    dfs.vectors();
    dfs.user_input();
    dfs.edge(0,1);
    dfs.edge(0,2);
    dfs.edge(2,3);
    dfs.edge(1,3);
    dfs.edge(1,4);
    dfs.edge(4,5);
    dfs.dfs_g();
}
