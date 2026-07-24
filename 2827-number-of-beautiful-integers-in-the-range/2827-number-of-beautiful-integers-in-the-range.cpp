class Solution {
    int countBeautiful(int n, int k) {
        if (n == 0) return 0;
        string s = to_string(n);
        int len = s.length();
        int dp[11][2][2][21][20] = {0};
        dp[0][1][1][10][0] = 1;
        for (int i = 0; i < len; ++i) {
            for (int tight = 0; tight < 2; ++tight) {
                for (int lz = 0; lz < 2; ++lz) {
                    for (int diff = 0; diff <= 20; ++diff) {
                        for (int rem = 0; rem < k; ++rem) {
                            int count = dp[i][tight][lz][diff][rem];
                            if (count == 0) continue; 
                            int limit = tight ? (s[i] - '0') : 9;
                            for (int d = 0; d <= limit; ++d) {
                                int next_tight = tight && (d == limit);
                                int next_lz = lz && (d == 0);
                                int next_diff = diff;
                                if (!next_lz) { 
                                    if (d % 2 == 0) next_diff++;
                                    else next_diff--;
                                }
                                int next_rem = next_lz ? 0 : ((rem * 10) + d) % k;
                                dp[i + 1][next_tight][next_lz][next_diff][next_rem] += count;
                            }
                        }
                    }
                }
            }
        }
        int valid_numbers = 0;
        for (int tight = 0; tight < 2; ++tight) {
            valid_numbers += dp[len][tight][0][10][0];
        }
        
        return valid_numbers;
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return countBeautiful(high, k) - countBeautiful(low - 1, k);
    }
};