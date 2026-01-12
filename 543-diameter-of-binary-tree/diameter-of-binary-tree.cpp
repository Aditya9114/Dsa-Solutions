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
    int maxi = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int lh = 0,rh=0;
        lh = height(root->left)-1;
        rh = height(root->right)-1;
        maxi = max(maxi,2+lh+rh);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
    int height(TreeNode *node){
        if(node == NULL) return 0;
        int LH =  height(node->left);
        int RH =  height(node->right);
        return 1 + max(LH,RH);
    }
};