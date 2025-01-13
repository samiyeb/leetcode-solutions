#include <unordered_set>
class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> nodes;

        while (n != 1) {
            if (nodes.find(n) != nodes.end()) {
                return false;
            }
            nodes.insert(n);
            
            int temp = 0;

            while (n > 9) {
                temp += ((n % 10) * (n % 10));
                n = n / 10;
            }
            temp += ((n % 10) * (n % 10));
            n = temp;

        }

        return true;
        
    }
};