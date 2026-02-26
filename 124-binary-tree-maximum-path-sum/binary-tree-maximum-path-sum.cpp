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
    
    int maxPathSum(TreeNode* root) {
        int ms;
        ms = INT_MIN;
        findMaxSum(root,ms);
        if(root->val > ms)return root->val;
        return ms;
    }
    int findMaxSum(TreeNode* r, int &ms){
        if(r == NULL)return 0;
        int leftval = max(0,findMaxSum(r->left,ms));
        int rightval = max(0,findMaxSum(r->right,ms));
        ms = max(ms,((r->val) + leftval + rightval));
        return ((r->val) + max(leftval,rightval));
    }
};