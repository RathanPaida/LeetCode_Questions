class Solution {
public:
    void solve( int u,int &mini,vector<bool> &vis,vector<vector<pair<int,int>>> &ed){
        if(vis[u-1]){
            return;
        }
        vis[u-1]=true;
        for(auto i:ed[u]){
            mini=min(mini,i.second);
            solve(i.first,mini,vis,ed);
        }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        int mini=INT_MAX;
        vector<vector<pair<int,int>>> ed(n+1);
        for(auto i:roads){
            ed[i[0]].push_back({i[1],i[2]});
            ed[i[1]].push_back({i[0],i[2]});
        }
        vector<bool> vis(n,false);
        solve(1,mini,vis,ed);
        return mini;
    }
};