#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int res = INT_MIN;

        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
            }

            res = max(res, count);
        }

        return res;
        
    }
};