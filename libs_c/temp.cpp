#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    cout << "\n " << v.size() << " " << v.capacity() << "\n";
    v.reserve(3);
    cout << "\n " << v.size() << " " << v.capacity() << "\n";
    for(int i = 0; i < 5; ++i) v.push_back(i + 1);
    for(int i : v) cout << i << " ";
    cout << "\n " << v.size() << " " << v.capacity();
    v.reserve(0);
    cout << "\n " << v.size() << " " << v.capacity();
    v.reserve(10);
    cout << "\n " << v.size() << " " << v.capacity();

    // v.reserve(10);
    // v.push_back(-1);
    // v.push_back(-2);
    // cout << "\n " << v.size() << " " << v.capacity() << "\n";
    // for(int i : v) cout << i << " ";
    

    

    return 0;
}