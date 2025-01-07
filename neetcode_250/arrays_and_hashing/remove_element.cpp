#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {return 0;}
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                int j = nums.size() - 1;
                while (j > i && nums[j] == val) {
                    j--;
                }
                if (j != i && nums[j] != val) {
                    nums[i] = nums[j];
                    nums[j] = val;
                }
            }
        }

        int i = 0;
        while (i < nums.size() && nums[i] != val) {
            i++;
        }

        return i;
        
    }
};