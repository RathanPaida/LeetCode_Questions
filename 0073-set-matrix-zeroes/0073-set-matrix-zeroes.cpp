class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool colzero=false,rowzero=false;
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                rowzero=true;
            }
        }
        for(int j=0;j<matrix.size();j++){
            if(matrix[j][0]==0){
                colzero=true;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(rowzero){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        if(colzero){
            for(int j=0;j<matrix.size();j++){
                matrix[j][0]=0;
            }
        }
    }

};