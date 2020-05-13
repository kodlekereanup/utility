/*
 * GENERIC_STACK.CPP 
 * @author: ANUP KODLEKERE
 * @date  : April 2020
 * About  : This is a toy implementation of STL_STACK.H from the C++ STL
            just to be able to better understand the underlying implementation
            of the container
 * Takeaway: The STL version is obviosly optimzed. Also, the stack file actually
             implements a std::deque<T> container (shocker). 
             Also that it doesn't have a capacity parameter
*/             

#include <iostream>
#include <string>

template <class T>
class Stack {
    unsigned int _size;
    int _top = -1;
    int _capacity;
    T* _buffer;
    
    public:
    Stack();
    Stack(unsigned int);
    ~Stack();

    void push(const T&);
    T pop(); // pops and returns the popped element

    constexpr unsigned int size();
    constexpr unsigned int capacity();
    constexpr int top(); // returns the position of top //
    constexpr T peek();  // returns the element at the top // 
    constexpr bool isEmpty();
    const void display();
};

// Default Constructor
template <class T>
Stack<T> :: Stack() :
    _size(0), _capacity(0), _buffer(nullptr) {}

// Destructor
template <class T>
Stack<T> :: ~Stack() {
    delete[] _buffer;
    _buffer = nullptr;
}

template <class T>
constexpr unsigned int Stack<T> :: size() { return _size; }

template <class T>
constexpr unsigned int Stack<T> :: capacity() { return _capacity; }

// Size Constructor
template <class T>
Stack<T> :: Stack(unsigned int s) :
    _size(s), _buffer(new T[s]) {}

template <class T>
void Stack<T> :: push(const T& data) {
    if(_top == _capacity - 1) {
        _capacity *= 2;
        if(_capacity == 0) _capacity++;
        T* new_buffer = new T[_capacity];
        //copy the old array
        for(int i = 0; i < _size; i++) new_buffer[i] = _buffer[i];
        delete[] _buffer;
        _buffer = new_buffer;
    } 
    _size++;
    _buffer[++_top] = data;
}

template <class T>
constexpr int Stack<T> :: top() { return _top; }

template <class T>
constexpr T Stack<T>:: peek() { return _buffer[_top]; }

template <class T>
constexpr bool Stack<T> :: isEmpty() { return _top == -1; }

template <class T>
T Stack<T> :: pop() {
    if(isEmpty()) {
        std::cout << "Stack Underflow: Exiting...";
        exit(EXIT_FAILURE);
    } else {
        --_size;
        return _buffer[_top--];
    }
}

template <class T>
const void Stack<T> :: display() {
    std::cout << '\n';
    for(int i = _top; i >=0; --i) std::cout << _buffer[i] << " ";
    std::cout << '\n';
}

int main() {

    Stack<std::string> s;
    std::cout << "\n" << s.size() << " " << s.capacity();
    s.push("String");

    s.push("World");
    s.display();
    std::cout << "\n" << s.size() << " " << s.capacity();

    s.pop();
    s.display();
    std::cout << "\n" << s.size() << " " << s.capacity();

    s.pop();
    s.display();
    std::cout << "\n" << s.size() << " " << s.capacity();
    std::cout << '\n' << s.top();
    return 0;
}
// TODO: After top becomes -1, destoy / free the capacity
//       The capacity remains the same even after the stack
//       becomes empty
