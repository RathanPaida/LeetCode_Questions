class Solution {
private:
    vector<int> order;
    vector<bool> vis;
    void dfs1(int u,vector<vector<int>>& adj) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs1(v, adj);
            }
        }
        order.push_back(u);
    }
    void dfs2(int u, int current_scc, vector<int>& scc_id, 
              vector<vector<int>>& sccs, vector<vector<int>>& rev_adj) {
        vis[u] = true;
        scc_id[u] = current_scc;
        sccs.back().push_back(u);
        for (int v : rev_adj[u]) {
            if (!vis[v]) {
                dfs2(v, current_scc, scc_id, sccs, rev_adj);
            }
        }
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }
        vector<vector<int>> adj(26), rev_adj(26);
        for (int i = 0; i < 26; i++) {
            if (first[i] > last[i]) continue;
            for (int j = first[i]; j <= last[i]; j++) {
                int v = s[j] - 'a';
                if (i != v) {
                    adj[i].push_back(v);
                    rev_adj[v].push_back(i);
                }
            }
        }
        order.clear();
        vis.assign(26, false);
        for (int i = 0; i < 26; i++) {
            if (first[i] <= last[i] && !vis[i]) {
                dfs1(i, adj);
            }
        }
        vis.assign(26, false);
        vector<vector<int>> sccs;
        vector<int> scc_id(26, -1);
        int current_scc = 0;
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            if (!vis[u]) {
                sccs.push_back({});
                dfs2(u, current_scc, scc_id, sccs, rev_adj);
                current_scc++;
            }
        }
        vector<string> ans;
        for (int i = 0; i < current_scc; i++) {
            bool has_out_edge = false;
            int min_l = n, max_r = -1;
            for (int u : sccs[i]) {
                min_l = min(min_l, first[u]);
                max_r = max(max_r, last[u]);
                for (int v : adj[u]) {
                    if (scc_id[u] != scc_id[v]) {
                        has_out_edge = true;
                    }
                }
            }
            if (!has_out_edge) {
                ans.push_back(s.substr(min_l, max_r - min_l + 1));
            }
        }
        
        return ans;
    }
};