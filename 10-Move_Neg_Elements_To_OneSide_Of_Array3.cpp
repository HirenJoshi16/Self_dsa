//coded by hiren
#include <iostream>
#define size 6
using namespace std;

int main(){
    int i=0, j=0;
    int tmp;
    int arr[size] = {4, -3, 1, -10, 5, -7};

    cout<<"elements :"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

        while(j <= size-1){
            if(arr[j] < 0){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
            }
            j++;
        }
        
    cout<<"\nelements :"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}