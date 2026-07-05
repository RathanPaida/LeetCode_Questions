class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> qu;
        vector<int> ans;
        int n = nums.size();
        for(int fi =0; fi<k; fi++){
            while(!qu.empty() && nums[qu.front()]<nums[fi]){
                qu.pop_front();
            }
            while(!qu.empty() && nums[qu.back()]<nums[fi]){
                qu.pop_back();
            }
            qu.push_back(fi);
        }
        ans.push_back(nums[qu.front()]);
        for(int i = k ;i<n;i++){
            if(i-k == qu.front()) qu.pop_front();
            while(!qu.empty() && nums[qu.front()]<nums[i]){
                qu.pop_front();
            }
            while(!qu.empty() && nums[qu.back()]<nums[i]){
                qu.pop_back();
            }
            qu.push_back(i);
            ans.push_back(nums[qu.front()]);
        }
        return ans;
    }
};