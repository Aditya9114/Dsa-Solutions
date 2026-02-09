class Solution {
public:
    unordered_map<int,int> mpp;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size()-1,
                     postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& in, int inStart, int inEnd,
                    vector<int>& post, int postStart, int postEnd) {

        if(inStart > inEnd || postStart > postEnd)
            return NULL;

        TreeNode* root = new TreeNode(post[postEnd]);

        int rootIndex = mpp[root->val];
        int leftSize = rootIndex - inStart;

        root->left = build(in, inStart, rootIndex - 1,
                           post, postStart, postStart + leftSize - 1);

        root->right = build(in, rootIndex + 1, inEnd,
                            post, postStart + leftSize, postEnd - 1);

        return root;
    }
};
