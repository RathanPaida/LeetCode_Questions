class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> walls;
        for (auto& b : buildings) {
            walls.push_back({b[0], -b[2]});
            walls.push_back({b[1], b[2]});
        }
        
        sort(walls.begin(), walls.end());
        
        vector<vector<int>> ans;
        multiset<int> heights = {0};
        int prev_max = 0;
        
        for (auto& w : walls) {
            int x = w.first;
            int h = w.second;
            
            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }
            
            int curr_max = *heights.rbegin();
            
            if (curr_max != prev_max) {
                ans.push_back({x, curr_max});
                prev_max = curr_max;
            }
        }
        
        return ans;
    }
};