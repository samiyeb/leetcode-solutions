#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_count;

        if (s.size() != t.size()) {
            return false;
        }

        for (char c : s) {
            if (s_count.find(c) != s_count.end()) {
                s_count[c]++;
            } else {
                s_count[c] = 1;
            }
        }

        for (char c : t) {
            if ((s_count.find(c) != s_count.end() && s_count[c] == 0) || !(s_count.find(c) != s_count.end())) {
                return false;
            }
            s_count[c]--;
        }

        return true;

    }
};