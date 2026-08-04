class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int j = 1; j < nums.size(); j++) {
            int expectedNext = nums[j - 1] + 1;
            while (expectedNext < nums[j]) {
                ans.push_back(expectedNext);
                expectedNext++;
            }
        }
        return ans;
    }
};