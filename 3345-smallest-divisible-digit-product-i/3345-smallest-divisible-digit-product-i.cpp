class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; ++i) {
            int product = 1;
            int temp = i;
            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }
            if (product % t == 0) {
                return i;
            }
        }
    }
};