#include <string>
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int zero = 0;
        int one = 0;

        if (s[0] == '0') {zero = 1;}

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') {
                one++;
            }
        }

        int score = zero + one;

        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                one--;
            } else {
                zero++;
            }

            score = max(score, zero + one);
        }

        return score;
        
    }
};