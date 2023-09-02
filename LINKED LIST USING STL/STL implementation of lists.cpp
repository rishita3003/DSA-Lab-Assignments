/* STL implementation */

#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <sys/time.h>
using namespace std;


void display(list <int> &lst){
    list <int>::iterator it;

    //iterator traversing from the beginning of the list till the end
    for(it=lst.begin();it!=lst.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


int main() {
    list <int> list1; //list of 0 length so we need to push elements in it
    list <int> list2(7); //empty list of size 7 -->memory for 7 is there but no values stored

    //inserting values in the list from back
    struct timeval start,end;
    gettimeofday(&start,NULL);
    ios_base::sync_with_stdio(false);
    list1.push_back(6);
    display(list1);
    gettimeofday(&end,NULL);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
    cout << "Time taken by push function is : " << fixed  << setprecision(20)<< time_taken;
    cout << " sec" << endl;
    list1.push_back(9);
    list1.push_back(5);

    //inserting values in the list from front
    list1.push_front(7);
    list1.push_front(0);
    list1.push_front(2);

    //list2 already has memory allocated so, just assign values
    list <int>:: iterator iter;
    iter=list2.begin();
    *iter=45;
    iter++;
    *iter=90;
    iter++;
    *iter=12;
    iter++;
    *iter=23;
    iter++;
    *iter=87;
    iter++;
    *iter=44;
    iter++;
    *iter=23;
    iter++;

   //DISPLAY CREATED LISTS
   cout<<"list 1 is"<<endl;
   display(list1);

   //size of the list
   cout<<"the number of elements in the first list are: "<<list1.size()<<endl;
   cout<<"list 2 is"<<endl;
   display(list2);

   //Sorting the list
   list1.sort();
   cout<<"after sorting list 1 is:"<<endl;
   display(list1);
   cout<<endl;

   //Returning the first and last value of the lists
   cout<<"the first element of list 2 is: "<<list2.front()<<endl;
   cout<<"the last element of the list 2 is: "<<list2.back()<<endl;

   //Removing elements of the list from the front and the back

    struct timeval start2,end2;
    gettimeofday(&start2,NULL);
    ios_base::sync_with_stdio(false);
    list1.pop_back();
    gettimeofday(&end2,NULL);
    double time_taken2;
    time_taken2 = (end2.tv_sec - start2.tv_sec) * 1e6;
    time_taken2 = (time_taken2 + (end2.tv_usec - start2.tv_usec)) * 1e-6;
    cout << "Time taken by pop function is : " << fixed  << setprecision(20)<< time_taken2;
    cout << " sec" << endl;

   cout<<"the list 1 after removing last element"<<endl;
   display(list1);
   list1.pop_front();
   cout<<"the list 1 after removing first element"<<endl;

   display(list1);

   //Reverse of list
   list2.reverse();
   cout<<"the list 2 in reverse manner is as follows"<<endl;
    struct timeval start3,end3;
    gettimeofday(&start3,NULL);
    ios_base::sync_with_stdio(false);
    display(list2);
    gettimeofday(&end3,NULL);
    double time_taken3;
    time_taken3 = (end3.tv_sec - start3.tv_sec) * 1e6;
    time_taken3 = (time_taken3 + (end3.tv_usec - start3.tv_usec)) * 1e-6;
    cout << "Time taken by display function is : " << fixed  << setprecision(20)<< time_taken3;
    cout << " sec" << endl;


   //Empty list check --> 1 = true and 0=false
   list<int> list3;
   cout<<"the list 3 is empty or not: "<<list3.empty()<<endl;

   //Removing all occurences of a value
   list1.remove(2);
   cout<<"after removing all 2's list 1 is: ";
   display(list1);
   cout<<endl;

}
