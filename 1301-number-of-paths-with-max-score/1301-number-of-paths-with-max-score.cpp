class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1e9 + 7;
        int n = board.size();
        vector<vector<int>> maxScore(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        maxScore[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(board[i][j]=='X'){
                    continue;
                }
                if(i==n-1&&j==n-1){
                    continue;
                }
                int bs=-1;
                int tw=0;
                if(i+1<n&&maxScore[i+1][j]!=-1){
                    if(maxScore[i+1][j]>bs){
                        bs=maxScore[i+1][j];
                        tw=ways[i+1][j];
                    }
                    else if(maxScore[i+1][j]==bs){
                        tw=(tw+ways[i+1][j])%mod;
                    }
                }
                if(j+1<n&&maxScore[i][j+1]!=-1){
                    if(maxScore[i][j+1]>bs){
                        bs=maxScore[i][j+1];
                        tw=ways[i][j+1];
                    }
                    else if(maxScore[i][j+1]==bs){
                        tw=(tw+ways[i][j+1])%mod;
                    }
                }
                if(i+1<n&&j+1<n&&maxScore[i+1][j+1]!=-1){
                    if(maxScore[i+1][j+1]>bs){
                        bs=maxScore[i+1][j+1];
                        tw=(ways[i+1][j+1])%mod;
                    }
                    else if(maxScore[i+1][j+1]==bs){
                        tw=(tw+ways[i+1][j+1])%mod;
                    }
                }
                if(bs==-1){
                    continue;
                }
                if(board[i][j]>='1'&&board[i][j]<='9'){
                    maxScore[i][j]=bs+(board[i][j]-'0');
                }
                else{
                    maxScore[i][j]=bs;
                }
                ways[i][j]=tw;
            }
        }
        if (maxScore[0][0] == -1) {
            return {0, 0};
        }
        return {maxScore[0][0], ways[0][0]};
    }
};