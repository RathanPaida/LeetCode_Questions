class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sz=0;
            int cnt=0;
            for(int j=i;j<n;j++){
                sz++;
                if(nums[j]==target){
                    cnt++;
                }
                if(cnt>sz/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};