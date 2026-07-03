class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int x : nums) {
            total_sum += x;
        }
        if (abs(target) > total_sum) return 0;
        int offset = total_sum;
        vector<int> dp(2 * total_sum + 1, 0);
        dp[offset] = 1; 
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> next_dp(2 * total_sum + 1, 0);
            for (int current_sum = -total_sum; current_sum <= total_sum; ++current_sum) {
                int ways_to_reach_this_sum = dp[current_sum + offset];
                if (ways_to_reach_this_sum > 0) {
                    next_dp[current_sum + offset + nums[i]] += ways_to_reach_this_sum;
                    next_dp[current_sum + offset - nums[i]] += ways_to_reach_this_sum;
                }
            }
            dp = next_dp;
        }
        return dp[target + offset];
    }
};