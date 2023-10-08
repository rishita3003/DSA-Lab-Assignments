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

int main(){
    ios::sync_with_stdio(false);
    priority_queue <int,vector<int>,greater <int>> pq;
    pq.push(5);
    auto start1=high_resolution_clock::now();
    pq.push(1);
    pq.push(10);
    pq.push(30);
    auto end1=high_resolution_clock::now();
    auto duration1=duration_cast<nanoseconds>(end1-start1);
    cout<<"The time taken by push function is: "<<duration1.count()<<" nanoseconds "<<endl;

    
   
    pq.push(2);
    pq.push(20);
    cout<<pq.top()<<" ";
    auto start2=high_resolution_clock::now();
    pq.pop();
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(end2-start2);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    cout<<"The time taken by the pop function is: "<<duration2.count()<<" nanoseconds "<<endl;
    return 0;
}
