#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {count++;}
            }
        }

        return count;
        
    }

private: 
    bool isPrefixAndSuffix(string s1, string s2) {
        int prefix_size = s1.size();
        int n = s2.size();
        if (n < prefix_size) {return false;}
        return s2.substr(0, prefix_size) == s1 && s2.substr(n-prefix_size, prefix_size) == s1;
    }
};