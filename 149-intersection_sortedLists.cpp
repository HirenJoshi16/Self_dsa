// Program to find intersection of two sorted list ~ O(n+m) & O(n+m) : coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Finds intersection of lists
void interSection(list<int> &lst1, list<int> &lst2){
    // Edge case
    if(!head) return head;
    unordered_set<int> uset; // Creating set

    // Inserts list1 elements to uset
    for(auto &i : lst1){
        // Can also be written as (auto i : lst1) by using ampersand
        uset.insert(i);
    }
    // Finds element to uset of list2
    for(auto &i : lst2){
        if(uset.find(i) != uset.end()){
            cout<<i<<" ";
        }
    }
}

// Display elements of list
void traversel(list<int> lst){
    list<int> :: iterator it;    
    for(it = lst.begin(); it!=lst.end(); it++){
        cout<<*it<<" ";
    }
}

// Driver code
int main(){
    list<int> lst1 = {1, 2, 3, 4, 6};
    list<int> lst2 = {2, 4, 6, 8, 9, 10};

    traversel(lst1);
    cout<<"  ";
    traversel(lst2);
    cout<<endl;
    interSection(lst1, lst2);
    return 0;
}