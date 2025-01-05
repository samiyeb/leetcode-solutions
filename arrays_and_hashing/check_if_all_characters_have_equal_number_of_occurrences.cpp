#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> counter;

        for (char c : s) {
            counter[c]++;
        }

        bool no_base = true;
        int base = 0;
        for (pair<char, int> kv : counter) {
            if (no_base) {
                no_base = false;
                base = kv.second;
            }

            if (base != kv.second) {return false;}
        }

        return true;
        
    }
};