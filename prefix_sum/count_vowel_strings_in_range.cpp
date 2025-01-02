#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix;
        int current_count = 0;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (string word : words) {
            bool start = false;
            bool end = false;
            for (char vowel : vowels) {
                if (word.front() == vowel) {start = true;}
                if (word.back() == vowel) {end = true;}
            }
            if (start && end) {current_count++;} 

            prefix.push_back(current_count);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int left = 0;
            if (l > 0) {left = prefix[l-1];}
            ans.push_back(prefix[r] - left);
        }

        return ans;
        
    }
};