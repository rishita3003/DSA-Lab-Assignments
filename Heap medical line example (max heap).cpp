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

//Example for heap
//The highest priority patient in the medical line
//Patients are numbered as their priority

class max_heap{
    public:
    int* heap;
    int size;
    int capacity;

    max_heap(int c){
        capacity=c;
        heap=new int[c];
        size=0;
    }

    int  left(int i){
        return (2*i+1);
    }

    int right(int i){
        return (2*i+2);
    }

    int parent(int i){
        return (i-1)/2;
    }


    //higher priority patients are checked first
    //insert patients in the queue acco. to their priority
    void insert_key(int ele){
        cout<<"Insert patient with priority "<<ele<<" in the list"<<endl;
        if(size!=capacity){
            heap[size]=ele;
            size++;
            int index=size-1;

            //ensuring max heap
            while(heap[index]>heap[parent(index)] && index!=0){
                swap(heap[index],heap[parent(index)]);
                index=parent(index);
            }
            return;
        }
        else{
            cout<<"No more patients can be added"<<endl;
            return;
        }
    }

    //everytime a patient is treated, the priority queue is to be updated
    void heapify(int i){
        int l=left(i);
        int r=right(i);
        int large=i;
        if(heap[l]>heap[i] && heap[l]>heap[r]){
            large=l;
        }
        else if(heap[r]>heap[i] && heap[r]>heap[l]){
            large=r;
        }
        if(large!=i){
            swap(heap[i],heap[large]);
            heapify(large);
        }
    }

    // to select the patient to be treated first
    int extract_max(){
        cout<<"The patient who will be treated now is: ";
        if(size==0){
            return INT_MIN;
        }
        if(size==1){
            size--;
            return heap[0];
        }
        int maxm=heap[0];
        heap[0]=heap[size-1];
        size--;
        heapify(0);
        return maxm;
    }

    //If it becomes urgent to treat a lower priority patient
    //no new patient added -> just priority of a patient in list is increased
    
    void increase_key(int key,int i){
        cout<<"Increased the priority of patient "<<i<<" to "<<key<<endl;
        heap[i]=key;
        while(heap[i]>heap[parent(i)] && i!=0){
            swap(heap[i],heap[parent(i)]);
            i=parent(i);
        }
    }

    void delete_key(int i){
        if(size==0){
            cout<<"The list is already empty."<<endl;
            return;
        }
        if(size==1){
            size--;
            return;
        }
        increase_key(INT_MAX,i);
        extract_max();
    }

    //print heap

    void print_heap(){
        if(size==0){
            cout<<"No patients in the list."<<endl;
            return;
        }
        cout<<"The list of patients is: "<<endl;
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
};


int main(){
    ios::sync_with_stdio(false);
    max_heap mh(10);
    mh.insert_key(5);
    mh.insert_key(4);
    mh.insert_key(2);
    mh.insert_key(3);
    cout<<mh.extract_max()<<endl;
    mh.insert_key(1);
    mh.insert_key(6);
    mh.print_heap();
    cout<<mh.extract_max()<<endl;
    mh.print_heap();
    mh.increase_key(7,2);
    mh.print_heap();
    cout<<mh.extract_max()<<endl;
    mh.print_heap();

}
