#include <stack>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        map<char, char> map{{')', '('}, {'}', '{'}, {']', '['}};

        for (char c: s) {
            if (map.find(c) != map.end()) {
                if (stack.size() > 0 && stack.top() == map[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }

        return stack.size() == 0;
        
    }
};