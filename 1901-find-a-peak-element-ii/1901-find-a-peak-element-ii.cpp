class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int max_row = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > mat[max_row][mid]) {
                    max_row = i;
                }
            }
            int curr_val = mat[max_row][mid];
            int left_val = (mid - 1 >= 0) ? mat[max_row][mid - 1] : -1;
            int right_val = (mid + 1 < n) ? mat[max_row][mid + 1] : -1;
            if (curr_val > left_val && curr_val > right_val) {
                return {max_row, mid};
            } 
            else if (left_val > curr_val) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return {-1, -1}; 
    }
};