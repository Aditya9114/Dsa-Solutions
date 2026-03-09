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
        vector<int> a,b;
        inorder(root,a);
        b = a;
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                return false;
            }
            if(i > 0 && b[i-1] == b[i])return false;
        }
        return true;
    }
    void inorder(TreeNode *r, vector<int> &a){
        if(r==NULL)return;
        inorder(r->left,a);
        a.push_back(r->val);
        inorder(r->right,a);
    }
};