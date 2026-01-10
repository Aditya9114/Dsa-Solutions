class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        // If left child is NULL, go right
        if (root->left == NULL)
            return 1 + minDepth(root->right);

        // If right child is NULL, go left
        if (root->right == NULL)
            return 1 + minDepth(root->left);

        // Both children exist
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
