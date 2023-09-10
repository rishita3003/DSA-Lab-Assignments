#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/* Queues example */
/*This example is of the traffic light. The cars keep standing in the queue until the light is red and then the first car in the queue pops out first when the light turns green */

class traffic{
    public:
    queue<string> q;
    
    void red(string s){
        q.push(s);
        cout<<"The vehicle added in the queue is: "<<s<<endl;
    }
    
    void green(){
        if(q.empty()){
            cout<<"There is no vehicle in the line!"<<endl;
            return;
        }
        else{
            string vehicle=q.front();
            q.pop();
            cout<<"The vehicle which gets out the traffic now is: "<<vehicle<<endl;
        }
        return;
    }
};

int main() {
    traffic traf;
    
    traf.red("Mercedes");
    traf.red("Audi");
    traf.green();
    traf.red("BMW");
    traf.green();
    traf.green();
    traf.green();
    
}