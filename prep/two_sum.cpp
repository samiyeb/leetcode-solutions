#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (map.find(diff) != map.end()) {
                return vector<int>{map[diff], i};
            }

            map[nums[i]] = i;
        }

        return vector<int>{-1, -1};
        
    }
};