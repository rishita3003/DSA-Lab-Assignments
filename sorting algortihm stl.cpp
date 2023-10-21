#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include<algorithm>
#define ll long long
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
#include <chrono>

using namespace std::chrono;
using namespace std;
const ll num=15000;

static ll arr[num];

void sorting(){
    for(size_t i=0;i<num;i++){
        arr[i]=rand()%1000;
    }
    auto start= high_resolution_clock::now();
    sort(arr,arr+num);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"The time taken by the STL sort function to sort the randomly generated array is "<<duration.count()<<" nanoseconds "<<endl;
}

void print(){
     cout<<"The sorted array is: ";
    for(size_t i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
   ios::sync_with_stdio(false);
   sorting();
   print();
}

/*we can see that the sorting done by the STL sort function is much faster than 
some of the sorting algorithms used earlier, this is because sort function of STL is intro sort 
which is combination of heap,quick and insertion sort, applied according their
best case or average case encountered, in order to give the best time complexity
*/
