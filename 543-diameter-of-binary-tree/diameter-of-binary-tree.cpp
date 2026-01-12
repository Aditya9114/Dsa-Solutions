class Solution {
public:
    int maxi = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }

    int height(TreeNode* node) {
        if (!node) return 0;

        int LH = height(node->left);
        int RH = height(node->right);

        maxi = max(maxi, LH + RH);   // update diameter

        return 1 + max(LH, RH);
    }
};
