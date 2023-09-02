//time complexity is O(n) ; where n is the length of the string
#include <bits/stdc++.h>
using namespace std;
int main() {
    //for self input string--> input number as a string
    string a;
    cin>>a;
    int count=0;

    for(int i=0;i<(a.length());i++){
            //checking if the first and the last digit of the string are same or not
            if(a[i]==a[a.length()-i-1]){
                count++;
            }
            else{
                cout<<"NOT A PALINDROME";
                break;
            }
    }
    if(count==a.length()){
        cout<<"IT IS A PALINDROME";
    }

    return 0;

}

