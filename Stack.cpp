#include <bits/stdc++.h>

// Integer stack only, make it generic

class Stack {
    int _size;
    int* arr;
    public:
    int top = 0;
    int min;
    
    public:
    Stack() {
        _size = 0;
        arr = new int[0];
    }
    Stack(int s) : _size(s) {
        arr = new int[_size];
    }
    
    // ~Stack() {
    //     delete[] arr;
    //     arr = nullptr;
    // }
    
    void push(int);
    int pop();
    void display();
};

void Stack :: push(int d) {
    if(top == _size) {
        std::cout << "Err";
        return;
    } else arr[++top] = d; 
}

int Stack :: pop() { 
    if(top == 0) std::cout << "Err";
    else { 
        --top;
        return top;
    }
    return -1;
}

void Stack :: display() {
    for(int i = top; i >= 0; --i) std::cout << arr[i] << " ";
}

int main() {
    
    Stack s(2);
    
    s.push(1);
    s.push(2);
    s.display();
    
    
    return 0;
}