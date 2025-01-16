#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        set<int> window;

        for (int r = 0; r < nums.size(); r++) {
            if ((r-l) > k) {
                window.erase(nums[l]);
                l++;
            }

            if (window.find(nums[r]) != window.end()) {
                return true;
            }

            window.insert(nums[r]);
        }

        return false;
        
    }
};