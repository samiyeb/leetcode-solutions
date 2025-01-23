#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;
class RandomizedSet {
public:
    map<int,int> num_to_index;
    vector<int> nums;
    RandomizedSet() {}
    
    bool insert(int val) {
        if (num_to_index.find(val) != num_to_index.end()) {
            return false;
        }

        nums.push_back(val);
        num_to_index[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!(num_to_index.find(val) != num_to_index.end())) {
            return false;
        }

        int last_value = nums.back();
        int last_values_new_index = num_to_index[val];
        num_to_index[last_value] = last_values_new_index;
        nums[last_values_new_index] = last_value;
        nums.pop_back();
        num_to_index.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
        
    }
};