class Solution {
public:
    class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int findParent(int node) {
            if (parent[node] == node)
                return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            if (pu == pv)
                return;
            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailToAccount;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailToAccount.find(mail) == mailToAccount.end())
                    mailToAccount[mail] = i;
                else
                    ds.unionBySize(i, mailToAccount[mail]);
            }
        }
        vector<vector<string>> mergedMails(n);
        for (auto [mail, node] : mailToAccount) {
            int parent = ds.findParent(node);
            mergedMails[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMails[i].size() == 0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergedMails[i].begin(), mergedMails[i].end());
            for (auto it : mergedMails[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};