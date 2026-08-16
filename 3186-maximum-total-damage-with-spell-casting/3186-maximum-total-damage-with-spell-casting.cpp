class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<int> uniq;
        vector<long long> sums;
        for (int p : power) {
            if (uniq.empty() || uniq.back() != p) {
                uniq.push_back(p);
                sums.push_back(p);
            } else {
                sums.back() += p;
            }
        }
        int k = uniq.size();
        vector<long long> dp(k + 1, 0);
        for (int i = 1; i <= k; ++i) {
            long long current_val = uniq[i - 1];
            long long current_sum = sums[i - 1];
            auto it = lower_bound(uniq.begin(), uniq.begin() + i - 1, current_val - 2);
            int valid_count = distance(uniq.begin(), it);
            dp[i] = max(dp[i - 1], current_sum + dp[valid_count]);
        }
        return dp[k];
    }
};