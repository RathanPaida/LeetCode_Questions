class Solution {
private:
    bool is_valid(vector<int>& piles,int mid,int h){
        int ans=0;
        for(auto &i:piles){
            ans+=(i+mid-1)/mid;
            if(ans>h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=*max_element(piles.begin(),piles.end());
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(is_valid(piles,mid,h)){
                e=mid-1;
                ans=mid;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};