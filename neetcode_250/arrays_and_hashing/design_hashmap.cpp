#include <vector>
class MyHashMap {
public:
    std::vector<int> map;
    MyHashMap() {
        map = std::vector<int>(1000001, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};