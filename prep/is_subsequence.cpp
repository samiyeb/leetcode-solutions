#include <string>
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (t.size() < s.size()) {return false;}
        if (s.size() == 0) {return true;}


        int i = 0;
        for (char c : t) {
            if (c == s[i]) {
                i++;
            }
            if (i == s.size()) {
                return true;
            }
        }

        return false;
        
    }
};