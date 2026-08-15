class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int nx=0;
        int nc=0;
        for(int i:nums){
            nx^=i;
            if(i>0){
                nc++;
            }
        }
        if(nx==0){
            if(nc>0){
                return nums.size()-1;
            }
            else{
                return 0;
            }
        }
        else{
            return nums.size();
        }
    }
};