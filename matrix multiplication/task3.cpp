//time complexity is O(m*n*p)

#include <bits/stdc++.h>
using namespace std;

int main() {
   //matrix multiplication
   int m,n,p;
   cin>>m>>n>>p;

   //a[m][n], b[n][p], c[m][p]
   //allocating memory to the 2D arrays
   //a is a matrix which is an array of rows which themselves are separate arrays
   //so row names can be used as pointer
   long long** a=new long long*[m] ;
   for(int i=0;i<m;i++){
    a[i]=new long long[n];
   }
   long long** b=new long long*[n];
   for(int i=0;i<n;i++){
    b[i]=new long long[p];
   }
   long long** c=new long long*[m] ;
   for(int i=0;i<m;i++){
    c[i]=new long long[p];
   }
   cout<<"matrix a is: "<<endl;
   srand(time(0));
   for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //randomly generating values of the arrays
            a[i][j]=rand();
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
   }
   cout<<"matrix b is: "<<endl;
   for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
          b[i][j]=rand();
          cout<<b[i][j]<<" ";
        }
        cout<<endl;
   }

   for(int i=0;i<m;i++){
       for(int j=0;j<p;j++){
           c[i][j]=0;
           for(int k=0;k<n;k++){
                //matrix multiplication algo
               c[i][j]+=a[i][k]*b[k][j];
           }
       }
   }
   cout<<"matrix c is: "<<endl;
   for(int i=0;i<m;i++){
       for(int j=0;j<p;j++){
           cout<<c[i][j]<<" ";
       }
       cout<<endl;
   }

   //free the allocated memory
   for(int i=0;i<m;i++){
    //deleting the row arrays first
    delete[] a[i];
    delete[] c[i];
   }
   for(int i=0;i<n;i++){
    delete[] b[i];
   }

   //deleting full array
   delete[] a;
   delete[] b;
   delete[] c;

   return 0;

}
