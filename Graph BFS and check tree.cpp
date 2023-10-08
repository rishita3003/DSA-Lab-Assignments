#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <set>
#define ll long long
#define inn int64_t
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
const ll num=1e9;
using namespace std;

void edge(vector <int> adj[],int u,int v){
    adj[u].pb(v);
    adj[v].pb(u);
return;
}

//breadth first search

void bfs(vector <int> adj[],int v,int s){
    bool visit[v+1]; //vertices adjacent
    fill(visit,visit+(v),false);
    visit[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto x:adj[u]){
            if(visit[x]!=true){
            visit[x]=true;
            q.push(x);
            }
        }
    }
    cout<<endl;
}

//check if graph is a tree

bool tree(vector<int> adj[],int v,int s){
    bool visit[v+1];
    fill(visit,visit+v,false);
    int parent[v];
    parent[s]=-1;
    queue<int> q;
    visit[s]=true;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto x:adj[u]){
            if(!visit[x]){
                parent[x]=u;
                visit[x]=true;
                q.push(x);
            }
            //if any node apart front the parent node is repeated through another node, then a cycle in graph
            //thus not a tree
            else if(visit[x] && x!=parent[u]){
                return false;
            }
        }
    }
//If any node left unvisited then also not a tree
for(int i=0;i<v;i++){
    if(!visit[i]){
        return false;
    }
}
return true;
}



int main(){
    int v;
    cout<<"Enter the number of vertices of graph: ";
    cin>>v;
    vector<int> adj[v];
    /*edge(adj,0,1);
    edge(adj,0,2);
    edge(adj,1,2);
    edge(adj,1,3);
    edge(adj,2,4);
    edge(adj,3,4);
    edge(adj,2,3);*/
    
    edge(adj,0,1);
    edge(adj,0,4);
    edge(adj,1,2);
    edge(adj,1,3);
    edge(adj,5,4);
    edge(adj,5,6);
    edge(adj,5,7);
    int s;
    cout<<"Enter the source node: ";
    cin>>s;
    cout<<"The breadth first search traversal: "<<endl;
    bfs(adj,v,s);
    cout<<"TREE(1/0): "<<tree(adj,v,s);

}
