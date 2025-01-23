#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> start;
        backtrack(start, nums, 0);
        return res;

        
    }

private:
    void backtrack(vector<int> curr, vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(curr, nums, i+1);
        curr.pop_back();
        backtrack(curr, nums, i+1);
    }
};