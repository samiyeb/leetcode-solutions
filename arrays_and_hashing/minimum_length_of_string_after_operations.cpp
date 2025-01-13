#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int current_length = s.size();
        unordered_map<char, int> map;

        for (char c : s) {
            map[c]++;
            if (map[c] == 3) {
                map[c] -= 2;
                current_length -= 2;
            }
        }

        return current_length;
        
    }
};