// Program to search element in matrix - coded by vHiren
#include <iostream>
#include <unordered_set>
using namespace std;

// Finds element in matrix ~ Naive Approach - O(n*m) & O(n) 
bool findinMatrix1(int A[3][3], int element){
    unordered_set<int> uSet;  

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                uSet.insert(A[i][j]);
            }
        }

        if(uSet.find(element) != uSet.end()){
            return true;
        }
    return false;
}

// Finds element in matrix ~ Naive Approach - O(n*m) & O(1) 
bool findinMatrix2(int A[][3], int element){
    int flag=0;
    for(int i=0; i<3; i++){
        flag=0;
        for(int j=0; j<3; j++){
            if(A[i][j] == element){
                flag=1;
            }
        }
        if(flag==1){
            return true;
        }
    }
    return false;
}

// Driver code
int main(){
    int A[3][3];
    // Input matrix
    cout<<"Enter Matrix : "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>A[i][j];
        }
    }

    int element;
    cout<<"Enter Element : ";
    cin>>element;
    if(findinMatrix2(A, element)){
        cout<<"element found";
    }
    else{
        cout<<"element not found";
    }
    
    return 0;
}