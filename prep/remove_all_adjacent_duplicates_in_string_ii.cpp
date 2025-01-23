#include <deque>
#include <utility>
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> deque;

        for (char c : s) {
            if (deque.size() > 0 && deque.front().first == c) {
                deque.front().second += 1;
            } else {
                deque.push_front(pair<char,int>(c,1));
            }
            if (deque.front().second == k) {
                deque.pop_front();
            }
        }

        string res = "";
        while (deque.size() > 0) {
            int frequency = deque.back().second;
            for (int i = 0; i < frequency; i++) {
                res += deque.back().first;
            }
            deque.pop_back();
        }

        return res;
        
    }
};