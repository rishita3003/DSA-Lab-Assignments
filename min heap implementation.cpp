#include <iostream>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <unordered_set>
#include <set>
#define ll long long
#define inn int64_t
#define vp vector<pair<ll,ll>>
#define pb push_back
#define mp make_pair
const ll num=1e9;
using namespace std;
using namespace std::chrono;

class min_heap{
    public:
    int* heap;
    int size;
    int capacity;

    //constructor to make a min heap directly
    min_heap(int c){
        capacity=c;
        heap=new int[c];
        size=0;
    }

    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    int parent(int i){
        return (i-1)/2;
    }

    //insertion in a heap
    void insert_key(int ele){
        if(size!=capacity){
            //ensuring a complete binary tree -->heap
            size++;
            heap[size-1]=ele;
            int index=size-1;
            //ensuring that it is min heap
            while(heap[parent(index)]>heap[index] && index!=0 ){
                swap(heap[parent(index)],heap[index]);
                index=parent(index);
            }
            return;
        }
        else{
            cout<<"The heap is fully complete!"<<endl;
            return;
        }

    //time complexity of O(log(n))
    }

    //min heapify operation
    void heapify(int i){
        int l=left(i);
        int r=right(i);
        int small=i;
        if(heap[l]<heap[i]&& heap[l]<heap[r]){
            small=l;
        }
        else if(heap[r]<heap[i] && heap[r]<heap[l]){
            small=r;
        }
        if(small!=i){
            swap(heap[i],heap[small]);
            heapify(small);
        }
        else{
            return;
        }

        //time complexity of O(log(n)) --> i.e. function is called max times equal to its height and best case is theta(1)
        //auxilliary space here is O(log(n))
        //auxilliary space can be converted to O(1) by making it an iterative function
    }

    //extract minimum--> remove min element from the heap and return it
    int extract_min(){
        if(size==0){
            return INT_MAX;
        }
        if(size==1){
            size--;
            return heap[0];
        }
        int minm=heap[0];
        swap(heap[0],heap[size-1]);
        size--;
        heapify(0);
        return minm;
    }

    //decrease key operation--> decrease a particular key and rebuild the whole tree
    void decrease_key(int key,int i){
        heap[i]=key;
        while(i!=0 && heap[i]<heap[parent(i)]){
            swap(heap[i],heap[parent(i)]);
            i=parent(i);
        }
        //it takes care of making heap, min heap again
    }

    //delete key
    void delete_key(int i){
        if(size==0){
            cout<<"The heap is already empty!"<<endl;
            return;
        }
        if(size==1){
            size--;
            return;
        }
        decrease_key(INT_MIN,i);
        extract_min();
}

    //print heap
    void print_heap(){
        if(size==0){
            cout<<"The heap is empty!"<<endl;
            return;
        }
        cout<<"The heap is: "<<endl;
        for(int i=0;i<size;i++){
                cout<<heap[i]<<" ";
        int level=floor(log(i+1)/log(2));
            if(level==0 || i==2){
                cout<<endl;
            }
            else if(i==pow(2,level)+pow(2,level-1)){
                    cout<<endl;
            }
        }
        cout<<endl;
    }
    
    //build-heap-->heap using array
    
};


int main(){
    ios::sync_with_stdio(false);
    min_heap mh(10);
    mh.insert_key(40);
    
    auto start1=high_resolution_clock::now();
    mh.insert_key(20);
    auto end1=high_resolution_clock::now();
    auto duration1=duration_cast<nanoseconds>(end1-start1);
    cout<<"The time taken by insert function is: "<<duration1.count()<<" nanoseconds "<<endl;
    mh.insert_key(30);
    mh.insert_key(35);
    mh.insert_key(25);
    mh.insert_key(80);
    mh.insert_key(32);
    mh.insert_key(100);
    mh.insert_key(70);
    mh.insert_key(60);
    //insert function will convert the tree into min heap and print it
    mh.print_heap();

    auto start2=high_resolution_clock::now();
    mh.delete_key(3);
    auto end2=high_resolution_clock::now();
    auto duration2=duration_cast<nanoseconds>(end2-start2);
    cout<<"The time taken by delete function is: "<<duration2.count()<<" nanoseconds "<<endl;
    
    mh.print_heap();
}
