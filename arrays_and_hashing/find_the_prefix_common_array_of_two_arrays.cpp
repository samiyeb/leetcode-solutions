#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> a_set;
        set<int> b_set;

        int n = A.size();
        vector<int> C;
        int curr = 0;

        for (int i = 0; i < n; i++) {
            if (b_set.find(A[i]) != b_set.end()) {
                curr++;
            }

            if (a_set.find(B[i]) != a_set.end()) {
                curr++;
            }

            if (A[i] == B[i]) {
                curr++;
            }

            C.push_back(curr);

            a_set.insert(A[i]);
            b_set.insert(B[i]);
        }

        return C;
        
    }
};