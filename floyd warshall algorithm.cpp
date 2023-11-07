#include<iostream>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include <list>
#include <iomanip>
#include<queue>
#include <stack>
#include<chrono>
using namespace std::chrono;
using namespace std;
#define ll long long
#define pb push_back
const ll num=1e9;

#define pairs pair<int,int>

//directed graph --> shortest path
//time complexity: O(v^3)

class graph{
public:
int v;
int s;
vector<vector<int>> adj; //vector<pairs> because now we are also storing the weights of the vertices

graph(int vertex,int source){
    v=vertex;
    s=source;
    adj.resize(v);
    for(int i=0;i<v;i++){
        adj[i].resize(v);
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i!=j){
            adj[i][j]=INT_MAX;
            }
            else{
                adj[i][j]=0;
            }
        }
    }
}

void edge(int u,int z,int w){
    //edge between u and z having weight w
    adj[u][z]=w;
}

void shortest_path(){
    for(int via=0;via<v;via++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                    if(adj[i][via]!=INT_MAX && adj[via][j]!=INT_MAX){
                adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                    }
            }
        }
    }
}

void print_path(){
    cout<<"Vertex distance from source are: "<<endl;
    for(int i=0;i<v;i++){
           for(int j=0;j<v;j++){
                if(adj[i][j]==INT_MAX){
                    cout<<"inf"<<" ";
                    continue;
                }
            cout<<adj[i][j]<<"   ";
           }
           cout<<endl;
    }
}
};

int main(){
    ios::sync_with_stdio(false);
    cout<<"Enter the number of vertices in the graph: ";
    int n;
    cin>>n;
    int m;
    cout<<"Enter the source node for shortest path: ";
    cin>>m;
    graph floyd(n,m);

    /*srand(time(0));
    for(int i=0;i<bellman.v;i++){
        int u=rand()%bellman.v;
        int z=(u+rand())%bellman.v;
        int w=rand()%20;
    cout<<"Edge: "<<rand()%bellman.v<<" to "<<rand()%bellman.v<<" with weight "<<w<<endl;
    bellman.edge(u,z,w);
    }*/

    floyd.edge(0,1,4);
    floyd.edge(0,7,8);
    floyd.edge(1,2,8);
    floyd.edge(1,7,11);
    floyd.edge(2,3,7);
    floyd.edge(2,8,2);
    floyd.edge(2,5,4);
    floyd.edge(3,4,9);
    floyd.edge(3,5,14);
    floyd.edge(4,5,10);
    floyd.edge(5,6,2);
    floyd.edge(6,7,1);
    floyd.edge(6,8,6);

    using picoseconds=duration<ll,pico>;
    auto start=steady_clock::now();
    floyd.edge(7,6,2);
    auto end=steady_clock::now();
    auto dura=picoseconds(end-start);
    cout<<"The time taken to add an edge to the graph is: "<<dura.count()<<" picoseconds"<<endl;
    floyd.edge(7,8,7);

    auto start2=steady_clock::now();
   floyd.shortest_path();
    auto end2=steady_clock::now();
    auto duration2=picoseconds(end2-start2);
    cout<<"The time taken by floyd algorithm to find the shortest path is: "<<duration2.count()<<" picoseconds"<<endl;

    auto start3=steady_clock::now();
    floyd.print_path();
    auto end3=steady_clock::now();
    auto duration3=picoseconds(end3-start3);
    cout<<"The time taken to print the shortest path is: "<<duration3.count()<<" picoseconds"<<endl;

}
