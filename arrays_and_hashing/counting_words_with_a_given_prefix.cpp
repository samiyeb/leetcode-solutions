#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int prefix_size = pref.size();
        int res = 0;

        for (string word : words) {
            if (word.substr(0, prefix_size) == pref) {
                res++;
            }
        }

        return res;    
    }
};