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
    int ms;
    int maxPathSum(TreeNode* root) {
        ms = root->val;
        findMaxSum(root);
        return ms;
    }
    int findMaxSum(TreeNode* r){
        if(r == NULL)return 0;
        int leftSum = max(0, findMaxSum(r->left));
        int rightSum = max(0, findMaxSum(r->right));
        int rootVal = r->val;
        ms = max(ms, leftSum+rightSum+rootVal);
        return r->val + max(leftSum,rightSum);
    }
};