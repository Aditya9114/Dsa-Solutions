/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ori = root;
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL)return newNode;
        while (root->left  || root->right) {
            if (root->val < val) {
                if(root->right == NULL){
                    root->right = newNode;
                    return ori;
                }
                root = root->right;
            } else {
                if(root->left == NULL){
                    root->left = newNode;
                    return ori;
                }
                root = root->left;
            }
        }
        if (root->val < val) {
            root->right = newNode;
            return ori;
        } else {
            root->left = newNode;
            return ori;
        }
    }
};