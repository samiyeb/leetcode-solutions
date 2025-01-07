#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> map;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        vector<vector<string>> res;

        for (pair<string, vector<string>> group : map) {
            res.push_back(group.second);
        }

        return res;  
    }
};