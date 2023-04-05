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
    for(int i=0; i<(a->u_size); i++){
        cout<<"enter element at index "<<i<<endl;
        cin>>n;
        (a->ptr)[i] = n;
    }
}

int max(struct array *a){
    int tmp;
    for(int i=0; i<(a->u_size); i++){
        if((a->ptr)[i] > (a->ptr)[i+1]){
            tmp = (a->ptr)[i];
            (a->ptr)[i] = (a->ptr)[i+1];
            (a->ptr)[i+1] = tmp;
        }
    }
    return tmp;
}

int min(struct array *a){
    int tmp;
    for(int i=0; i<(a->u_size); i++){
        if((a->ptr)[i] < (a->ptr)[i+1]){
            tmp = (a->ptr)[i];
            (a->ptr)[i] = (a->ptr)[i+1];
            (a->ptr)[i+1] = tmp;
        }
    }
    return tmp;
}

int main(){
    struct array a;
    createArray(&a);
    setVal(&a);
    cout<<endl;
    int val1 = max(&a);
    cout<<"maximum value "<<val1<<endl;

    cout<<endl;
    int val2 = min(&a);
    cout<<"minimum value "<<val2<<endl;
    return 0;
}
