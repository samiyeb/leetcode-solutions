#include <queue>
#include <climits>
#include <vector>
using namespace std;
// The most optimal solution uses Dynamic Programming but I didn't solve it that way unfortunately lol
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // Brute Force Solution O(n^2) O(1)
        // int result = INT_MIN;
        // for (int i = 0; i < values.size(); i++) {
        //     for (int j = i + 1; j < values.size(); j++){
        //         result = max(result, values[i] + values[j] + i - j);
        //     }
        // }
        // return result;


        // Max Heap Solution O(nlogn) O(n)
        int result = INT_MIN;

        priority_queue<pair<int, int>> max_heap;
        
        for (int j = 0; j < values.size(); j++) {
            int new_val = values[j] - j;
            max_heap.push({new_val, j});
        }

        for (int i = 0; i < values.size(); i++) {
            while (max_heap.size() > 0) {
                int j = max_heap.top().second;
                if (i < j) {
                    result = max(result, values[i] + values[j] + i - j);
                    break;
                } else {
                    max_heap.pop();
                }
            }
        }

        return result;
        
    }
};