#include<iostream>
#include<cstring>
#include<ctime>
#include <iomanip>
#include <vector>
#include<algorithm>
#include<chrono>
using namespace std;
using namespace chrono;
#define ll long long
#define pb push_back
const ll num=15000;

static ll arr[num];

class sorting{
public:
size_t l=0;
size_t h=num-1;
size_t k=num;
void declare(){
    for(size_t i=0;i<num;i++){
        arr[i]=rand()%1000;
    }
}

//BUBBLE SORT
//time complexity: O(n^2)

void bubble_sort(){
    for(size_t i=0;i<num-1;i++){
        size_t count=0;
        for(size_t j=0;j<num-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                count++;
            }
        }
        if(count==0){
            return; //array is sorted if it does not make even one swap in a pass
        }
    }
}

//SELECTION SORT
//time complexity: O(n^2)
//2 arrays maintained-> one which is already sorted and one in which we are finding minimum element

void selection_sort(){
    for(size_t i=0;i<num-1;i++){
        ll minm=arr[i];
        ll x=i;
        for(size_t j=i+1;j<num;j++){
            minm= min(arr[j],minm);
            if(minm==arr[j]){
                x=j;
            }
        }
        if(i!=x){
            swap(arr[i],arr[x]);
        }
    }
}

//INSERTION SORT
//time complexity: O(n^2) worst case and O(n) best case

void insertion_sort(){
    for(ll i=1;i<num;i++){
        ll key=arr[i];
        ll j=i-1;
        while(j>=0 &&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//QUICK SORT
//time complexity: O(nlogn)
//returning the index of the pivot element after partition

size_t hoarse_part(size_t l,size_t h){
    size_t pivot=arr[l]; //pivot chosen to be the high index
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
    }
}

//we perform partition first and then quick sort again on those partitions
void quick_sort(ll l,ll h){
    if(l<h){
     ll p=hoarse_part(l,h);
     quick_sort(l,p);
     quick_sort(p+1,h);
    }
}

//MERGE SORT
//merging 2 seperately sorted arrays
//merge function
//Time complexity: O(nlogn)

void merge(ll low,ll mid,ll high){
ll i=low;
ll j=mid+1;
ll k=0;
ll m=mid-low+1;
ll n=high-mid;
ll b[m+n];

while(i<=mid && j<=high){
    if(arr[i]<=arr[j]){
        b[k]=arr[i];
        i++;
        k++;
    }
    else{
        b[k]=arr[j];
        j++;
        k++;
    }
}
while(j<=high){
        b[k]=arr[j];
        j++;
        k++;
}
while(i<=mid){
        b[k]=arr[i];
        i++;
        k++;
}
for(ll x = 0; x < k; x++) {
        arr[low + x] = b[x];
}
}

void merge_sort(ll l,ll h){
    if(h>l){
        ll  m=(h+l)/2;
        merge_sort(l,m);
        merge_sort(m+1,h);
        merge(l,m,h);
    }
}

//RADIX SORT (uses counting sort)
//time complexity -> O(n)+O((n+b)*d) = O(d*(n+b)) numbers in base b, b=10 here

void count_sort(int exp){
     int count[10]={0}; //as we are considering single digits of the number
    for(ll i=0;i<num;i++){
        count[(arr[i]/exp)%10]++;
        //to take only single digits of the number
    }
    for(int i=1;i<10;i++){
        count[i]=count[i-1]+count[i];
        //finding cumulative sums of the number of elements smaller than or equal to the given number
    }
    int output[num];
    for(int i=num-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<num;i++){
        arr[i]=output[i];
    }

}

//sort the array digit wise, starting from the last to the first digit
void radix_sort(){
    ll maxm=arr[0];
    for(ll i=0;i<num;i++){
        maxm=max(maxm,arr[i]);
    }

    //number of digits in maxm are largest, so loop till maxm/exp!=0
    for(ll exp=1;maxm/exp>0;exp=exp*10){
        count_sort(exp);
    }
}

//BUCKET SORT
//time complexity: O(nlogn) worst case and O(n) best case

void bucket_sort(){
    ll maxm=INT_MIN;
    for(ll i=0;i<num;i++){
        maxm=max(maxm,arr[i]);
    }
    maxm++;
    vector<ll> bck[k]; //array of vectors
    for(ll i=0;i<num;i++){
        ll b=(k*arr[i])/maxm; //number goes to which bucket
        bck[b].pb(arr[i]);
    }
    for(ll i=0;i<k;i++){
        sort(bck[i].begin(),bck[i].end());
    }

    ll z=0;
    for(ll i=0;i<k;i++){
        for(ll j=0;j<bck[i].size();j++){
            arr[z]=bck[i][j];
            z++;
        }
    }
}

//print the sorted array
void print(){
    cout<<"The sorted array is: ";
    for(size_t i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
}
};

int main(){
  ios::sync_with_stdio(false);
  cout<<"Enter 1 for bubble sort"<<endl;
  cout<<"Enter 2 for selection sort"<<endl;
  cout<<"Enter 3 for insertion sort"<<endl;
  cout<<"Enter 4 for quick sort"<<endl;
  cout<<"Enter 5 for merge sort"<<endl;
  cout<<"Enter 6 for radix sort"<<endl;
  cout<<"Enter 7 for bucket sort"<<endl;
  int k;
  cout<<"PRESS key: ";
  cin>>k;

  switch(k){
    case 1:{
    sorting bubble;
    bubble.declare();
    auto start=high_resolution_clock::now();
    bubble.bubble_sort();
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"the time taken by bubble sort is: "<<duration.count()<<" nanoseconds "<<endl;
    bubble.print();
    break;
    }

    case 2:{
    sorting selection;
    selection.declare();
    auto start=high_resolution_clock::now();
    selection.selection_sort();
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"the time taken by selection sort is: "<<duration.count()<<" nanoseconds "<<endl;
    selection.print();
    break;
    }

    case 3:{
    sorting insertion;
    insertion.declare();
    auto start=high_resolution_clock::now();
    insertion.insertion_sort();
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"the time taken by insertion sort is: "<<duration.count()<<" nanoseconds "<<endl;
    insertion.print();
    break;
    }

    case 4:{
    sorting quick;
    quick.declare();
    auto start=high_resolution_clock::now();
    quick.quick_sort(quick.l,quick.h);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"the time taken by quick sort is: "<<duration.count()<<" nanoseconds "<<endl;
    quick.print();
    break;
}

    case 5:{
    sorting merging;
    merging.declare();
    auto start=high_resolution_clock::now();
    merging.merge_sort(merging.l,merging.h);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"the time taken by merge sort is: "<<duration.count()<<" nanoseconds "<<endl;
    merging.print();
    break;
    }

    case 6:{
    sorting radix;
    radix.declare();
    auto start=high_resolution_clock::now();
    radix.radix_sort();
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"the time taken by radix sort is: "<<duration.count()<<" nanoseconds "<<endl;
    radix.print();
    break;
    }

    case 7:{
    sorting bucket;
    bucket.declare();
    auto start=high_resolution_clock::now();
    bucket.bucket_sort();
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(end-start);
    cout<<"the time taken by bucket sort is: "<<duration.count()<<" nanoseconds "<<endl;
    bucket.print();
    break;
    }
  }
}
