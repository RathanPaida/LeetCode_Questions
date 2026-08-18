class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        if (k == 1) {
            int max_val = -1;
            for (auto &[num, freq] : count) {
                if (freq == 1) {
                    max_val = max(max_val, num);
                }
            }
            return max_val;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        int ans = -1;
        if (count[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (count[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};