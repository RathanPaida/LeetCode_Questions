class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] > target && i>0) {
                int s = 0, e = n - 1;
                while (s <= e) {
                    int mid = s + (e - s) / 2;
                    if (matrix[i - 1][mid] == target) {
                        return true;
                    } else if (matrix[i - 1][mid] > target) {
                        e = mid - 1;
                    } else {
                        s = mid + 1;
                    }
                }
                return false;
            }
        }
        
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (matrix[m - 1][mid] == target) {
                return true;
            } else if (matrix[m - 1][mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return false;
    }
};
