#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int ptr = n-1;
        while (ptr > 0) {
            for (int i = 0; i < n; i++) {
                if (nums[i] + i >= ptr) {
                    ptr = i;
                    res++;
                    break;
                }
            }
            
        }

        return res;
        
    }
};