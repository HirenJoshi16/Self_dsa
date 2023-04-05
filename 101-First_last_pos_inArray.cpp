//Condition ~ in O(logn) time && O(1) space - Use binary search
#include <iostream>
using namespace std;

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

//uses linearSearch
void lastfirst(int A[], int val, int n){
    int first, last;
    int i=0;
    int j=n-1;

    //In this case the time complexity is O(n), Where O(n+n) = O(2n) = O(n)
    // space complexity is O(1)
    while(A[i] != val && i<=j){
        i++;
    }
    first = i;
    while(A[j] != val && j>i){
        j--;
    }
    last = j;

    if(A[i] != val || A[j] != val){
        first = -1;
        last =  -1;
    }

    cout<<"First Occurance : "<<first;
    cout<<"\nlast Occurance : "<<last;
}

//uses BinarySearch
void first(int A[], int low, int high, int val){
    int first=-1;
    int mid;

        while(low<=high){
            mid = (low+high)/2;
            if(A[mid]==val){
                first = mid;
                high = mid-1;
            }
            if(A[mid]>val){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    cout<<"First Occurance : "<<first;
}

//uses BinarySearch
void last(int A[], int low, int high, int val){
int last=-1;
int mid;

    while(low<=high){

        mid=(low+high)/2;
        if(A[mid] == val){
            last = mid;
            low = mid+1;
        }
        if(A[mid] > val){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    cout<<"\nlast Occurance : "<<last;
}

int main(){
    // int A[] = {10, 78, 32, 35, 11, 45, 30, 11, 20, 11};
    int A[] = {10, 20, 30, 40, 50, 50, 50, 80, 90, 100};
    int n=10;
    int val = 50;
    printArray(A, n);
    cout<<endl;
    first(A, 0, n-1, val);
    last(A, 0, n-1, val);
    return 0;
}