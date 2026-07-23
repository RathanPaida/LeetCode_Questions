class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32, 0);
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        int ans = 0;
        int prev_bit = 0;
        for (int i = 30; i >= 0; --i) {
            if ((n & (1 << i)) != 0) {
                ans += f[i];
                if (prev_bit == 1) {
                    return ans;
                }
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }
        return ans + 1;
    }
};