class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;
        int set_bits = 0;
        int i = 0;
        
        while (i < 32) {
            if ((num2 & (1 << i)) != 0) {
                set_bits++;
            }
            i++;
        }

        i--;
        while (i >= 0 && set_bits > 0) {
            if ((num1 & (1 << i)) != 0) {
                x += (1 << i);
                set_bits--;
            }
            i--;
        }

        i++;
        while (set_bits > 0) {
            if ((x & (1 << i)) == 0) {
                x += (1 << i);
                set_bits--;
            }
            i++;
        }

        return x;


        
    }
};