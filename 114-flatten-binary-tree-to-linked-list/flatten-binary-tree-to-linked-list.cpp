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
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode *node = new TreeNode();
        TreeNode *last = node;

        traverse(root, last);

        root->val = node->right->val;
        root->left = NULL;
        root->right = node->right->right;
    }

    void traverse(TreeNode *r, TreeNode *&l){
        if(r == NULL) return;

        TreeNode *temp = new TreeNode(r->val);
        l->right = temp;
        l = temp;

        traverse(r->left, l);
        traverse(r->right, l);
    }
};