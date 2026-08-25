class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        int t=k;
        while(true){
            if(mp.find(k)==mp.end()){
                return k;
            }
            k+=t;
        }
        return k;
    }
};