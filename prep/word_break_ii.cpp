#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dfs(s, wordDict, "", "", 0);
        return res;
    }

    bool in(vector<string> w, string cw) {
        for (string x : w) {
            if (cw == x) {
                return true;
            }
        }

        return false;
    }

    void dfs(string s, vector<string>& wordDict, string curr_word, string total, int i) {
        bool validWord = in(wordDict, curr_word);
        string temp_total = total;
        string temp_curr_word = curr_word;

        if (validWord) {
            total = (total == "") ? curr_word : total + " " + curr_word;
            curr_word = "";

            if (i == s.size()) {
                res.push_back(total);
                return;
            }
        }

        if (i == s.size()) {
            return;
        }

        curr_word += s[i];
        dfs(s, wordDict, curr_word, total, i+1);
        if (validWord) {
            temp_curr_word += s[i];
            dfs(s, wordDict, temp_curr_word, temp_total, i+1);
        }
    }
};