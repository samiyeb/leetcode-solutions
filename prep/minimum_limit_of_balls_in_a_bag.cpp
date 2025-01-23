#include <vector>
#include <climits>
#include <math.h>
using namespace std;
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = preprocessing_max_of_nums(nums);

        while (l < r) {
            int m = (l+r) / 2;

            if (is_limit(nums, maxOperations, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
        
    }

    int preprocessing_max_of_nums(vector<int>& nums) {
        int max = INT_MIN;

        for (int num: nums) {
            max = (num > max) ? num : max;
        }

        return max;
    }

    bool is_limit(vector<int>& nums, int maxOperations, int i) {
        for (int num : nums) {
            if (maxOperations < 0) {return false;}
            maxOperations -= ceil(static_cast<double>(num) / i) - 1;
        }

        return maxOperations >= 0;
    }
};