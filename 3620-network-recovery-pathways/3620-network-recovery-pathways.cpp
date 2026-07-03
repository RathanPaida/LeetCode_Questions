class Solution {
    bool isPossible(int min_edge, int n,vector<vector<pair<int, int>>>& e, 
                     vector<bool>& online, long long k) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            if (u == n - 1) return dist[u] <= k;
            for (auto& edge : e[u]) {
                int v = edge.first;
                int w = edge.second;
                if (w >= min_edge && online[v]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist[n - 1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> e(n);
        int max_weight = 0;
        for (auto& i : edges) {
            e[i[0]].push_back({i[1], i[2]});
            max_weight = max(max_weight, i[2]);
        }
        int low = 0, high = max_weight;
        int best_score = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, n, e, online, k)) {
                best_score = mid;  
                low = mid + 1;      
            } else {
                high = mid - 1;   
            }
        }     
        return best_score;
    }
};