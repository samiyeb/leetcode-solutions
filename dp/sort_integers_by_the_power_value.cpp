#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int getKth(int lo, int hi, int k) {

        int x = lo;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        unordered_map<int,int> cache;

        while (x <= hi) {
            int steps = 0;
            int temp = x;
            while (x != 1) {
                if (cache.find(x) != cache.end()) {
                    steps += cache[x];
                    break;
                }
                if (x % 2 == 0) {
                    x = x / 2;
                } else {
                    x = 3 * x + 1;
                }
                steps++;
            }

            x = temp;

            cache[x] = steps;

            pq.push(pair<int,int>(steps, x));
            x++;
        }


        while (k > 1) {
            pq.pop();
            k--;
        }

        return pq.top().second;
        
    }
};