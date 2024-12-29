#include <vector>
using namespace std;
class MyHashSet {
public:
    vector<bool> hashset;
    MyHashSet() {
        for (int i = 0; i < 1000000; i++) {
            hashset.push_back(false);
        }
    }
    void add(int key) {
        hashset[key] = true;
    }
    
    void remove(int key) {
        hashset[key] = false;
    }
    
    bool contains(int key) {
        return hashset[key];
    }
};