#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int max_left = 0;
        int max_right = 0;
        int l = 0;
        int r = height.size() - 1;

        long water = 0;

        while (l < r) {
            max_left = max(max_left, height[l]);
            max_right = max(max_right, height[r]);

            water += min(max_left, max_right) - min(height[l], height[r]);

            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return water;
        
    }
};