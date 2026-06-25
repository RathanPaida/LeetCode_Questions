class Solution {
public:
    void dfs(int i,vector<bool> &vis,vector<vector<int>> &edges){
        for(int j:edges[i]){
            if(!vis[j]){
                vis[j]=true;
                dfs(j,vis,edges);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<bool> vis(n,false);
        int ans=0;
        vector<vector<int>> edges(n);
        for(auto i:connections){
            edges[i[0]].push_back(i[1]);
            edges[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                dfs(i,vis,edges);
                ans++;
            }
        }
        return ans-1;
    }
};