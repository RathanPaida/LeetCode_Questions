class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& stones) {
        visited[node] = 1;
        for (int j = 0; j < stones.size(); j++) {
            if (!(visited[j]) &&
                (stones[j][0] == stones[node][0] || stones[j][1] == stones[node][1])) {
                dfs(j, visited, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, stones);
            }
        }
        return n - count;
    }
};