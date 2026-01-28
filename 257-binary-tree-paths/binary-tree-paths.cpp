class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> q;
        traverse(root, ans, q);
        return ans;
    }

    void traverse(TreeNode *node, vector<string> &ans, vector<int> &q) {
        if (node == NULL) {
            return;
        }

        q.push_back(node->val);

        if (node->left == NULL && node->right == NULL) {
            string path = "";
            int s = q.size();

            for (int i = 0; i < s; i++) {
                path += to_string(q[i]);
                if (i != s - 1) {
                    path += "->";
                }
            }
            ans.push_back(path);  
        }

        traverse(node->left, ans, q);
        traverse(node->right, ans, q);

        q.pop_back(); 
    }
};
