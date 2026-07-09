class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        int current_component = 0;        
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                current_component++;
            }
            comp[i] = current_component;
        }        
        vector<bool> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];            
            answer[i] = (comp[u] == comp[v]);
        }
        return answer;
    }
};