#include<iostream>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include <list>
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
//time complexity --> O(v*e)

class graph{
public:
int v;
int s;
vector<vector<pairs>> adj; //vector<pairs> because now we are also storing the weights of the vertices
vector<int> dist;

graph(int vertex,int source){
    v=vertex;
    s=source;
    adj.resize(v);
    dist.resize(v);
    fill(dist.begin(),dist.end(),INT_MAX);
}

void edge(int u,int z,int w){
    adj[u].pb({z,w}); //edge between u and z having weight w
}

void shortest_path(){
    dist[s]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<v;j++){
            for(auto x:adj[j]){
                if(dist[j]!=INT_MAX && dist[x.first]>dist[j]+x.second){
                    dist[x.first]=dist[j]+x.second;
                }
            }
        }
    }

    for(int j=0;j<v;j++){
        for(auto k:adj[j]){
            int u=j;
            int z=k.first;
            int w=k.second;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                cout<<"Negative cycle detected"<<endl;
                return;
            }
        }
    }
}

void print_path(){
    cout<<"Vertex distance from source are: "<<endl;
    for(int i=0;i<v;i++){
            if(dist[i]==INT_MAX){
                cout<<i<<" INF"<<endl;
                continue;
            }
        cout<<i<<" "<<dist[i]<<endl;
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
    graph bellman(n,m);

    /*srand(time(0));
    for(int i=0;i<bellman.v;i++){
        int u=rand()%bellman.v;
        int z=(u+rand())%bellman.v;
        int w=rand()%20;
    cout<<"Edge: "<<rand()%bellman.v<<" to "<<rand()%bellman.v<<" with weight "<<w<<endl;
    bellman.edge(u,z,w);
    }*/

    bellman.edge(0,1,4);
    bellman.edge(0,7,8);
    bellman.edge(1,2,8);
    bellman.edge(1,7,11);
    bellman.edge(2,3,7);
    bellman.edge(2,8,2);
    bellman.edge(2,5,4);
    bellman.edge(3,4,9);
    bellman.edge(3,5,14);
    bellman.edge(4,5,10);
    bellman.edge(5,6,2);
    bellman.edge(6,7,1);
    bellman.edge(6,8,6);

    using picoseconds=duration<ll,pico>;
    auto start=steady_clock::now();
    bellman.edge(7,6,2);
    auto end=steady_clock::now();
    auto dura=picoseconds(end-start);
    cout<<"The time taken to add an edge to the graph is: "<<dura.count()<<" picoseconds"<<endl;
    //bellman.edge(7,8,7);

    auto start2=steady_clock::now();
    bellman.shortest_path();
    auto end2=steady_clock::now();
    auto duration2=picoseconds(end2-start2);
    cout<<"The time taken by bellman algorithm to find the shortest path is: "<<duration2.count()<<" picoseconds"<<endl;

    auto start3=steady_clock::now();
    bellman.print_path();
    auto end3=steady_clock::now();
    auto duration3=picoseconds(end3-start3);
    cout<<"The time taken to print the shortest path is: "<<duration3.count()<<" picoseconds"<<endl;

}
