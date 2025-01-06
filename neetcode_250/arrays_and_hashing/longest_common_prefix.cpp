#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest_str = "";

        for (string s : strs) {
            if (s.size() > longest_str.size()) {
                longest_str = s;
            }
        }

        string prefix = "";
        for (int i = 0 ; i < longest_str.size(); i++) {
            for (string s : strs) {
                if (i >= s.size() || s[i] != longest_str[i]) {
                    return prefix;
                }
            }

            prefix += longest_str[i];
        }

        return prefix;
        
    }
};