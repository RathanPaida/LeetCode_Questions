class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto i:intervals){
            if(ans.empty()){
                ans.push_back(i);
            }
            else if(i[0]<=ans.back()[0]&&i[1]>=ans.back()[1]){
                ans.back()[0]=i[0];
                ans.back()[1]=i[1];
            }
            else if(i[0]>=ans.back()[0]&&i[1]<=ans.back()[1]){
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans.size();
    }
};