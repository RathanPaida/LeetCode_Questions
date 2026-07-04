class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n + 1);
        vector<int> min_edge(n + 1, INT_MAX);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int distance = road[2];
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                parent[rootV] = rootU;
                min_edge[rootU] = min({min_edge[rootU], min_edge[rootV], distance});
            } else {
                min_edge[rootU] = min(min_edge[rootU], distance);
            }
        }
        return min_edge[find(1)];
    }
};