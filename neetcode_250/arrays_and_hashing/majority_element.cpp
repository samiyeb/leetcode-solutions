#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current_winner = nums[0];
        int count = 0;

        for (int n : nums) {
            if (n == current_winner) {
                count++;
            } else if (count > 0) {
                count--;
            } else {
                current_winner = n;
                count = 1;
            }
        }

        return current_winner;
        
    }
};