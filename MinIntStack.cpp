#include <bits/stdc++.h>

class Stack {
    unsigned int _size;
    int* arr;
    
    public:
    int top = -1;
    int min = INT_MAX;
    
    public:
    
    Stack() {
        _size = 0;
        arr = new int[0];
    }
    
    Stack(unsigned int s) : _size(s) {
        arr = new int[_size];
    }
    
    ~Stack() {
        delete[] arr;
        arr = nullptr;
    }
    
    void push(int);
    int pop();
    void display();
    constexpr inline int getMin() { return min; }
    constexpr inline int getTop() { return arr[top]; }
};

void Stack :: push(int d) {
    if(top == _size) {
        std::cout << "Err";
        return;
    } else {
        arr[++top] = d; 
        if(d < min) min = d;
    }
}

int Stack :: pop() { 
    if(top == 0) { 
        std::cout << "Err";
        return -1;
    } else return --top;
}

void Stack :: display() {
    std::cout << "\n";
    for(int i = top; i >= 0; --i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    
    Stack s(2);
    
    s.push(14);
    s.push(11);
    s.display();
    
    std::cout << "\n Min: " << s.getMin();
    s.push(20);
    s.display();
    std::cout << "\n Min: " << s.getMin();
    
    std::cout << "\n Top:" << s.getTop() << "\n";
    
    return 0;
}

