class Solution {
private:
    bool poss(const vector<int>& weights, int days, int capacity) {
        int days_needed = 1; 
        int current_weight = 0;
        for (int weight : weights) {
            if (current_weight + weight > capacity) {
                days_needed++;
                current_weight = weight;
            } else {
                current_weight += weight;
            }
        }
        return days_needed <= days;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int mid;
        int ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(poss(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};