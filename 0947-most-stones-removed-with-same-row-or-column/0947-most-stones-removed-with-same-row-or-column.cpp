class Disjoint{
    public:
        vector<int> parent , size;
        Disjoint(int n){
            parent.resize(n , 0);
            size.resize(n , 1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void dsunion(int u , int v){
            if(findUPar(u) == findUPar(v)) return;
            int ulpu = findUPar(u);
            int ulpv = findUPar(v);
            if(size[ulpu] < size[ulpv]){
                size[ulpv] += size[ulpu];
                parent[ulpu] = ulpv;
            } else{
                size[ulpu] += size[ulpv];
                parent[ulpv] = ulpu;
            }
            return;
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        Disjoint st(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[j][1] == stones[i][1]) st.dsunion(i , j);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(st.parent[i] == i) ans += st.size[i]-1; 
        }
        return ans;
    }
};