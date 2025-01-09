#include <vector>
using namespace std;
class MyHashSet {
public:
    vector<bool> s;
    MyHashSet() {
        s = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        s[key] = true;
    }
    
    void remove(int key) {
        s[key] = false;
    }
    
    bool contains(int key) {
       return s[key]; 
    }
};