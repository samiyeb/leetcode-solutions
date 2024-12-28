#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_max = 0;

        for (int i = 0; i < nums.size(); i++) {
            cur_max = max(cur_max-1, nums[i]);

            if (cur_max == 0 && i + 1 < nums.size()) {
                return false;
            }
        }

        return true;
        
    }
};