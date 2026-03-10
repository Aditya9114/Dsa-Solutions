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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = traverse(root, p, q);
        return ans;
    }
    TreeNode *traverse(TreeNode *r, TreeNode *p, TreeNode *q){
        if(r == NULL)return NULL;
        if(r->val == p->val || r->val == q->val)return r;
        TreeNode *left = traverse(r->left,p,q);
        TreeNode *right = traverse(r->right,p,q);
        if(left != NULL && right != NULL)return r;
        else if(left)return left;
        else return right;
    }
};