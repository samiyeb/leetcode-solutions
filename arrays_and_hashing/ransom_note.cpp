#include <map>
#include <string>
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::map<char,int> mag;

        for (char c : magazine) {
            mag[c]++;
        }

        for (char c : ransomNote) {
            if (mag.find(c) == mag.end() || mag[c] == 0) {
                return false;
            }
            mag[c]--;
        }

        return true;
        
    }
};