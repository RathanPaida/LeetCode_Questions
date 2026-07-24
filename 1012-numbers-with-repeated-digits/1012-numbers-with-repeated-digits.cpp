class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int l = s.size();
        int dp[11][2][2][1024] = {0};
        dp[0][1][1][0] = 1;   
        for (int i = 0; i < l; i++) {
            for (int tight = 0; tight < 2; tight++) {
                for (int lz = 0; lz < 2; lz++) {
                    for (int mask = 0; mask < 1024; mask++) {
                        if (dp[i][tight][lz][mask] == 0) continue;                        
                        int limit = tight ? (s[i] - '0') : 9;
                        for (int d = 0; d <= limit; d++) {
                            if (lz == 0 || d > 0) {
                                if (mask & (1 << d)) {
                                    continue; 
                                }
                            }
                            int next_tight = tight && (d == limit);
                            int next_lz = lz && (d == 0);
                            int next_mask = next_lz ? 0 : (mask | (1 << d));
                            dp[i + 1][next_tight][next_lz][next_mask] += dp[i][tight][lz][mask];
                        }
                    }
                }
            }
        }
        int unique_digit_numbers = 0;
        for (int tight = 0; tight < 2; tight++) {
            for (int mask = 1; mask < 1024; mask++) { 
                unique_digit_numbers += dp[l][tight][0][mask];
            }
        }
        return n - unique_digit_numbers;
    }
};