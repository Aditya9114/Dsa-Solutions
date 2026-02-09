class Solution {
public:
    unordered_map<int, int> mpp;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
    }

    TreeNode* build(vector<int>& pre, vector<int>& in, int preStart, int preEnd,
                    int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(pre[preStart]);

        int rootIndex = mpp[pre[preStart]];
        int leftSize = rootIndex - inStart; // 🔧 FIX 1

        // 🔧 FIX 2: correct preorder & inorder ranges
        root->left = build(pre, in, preStart + 1, preStart + leftSize, inStart,
                           rootIndex - 1);

        root->right = build(pre, in, preStart + leftSize + 1, preEnd,
                            rootIndex + 1, inEnd);

        return root;
    }
};
