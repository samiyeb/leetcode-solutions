#include <vector>
using namespace std;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long> postfix(nums.size(), nums.back());

        for (int i = nums.size() - 2; i >= 0; i--) {
            postfix[i] = (nums[i] + postfix[i+1]);
        }

        long prefix = nums.front();
        int splits = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (prefix >= postfix[i]) {
                splits++;
            }

            prefix += nums[i];
        }

        return splits;
        
    }
};