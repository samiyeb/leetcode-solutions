#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int res = 0;

        for (int i = 0; i < students.size(); i++) {
            res += abs(students[i] - seats[i]);
        }

        return res;
        
    }
};