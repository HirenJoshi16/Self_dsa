// Program to verify given two array have a valid stack sequence or not ~ coded by Hiren
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Method to print vector
void printVector(vector<int> nums){
    for(auto val : nums)
        cout<<val<<" ";
        
    cout<<"     ";
}

// Method to verify given two array have a valid stack sequence or not - O(N) & O(N)
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    stack<int> st;
    int i = 0; // Tracks element to be pushed
    int j = 0; // Tracks element to be popped

    while(i < n && j < n){
        st.push(pushed[i]); // Push the element

        // Pop correctly when stack is not empty
        while(!st.empty() && j < n && popped[j] == st.top()){ 
            st.pop();
            j++;
        }
        i++;
    }
    return st.empty(); // If empty it means both the array have a valid stack sequence 
}

// Driver code
int main(){
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 5, 3, 2, 1};
    // Printing vector
    printVector(pushed); 
    printVector(popped);

    cout<<'\n';
    // Method call
    if(validateStackSequences(pushed, popped))
        cout<<"Valid stack sequence";
    else
        cout<<"Not a valid stack sequence";

    return 0;
}