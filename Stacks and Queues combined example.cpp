#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Stacks and queues example */

int main() {
    // Stacks to manage backward and forward navigation for each tab
    stack<string> backwardStack;
    stack<string> forwardStack;

    // Queue to manage the order of tabs opened
    queue<string> tabQueue;

    // Open some tabs
    tabQueue.push("google.com");
    tabQueue.push("example.com");
    tabQueue.push("openai.com");

    // Simulate switching tabs
    string currentTab = tabQueue.front();
    tabQueue.pop();
    cout << "Current Tab: " << currentTab<< endl;

    // User navigates within the current tab
    backwardStack.push(currentTab);  // Current page is pushed onto backward stack
    currentTab = "example.com"; 
    cout << "Current Tab in backward stack: " << currentTab<< endl;

    // User clicks the back button
    if (!backwardStack.empty()) {
        forwardStack.push(currentTab);  // Current page is pushed onto forwardStack
        currentTab = backwardStack.top();  // Pop from backward stack
        backwardStack.pop();
        cout << "Current Tab (after Back): " << currentTab << endl;
    }

    // User clicks the forward button
    if (!forwardStack.empty()) {
        backwardStack.push(currentTab);  // Current page is pushed onto backwardStack
        currentTab = forwardStack.top();  // Pop from forward stack
        forwardStack.pop();
        cout << "Current Tab (after Forward): " << currentTab << endl;
    }
    
    return 0;
}
