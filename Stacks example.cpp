#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* Stacks example */
/* This is the example of GPS navigation system in which we can navigate to a location or we can go back to the previous/last location visited */

class GPS{
    public:
    stack<string> route;
    
void to(string location){
    cout<<"Navigating to: "<<location<<endl;
    route.push(location);
    return;
}

void backto(){
    if(!route.empty()){
        string prev=route.top();
        route.pop();
        cout<<"going back to "<<prev<<endl;
    }
    else{
        cout<<"no previous locations in the route!"<<endl;
    }
    return;
}
};

int main() {
    GPS gps;
    gps.to("Home");
    gps.to("Denmark");
    gps.to("College");
    
    gps.backto();
    gps.backto();
    gps.backto();
    
    return 0;
}