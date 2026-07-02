class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        if(grid[0][0]==1){
            pq.push({health-1,{0,0}});
        }
        else{
            pq.push({health,{0,0}});
        }
        vis[0][0]=true;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int h=t.first;
            int x=t.second.first;
            int y=t.second.second;
            if(x==m-1&&y==n-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&!vis[nx][ny]){
                    int nh=h+(grid[nx][ny]==1?-1:0);
                    if(nh>=1){
                        pq.push({nh,{nx,ny}});
                        vis[nx][ny]=true;
                    }
                }
            }
        }
        return false;
    }
};