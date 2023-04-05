// Program to find kth smallest number using maxHeap
#include <bits/stdc++.h>
using namespace std;

// Function to find kth smallest element to array | T.C ~ O(n*log*(k+1) = O(n*logk) : where k defines value of k
int find_KthSmallest(int *A, int k, int size){
    priority_queue<int> maxHeap;

        // Iterate array 
        for(int i=0; i<size; i++){
            maxHeap.push(A[i]);
            if(maxHeap.size() > k){
                // Highest element will get popped as its maxHeap
                maxHeap.pop();
            }
        }
        // Maxheap's top is the highest element of it
    return maxHeap.top();
}

// Driver code
int main(){
    int k = 4;
    int A[5] = {5, 7, 2, 3, 8};
    cout<<"K : "<<k;

    // Function call
    int kthVal = find_KthSmallest(A, k, 5);
    cout<<"\nKth Smallest Element is : "<<kthVal;
    return 0;
}