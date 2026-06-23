class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> v(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]<k){
                v[i]=-1;
            }else v[i]=1;

            if(nums[i]==k)v[i]=n;
        }

        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(mp.find(sum-(n))!=mp.end()){
                ans+=mp[sum-(n)];
            }
             if(mp.find(sum-(n+1))!=mp.end()){
                ans+=mp[sum-(n+1)];
            }

            mp[sum]+=1;
           
        }
    
        return ans;
    }
};