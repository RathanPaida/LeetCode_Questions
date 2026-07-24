class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int len = s.length();
        int dp[11][2][11] = {0};
        dp[0][1][0] = 1;
        for (int i = 0; i < len; ++i) {
            for (int tight = 0; tight < 2; ++tight) {
                for (int count = 0; count <= i; ++count) { 
                    if (dp[i][tight][count] == 0) continue;
                    int limit = tight ? (s[i] - '0') : 9;
                    for (int d = 0; d <= limit; ++d) {
                        int next_tight = tight && (d == limit);
                        int next_count = count + (d == 1 ? 1 : 0);
                        dp[i + 1][next_tight][next_count] += dp[i][tight][count];
                    }
                }
            }
        }
        int total_digit_ones = 0;
        for (int tight = 0; tight < 2; ++tight) {
            for (int count = 0; count <= len; ++count) {
                total_digit_ones += dp[len][tight][count] * count;
            }
        }
        
        return total_digit_ones;
    }
};