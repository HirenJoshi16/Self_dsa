#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

// ~ O(lst + stack operations in worst case scenerio) & O(vec+sp) --> O(n) & O(n)
// T.C Explanation : https://leetcode.com/problems/next-greater-node-in-linked-list/solutions/2722756/next-greater-node-in-linked-list/

// Function to find next greater node of each node in list ~ O(n) & O(n)
auto nextGreaterNode(list<int> lst){
    int position = -1;
    int index;
    // Initializing vector & stack of pair
    vector<int> vec;
    stack<pair<int, int> > sp;

    // Creating an iterator
    list<int> :: iterator it;

    // Iterate list
    for(it=lst.begin(); it!=lst.end(); it++){
        // Increase position each time & make all the elments 0 in vec
        position += 1; 
        vec.push_back(0);
        int currElement = *it;

            // If current list element is greater than stack top - then pop the stackTop   
            while(!sp.empty() && sp.top().second < currElement){
                // Storing index of stackTop element. So, to Store current list element to this index in vec
                index = sp.top().first;
    
                sp.pop();
                // Storing current list element to this index in vec
                vec.at(index) = currElement;
            }

        // Pushing current list element to stack in each iteration
        sp.push({position, currElement});
    }
    return vec;
}

// Driver code
int main(){
    // Initializing list
    list<int> lst{8, 9, 10, 3, 5, 1};

    // Function call
    vector<int> vec = nextGreaterNode(lst);
    // Printing elements
    for(auto i : vec){
        cout<<i<<" ";
    }

    return 0;
}