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
//time complexity: O(V+E)

class graph{
public:
int v;
int s;
vector<vector<pairs>> adj; //vector<pairs> because now we are also storing the weights of the vertices
priority_queue<pairs,vector<pairs>,greater<pairs>> pq;
vector<int> dist;

//constructor of graph to allocate the sizes of all the data structures used
graph(int vertex,int source){
    v=vertex;
    s=source;
    adj.resize(v);
    dist.resize(v);
    fill(dist.begin(),dist.end(),INT_MAX);
}


//adding edge to the graph
void edge(int u,int z,int w){
    adj[u].pb({z,w}); //edge between u and z having weight w
}


//dijkstra shortest path algorithm using min heap implementation
void shortest_path(){
    dist[s]=0;
    pq.push({s,0});

    while(!pq.empty()){
        int u=pq.top().first;
        //int curr_dist=pq.top().second;
        pq.pop();


    for(auto x:adj[u]){
        int vertex=x.first; //x is the pair of the vector of pairs
        int weight=x.second;

        //relax the weights of the vertices

        if(dist[vertex]>dist[u]+weight){
            dist[vertex]=dist[u]+weight;
            pq.push({vertex,dist[vertex]});
        //since pq does not have a decrease key function, instead of decreasing it, we are adding all the instances in it
        }
    }
    }
}

//print the shortest distance of vertices from the source node
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
    graph dijkstra(n,m);

    dijkstra.edge(0,1,4);
    dijkstra.edge(0,7,8);
    dijkstra.edge(1,2,8);
    dijkstra.edge(1,7,11);
    dijkstra.edge(2,3,7);
    dijkstra.edge(2,8,2);
    dijkstra.edge(2,5,4);
    dijkstra.edge(3,4,9);
    dijkstra.edge(3,5,14);
    dijkstra.edge(4,5,10);
    dijkstra.edge(5,6,2);
    dijkstra.edge(6,7,1);
    dijkstra.edge(6,8,6);

    using picoseconds=duration<ll,pico>;

    auto start=steady_clock::now();
    dijkstra.edge(7,6,2);
    auto end=steady_clock::now();
    auto dura=picoseconds(end-start);
    cout<<"The time taken to add an edge to the graph is: "<<dura.count()<<" picoseconds"<<endl;
    dijkstra.edge(7,8,7);

    auto start2=steady_clock::now();
    dijkstra.shortest_path();
    auto end2=steady_clock::now();
    auto duration2=picoseconds(end2-start2);
    cout<<"The time taken by dijkstra algorithm to find the shortest path is: "<<duration2.count()<<" picoseconds"<<endl;

    auto start3=steady_clock::now();
    dijkstra.print_path();
    auto end3=steady_clock::now();
    auto duration3=picoseconds(end3-start3);
    cout<<"The time taken to print the shortest path is: "<<duration3.count()<<" picoseconds"<<endl;
}
