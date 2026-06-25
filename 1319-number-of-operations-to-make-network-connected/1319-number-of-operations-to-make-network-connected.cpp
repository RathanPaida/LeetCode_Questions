class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        DSU ds(n);
        int extra = 0;
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            if (ds.findUPar(u) == ds.findUPar(v))
                extra++;
            else
                ds.unionBySize(u, v);
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i)
                components++;
        }
        return (extra >= components - 1) ? components - 1 : -1;
    }
};