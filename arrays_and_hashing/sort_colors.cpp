#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> color_frequency;

        for (int color : nums) {
            color_frequency[color]++;
        }

        int i = 0;
        int pad = i;
        for (int color : vector<int>{0,1,2}) {
            for (; i < color_frequency[color] + pad; i++) {
                nums[i] = color;
            }
            pad = i;
        }
        
    }
};