class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int c = matrix[0].size()-1;
        while(r<matrix.size() && c >=0){
            if(target == matrix[r][c]){
                return true;
            }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};