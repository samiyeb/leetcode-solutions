#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int current_greatest_candy_count = 0;

        for (int candy : candies) {
            current_greatest_candy_count = max(current_greatest_candy_count, candy);
        }

        vector<bool> num_of_potential_greatest_candy_count;

        for (int candy : candies) {
            num_of_potential_greatest_candy_count.push_back(candy + extraCandies >= current_greatest_candy_count);
        }

        return num_of_potential_greatest_candy_count;
        
    }
};