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
    bool isValidBST(TreeNode* root) {
       return validate(root, LONG_MIN, LONG_MAX);
    }
    bool validate(TreeNode *r, long min, long max){
        if(r==NULL)return true;
        if(r->val >= max || r->val <= min)return false;
        bool left = validate(r->left,min,(r->val));
        bool right = validate(r->right,(r->val),max);
        return left && right;
    }
};