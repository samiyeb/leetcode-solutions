class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;

        for (int i = 0; i < 32; i++) {
            int abit = ((a >> i) & 1);
            int bbit = ((b >> i) & 1);

            int entry = (abit ^ bbit);

            res ^= ((entry ^ carry) << i);

            if (entry == 0) {
                if (abit == 1) {
                    carry = 1;
                } else {
                    carry = 0;
                }
            }
        }

        return res;
        
    }
};