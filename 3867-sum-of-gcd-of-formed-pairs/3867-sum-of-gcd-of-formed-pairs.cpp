class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=nums[0];
        vector<int> pgcd(nums.size(),0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pgcd[i]=__gcd(nums[i],maxi);
        }
        sort(pgcd.begin(),pgcd.end());
        long long ans=0;
        for(int i=0;i<n/2;i++){
            ans+=__gcd(pgcd[i],pgcd[n-i-1]);
        }
        return ans;
    }
};