class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }
    void helper(TreeNode* node) {
        if (!node) return;
        helper(node->left);
        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;
        helper(node->right);
    }
};