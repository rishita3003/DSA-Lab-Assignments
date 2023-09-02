//time complexity of O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *a=new int[n]; //assigning memory to the array of size n
    srand(time(0));
    //input the randomly generated array
    for(int i=0;i<n;i++){
        a[i]= (rand())%100;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int temp;
    //if duplicate elements occur then replace them with -1 so that they can be removed later
    for(int i=0;i<n;i++){
        temp=a[i];
        //if arr[i] has been changed to -1 in some prev loop
        if(temp==-1){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(a[j]==temp )
                a[j]=-1;
            }
        }

        //output the new array
        for(int i=0;i<n;i++){
            if(a[i]!=-1){
                cout<<a[i]<<" ";
            }
        }

        //free up the space taken
        delete[] a;
        return 0;
    }

