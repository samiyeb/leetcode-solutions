#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hashset;

        for (int num : nums) {
            if (hashset.find(num) != hashset.end()) {
                return true;
            }
            hashset.insert(num);
        }

        return false;
        
    }
};