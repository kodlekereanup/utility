#include <iostream>
#include <vector>

namespace sct {
    class String {
        unsigned int _size;
        char* _buffer;
        
        public:
        String() {
            _size = 0;
            _buffer = nullptr;
        }
        
        String(const char* string) {
            _size = len(string);
            _buffer = new char[_size + 1];
            for(int i = 0; i < _size; i++) _buffer[i] = string[i];
            _buffer[_size] = 0;
        }
        
        friend std::ostream& operator<< (std::ostream& out, const String& str) {
            out << str._buffer;
            return out;
        }
        
        constexpr unsigned int len(const char* string) {
            int len = 0;
            for(int i = 0; string[i] != '\0';  i++) len++;
            return len;
        }
        
        constexpr inline unsigned int len() { return _size; }
        
        // copy constructor
        // assignment operator
        // +
        
        // is this safe? 
        String& operator+= (const String& other) {
            int oldSize = _size;
            _size += other._size;
            for(int i = oldSize, j = 0; j < other._size; i++, j++) _buffer[i] = other._buffer[j];
            return *this;
        }
        
        ~String() { 
            delete[] _buffer;  //avoids mem leaks
            _buffer = nullptr; // avoids dangling pointers
        }
    };
    
    //class Vector; 
    //class Vector3 : public Vector {
      // mathematical vector of 3 dimensions
    //};
    
    class D_Array { // c++ vector equivalent 
        int _size;
        int _max;
        int* arr;
        
        public:
        D_Array() {
            _size = 0;
            _max = 1;
            arr = new int[_size];
        }
        
        // create a vector of size s
        // todo, has problem
        D_Array(const unsigned int& s) {
            _size = s;
            _max = s;
            arr = new int[_size];
        } 
        
        D_Array(const unsigned int& s, const int& filler); // create a vector of size s and fill it with fillers
        
        // push_back 
        void push(int data) {
            //check if the max is reached
            if(_size == _max) {
                int* temp = new int[2 * _max];
                
                // copy the old array 
                for(int i = 0; i < _max; i++) temp[i] = arr[i];
                delete[] arr;
                _max *= 2;
                arr = temp;
            }
            
            arr[_size] = data;
            _size++;
        }
        
        const int& operator[] (unsigned int i) { return arr[i]; }
        
        constexpr inline unsigned int size()     { return _size; }
        constexpr inline unsigned int capacity() { return _max;  }
        
        ~D_Array() {
            delete[] arr;
            arr = nullptr;
        }
        
    };
}

int main() {
    
    sct::D_Array vec(3);
    
    for(int i = 0; i < 3; i++) vec.push(i);
    
    for(int i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << vec.size() << " " << vec.capacity() << "\n";
    
    std::vector<int> v(3); // doesnt just reserve 3 memory locations but also constructs it //
    std::cout << v.size() << " " << v.capacity() << "\n";
    
    for(int i : v) std::cout << i << " ";
    
    v.push_back(0); v.push_back(1); v.push_back(2);
    for(int i : v) std::cout << i << " ";
    
    return 0;
}
