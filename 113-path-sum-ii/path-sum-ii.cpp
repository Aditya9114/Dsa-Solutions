/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root!=NULL && root->left == NULL && root->right == NULL && (root->val == targetSum)){
            ans.push_back({root->val});
        }
        vector<int> st;
        int sum = 0;
        traverse(root,targetSum,st, sum, ans);
        return ans;
    }
    void traverse(TreeNode *node, int ts, vector<int> &stack, int s, vector<vector<int>> &a){
        if(node == NULL)return;
        s = s + node->val;
        stack.push_back(node->val);
        if(s == ts && (stack.size() > 1) && (node->left == NULL && node->right == NULL)){
            a.push_back(stack);
        }
        if(node->left){
            traverse(node->left,ts,stack,s,a);
        }
        if(node->right){
            traverse(node->right,ts,stack,s,a);
        }
        stack.pop_back();
    }
};