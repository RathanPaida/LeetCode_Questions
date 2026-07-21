class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, map<int, multiset<int>>> mp; 
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            TreeNode* node = t.first;
            int row = t.second.first;
            int col = t.second.second;
            mp[col][row].insert(node->val);
            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }
        for (auto& col_map : mp) {
            vector<int> colVals;
            for (auto& row_map : col_map.second) {
                for (int val : row_map.second) {
                    colVals.push_back(val);
                }
            }
            ans.push_back(colVals);
        }
        
        return ans;
    }
};