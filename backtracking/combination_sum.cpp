#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> count;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        count = {};
        vector<int> curr;
        backtrack(candidates, target, 0, 0, curr);
        return count;
        
    }

private:
    void backtrack(vector<int>& candidates, int target, int ptr, int acc, vector<int>& curr) {
        if (acc == target) {
            count.push_back(curr);
            return;
        } else if (acc >= target || ptr >= candidates.size()) {
            return;
        }

        curr.push_back(candidates[ptr]);
        backtrack(candidates, target, ptr, acc + candidates[ptr], curr);
        curr.pop_back();
        backtrack(candidates, target, ptr + 1, acc, curr);

    }
};