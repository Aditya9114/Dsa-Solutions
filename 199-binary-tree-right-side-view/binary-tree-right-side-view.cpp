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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;
        map<int,int> mpp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode *curr = q.front().first;
            int num = curr->val;
            int y = q.front().second;
            mpp[y] = num;
            q.pop();
            if(curr->left){
                q.push({curr->left,y+1});
            }
            if(curr->right){
                q.push({curr->right,y+1});
            }
        }
        for(auto x : mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};