#include <bits/stdc++.h>
using namespace std;

// Basic template of interval
struct interval{
    int s; // Indicates start of interval
    int e; // Indicates end of interval
};

// Displays element
void traversel(interval A[], int n){
    for(int i=0; i<n; i++){
        cout<<"["<<A[i].s<<", "<<A[i].e<<"]"<<" ";
    }
}

// Compares interval
bool intervalComp(interval interval1, interval interval2){
    return interval1.s < interval2.s;
}

// Merge's intervals to array ~ O(n*logn) & O(1)
// Insteading of index variable, stack can also be used or vector, etc but not recommanded as S.C becomes O(n)
void mergeIntervals(interval A[], int n){
    // Edge Case
    if(n<=0){
        cout<<"zerod array or no intervals exist";
    }
    // Sort the array
    sort(A, A+n, intervalComp); // Takes O(n*logn) T.C

    int index = 0; // Stores indeces of resultant array ~ for modified array with interval values, if exist

    // Iterate all intervals
    for(int i=1; i<n; i++){
        
        // When interval1's end is greater than interval2's start hence interval exist
        if(A[index].e >= A[i].s){
            // Merge previous & current interval
            A[index].e = max(A[index].e, A[i].e);
        }
        else{
            // Take this current interval to modifying array
            index++;
            A[index] = A[i];
        }
    }

    // Now display the modified array of merge intervals
    for(int i=0; i<=index; i++){
        cout<<"["<<A[i].s<<", "<<A[i].e<<"]"<<endl;
    }
}

// Driver code
int main(){
    interval A[] = { {6, 8}, {1, 9}, {2, 4}, {4, 7} };
    int n = 4;

    traversel(A, n);
    cout<<endl;
    mergeIntervals(A, n);
    return 0;
}