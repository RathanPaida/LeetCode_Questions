/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode*target,int k,unordered_map<TreeNode*,TreeNode*>&mp, vector<int>&ans,TreeNode*came){
        if(target==NULL)return;
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        if(target->left!=came){
            solve(target->left,k-1,mp,ans,target);
        }
        if(target->right!=came){
            solve(target->right,k-1,mp,ans,target);
        }
        if(mp[target]!=came){
            solve(mp[target],k-1,mp,ans,target);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left!=NULL){
                    mp[node->left]=node;
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    mp[node->right]=node;
                    q.push(node->right);
                }
            }
        }
        TreeNode*came=target;
        solve(target,k,mp,ans,came);
        return ans;
    }
};