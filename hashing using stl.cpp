#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#define ll long long
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
#include <chrono>
const ll num=1e9;
using namespace std::chrono;
using namespace std;

int main(){
    map <int,int> hash;
    cout<<"Take user input for the values to be entered in hash map: "<<endl;
    int x;
    cin>>x;
    int temp;
    while(x>=0){
        cin>>x;
        if(x>=0){
        temp=x%10;
        hash[temp]++;
    }
    }
    
    auto start= high_resolution_clock::now();
    hash[4]++;
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
     cout<<"the time taken to assign key is: "<<duration.count()<<" nanoseconds "<<endl;
    hash[5]++;
    hash[2]++;
    hash[4]++;
    hash[5]++;
    
    for(const auto& iter: hash){
        cout<<"Key: "<< iter.first << "  Value: "<<iter.second<<endl;
    }
}
