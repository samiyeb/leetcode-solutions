#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals.front()};
        int last_end;
        for (int i = 1; i < intervals.size(); i++) {
            last_end = res.back().back();
            if (intervals[i].front() <= last_end) {
                res[res.size() - 1][1] = max(last_end, intervals[i].back());
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
        
    }
};