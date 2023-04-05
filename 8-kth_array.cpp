#include <iostream>
#include <stdlib.h>
using namespace std;

struct array{
    int t_size;
    int u_size;
    int *ptr;
};

void createArray(struct array *a){
    a->t_size = 10;
    a->u_size = 5;
    a->ptr = (int*)malloc(sizeof(int)*(a->t_size));
}

void Traversel(struct array *a){
    for(int i=0; i<(a->u_size); i++){
        cout<<"index "<<i<<" element "<<(a->ptr)[i]<<endl;
    }
}

void setVal(struct array *a){
    int n;
    cout<<"enter elements :"<<endl;
    for(int i=0; i<(a->u_size); i++){
        cin>>n;
        (a->ptr)[i] = n;
    }
}

void arrayKth(struct array *a){
    int val1, val2;
    cout<<"Enter value of K for largest number : ";
    cin>>val1;
    cout<<val1<<" larget number is : "<<(a->ptr)[a->u_size-val1]<<endl;

    cout<<"Enter value of K for smallest number : ";
    cin>>val2;
    cout<<val2<<" smallest number is : "<<(a->ptr)[val2-1]<<endl;
}

void sort(struct array *a){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < (a->u_size)-1; i++) // For number of pass
    {
        isSorted = 1;
        for (int j = 0; j <(a->u_size)-1-i ; j++) // For comparison in each pass
        {
            if((a->ptr)[j]>(a->ptr)[j+1]){
                temp = (a->ptr)[j];
                (a->ptr)[j] = (a->ptr)[j+1];
                (a->ptr)[j+1] = temp;
                isSorted = 0;
            }
        } 
        if(isSorted){
            return;
        }
    } 
}

int main(){
    struct array a;
    createArray(&a);
    setVal(&a);
    // Traversel(&a);
    // cout<<endl;
    sort(&a);
    arrayKth(&a);
    // Traversel(&a);
    return 0;
}
