// Implementation of stack using array
#include <iostream>
#include <malloc.h>
using namespace std;

//Basic Template
struct stack{
    int top;
    int size;
    int *arr;
};

// Checks stack is empty or not
bool isEmpty(struct stack *s){
    if(s->top <= -1){
        return true;
    }
    return false;
}

// Checks stack is full or not
bool isFull(struct stack *s){
    if(s->top >= s->size-1){
        return true;
    }
    return false;
}

// inserts element to the stack
void push(struct stack *s, int key){
    if(isFull(s)){
        cout<<"Stack overflow!";
    }
    else{
        s->top++;
        s->arr[s->top] = key;
    }
}

// removes element to the stack
void pop(struct stack *s){
    if(isEmpty(s)){
        cout<<"Stack underflow!";
    }
    else{
        int key = s->arr[s->top];
        s->top--;
    }
}

// Traverses each element
void traversel(struct stack *s){
    for(int i=0; i<=s->top; i++){
        cout<<s->arr[i]<<" ";
    }
}

int main(){
    // Creating a stack and allocating memory dynamically
    struct stack s;
    s.size = 5;
    s.top = -1;
    s.arr = new int[s.size];
    cout<<"stack has been created successfully!"<<endl;

    // Pushing elements to the stack
    push(&s, 45);
    push(&s, 20);
    push(&s, 65);
    push(&s, 15);
    push(&s, 30);
    traversel(&s);
    cout<<endl;

    // Poping elements to the stack
    pop(&s);
    pop(&s);
    pop(&s);
    traversel(&s);
    return 0;
}