#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int one = m - 1;
        int two = n - 1;
        int main = (m+n) - 1;

        while (one >= 0 && two >= 0) {
            if (nums1[one] > nums2[two]) {
                nums1[main] = nums1[one];
                one--;
            } else {
                nums1[main] = nums2[two];
                two--;
            }
            main--;
        }

        while (one >= 0) {
            nums1[main] = nums1[one];
            one--;
            main--;
        }

        while (two >= 0) {
            nums1[main] = nums2[two];
            two--;
            main--;
        }
        
    }
};