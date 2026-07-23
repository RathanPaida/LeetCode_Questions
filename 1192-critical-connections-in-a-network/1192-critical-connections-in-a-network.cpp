class Solution {
private:
    int timer = 1;
    
    void dfs(int u, int parent, vector<vector<int>>& adj, 
             vector<int>& disc, vector<int>& low, vector<vector<int>>& bridges) {
        disc[u] = low[u] = timer++;        
        for (int v : adj[u]) {
            if (v == parent) {
                continue; 
            }
            if (disc[v] == 0) {
                dfs(v, u, adj, disc, low, bridges);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (const auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> disc(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, disc, low, bridges);
        return bridges;
    }
};