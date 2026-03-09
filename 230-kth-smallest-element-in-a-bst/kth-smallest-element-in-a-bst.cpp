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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        inorder(pq,root,k);
        return pq.top();
    }
    void inorder(priority_queue<int> &p, TreeNode *r, int k){
        if(r == NULL)return;
        inorder(p,r->left,k);
        p.push(r->val);
        if(p.size() > k)p.pop();
        inorder(p,r->right,k);
    }
};