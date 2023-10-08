#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_set>
#include <set>
#define ll long long
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
const ll num=1e9;
using namespace std;

//Graphs implementation using adjacency list (array of vectors)
//undirected graph

//taking user input for edges
//enter negative value or a vertex greater than equal to v to end the input

void user_input(vector<vector<int>> &adj,int v){
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


//add an edge

void edge(vector<vector<int>> &adj,int u,int v ){
    adj[u].pb(v);
    adj[v].pb(u);
}

//remove an edge

void del_edge(vector<vector<int>> &adj,int x,int y){
    auto it1=find(adj[y].begin(),adj[y].end(),x);
    auto it2=find(adj[x].begin(),adj[x].end(),y);
    if (it1 != adj[x].end() && it2 != adj[y].end()) {
    adj[x].erase(it2);
    adj[y].erase(it1);
    return;
     }
     else{
        cout<<"No such edge exists!"<<endl;
        return;
     }

}

//adjacent of a given vertex

void adj_ver(vector<vector<int>> &adj,int v){
cout<<"The adjacency list of vertex "<<v<<" is: ";
for(auto x:adj[v]){
    cout<<x<<" ";
}
cout<<endl;
}

//remove a vertex

void del_ver(vector<vector<int>>& adj,int* n,int x){
    if(x<0 || x>(*n)){
        cout<<"Invalid vertex to delete"<<endl;
        return;
    }
    for(auto y:adj[x]){
        auto it_x=find(adj[y].begin(),adj[y].end(),x);
        adj[y].erase(it_x);
    }

    adj[x].clear();
    adj.erase(adj.begin()+x);
    (*n)--;
    return;
}

//add a vertex --> not correctly working

void add_vertex(vector<vector<int>>& adj,int* v,int* n){
    (*v)++;
    (*n)++;
    adj.pb({});
    cout<<"Vertex added successfully!"<<endl;
}
//print the graph

void print(vector <vector<int>> &adj ,int n){
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
    int v;
    cout<<"Enter the number of vertices of graph initially: ";
    cin>>v;
    //number of vertices
    int n=v;

    vector<vector<int>> adj(v+1);
    user_input(adj,v);
    edge(adj,0,1);
    edge(adj,0,2);
    edge(adj,1,2);
    edge(adj,2,3);
    print(adj,v);
    del_edge(adj,0,1);
    adj_ver(adj,3);
    print(adj,v);
    del_ver(adj,&n,3);
    print(adj,v);
    add_vertex(adj,&v,&n);
    user_input(adj,v);
    print(adj,v);

}
