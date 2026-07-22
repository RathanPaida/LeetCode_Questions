class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[0][0] = true;     
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = stones[j] - stones[i];
                if (dist > i + 1) {
                    break;
                }
                if (dp[i][dist - 1] || dp[i][dist] || dp[i][dist + 1]) {
                    dp[j][dist] = true;
                    if (j == n - 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};