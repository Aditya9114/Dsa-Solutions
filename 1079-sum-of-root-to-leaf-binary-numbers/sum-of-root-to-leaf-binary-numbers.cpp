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
    int sumRootToLeaf(TreeNode* root) {
        string s;
        vector<string> v1;
        traverse(root, s, v1);
        int sum = 0;
        for(int i=0;i<v1.size();i++){
            int num = binaryToDecimal(v1[i]);
            sum+=num;
        }
        return sum;
    }
    void traverse(TreeNode* r, string& s, vector<string>& v1) { 
        if(r == NULL || r==NULL)return;
        s += to_string(r->val);
        if (r->left == NULL && r->right == NULL) {
            v1.push_back(s);
            s.pop_back();
            return;
        }
        traverse(r->left, s, v1);
        traverse(r->right, s, v1);
        s.pop_back();
        return;
    }
    int binaryToDecimal(const string& s) {
        int num = 0;
        for (char c : s) {
            num = num * 2 + (c - '0');
        }
        return num;
    }
};