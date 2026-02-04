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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return false;
        int sum = 0;
        return traverse(root,sum,targetSum);
    }
    bool traverse(TreeNode *r, int s, int ts){
        if(r==NULL)return false;
        s = s + r->val;
        if(r->left == NULL && r->right == NULL ){
            if(s!=ts) return false;
            return true;
        }
        return (traverse(r->left,s,ts) || (traverse(r->right,s,ts)));
    }
};