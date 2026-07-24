class Solution {
    long long countPowerful(long long n, int limit, string& s) {
        string num_str = to_string(n);
        int L = num_str.length();
        int lenS = s.length();
        if (L < lenS) return 0;
        long long dp[20][2] = {0};
        dp[0][1] = 1;
        
        for (int i = 0; i < L; ++i) {
            for (int tight = 0; tight < 2; ++tight) {
                if (dp[i][tight] == 0) continue;
                int limit_d = tight ? (num_str[i] - '0') : 9;
                int max_allowed = min(limit_d, limit);
                if (i >= L - lenS) {
                    int forced_d = s[i - (L - lenS)] - '0';
                    if (forced_d <= max_allowed) {
                        int next_tight = tight && (forced_d == limit_d);
                        dp[i + 1][next_tight] += dp[i][tight];
                    }
                } 
                else {
                    for (int d = 0; d <= max_allowed; ++d) {
                        int next_tight = tight && (d == limit_d);
                        dp[i + 1][next_tight] += dp[i][tight];
                    }
                }
            }
        }
        return dp[L][0] + dp[L][1];
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countPowerful(finish, limit, s) - countPowerful(start - 1, limit, s);
    }
};