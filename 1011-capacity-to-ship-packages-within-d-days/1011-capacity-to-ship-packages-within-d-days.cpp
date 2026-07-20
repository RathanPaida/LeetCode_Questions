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
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int mid;
        int ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(poss(weights,days,mid)){
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