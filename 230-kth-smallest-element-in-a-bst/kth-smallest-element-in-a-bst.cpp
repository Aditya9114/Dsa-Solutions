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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(ans,root,k);
        return ans[k-1];
    }
    void inorder(vector<int> &ans, TreeNode *r, int k){
        if(r == NULL || ans.size() == k)return;
        inorder(ans,r->left,k);
        ans.push_back(r->val);
        if(ans.size() == k)return;
        inorder(ans,r->right,k);
    }
};