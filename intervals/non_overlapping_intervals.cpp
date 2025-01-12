#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int j = 0;
        int count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[j].back() > intervals[i].front()) {
                if (intervals[j].back() > intervals[i].back()) {
                    j = i;
                }
                count++;
            } else {
                j = i;
            }
        }

        return count;
        
    }
};