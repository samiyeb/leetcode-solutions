#include <vector>
using namespace std;

class Solution {
int count;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0;
        calculate(nums, target, 0, 0);
        return count;
    }

private:
    void calculate(vector<int>& nums, int target, int ptr, int acc) {
        if (ptr == nums.size()) {
            if (acc == target) {count++;}
            return;
        }

        calculate(nums, target, ptr + 1, acc + nums[ptr]);
        calculate(nums, target, ptr + 1, acc - nums[ptr]);
    }
};