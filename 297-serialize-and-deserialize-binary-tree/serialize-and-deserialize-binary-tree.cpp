/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s;
        if (root == NULL)
            return s;
        q.push(root);
        s += to_string(root->val);
        s += ',';
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    string val = to_string(node->left->val) + ',';
                    s += val;
                    q.push(node->left);
                } else {
                    s += "n,";
                }
                if (node->right) {
                    string val = to_string(node->right->val) + ',';
                    s += val;
                    q.push(node->right);
                } else {
                    s += "n,";
                }
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        queue<TreeNode*> q;
        if (data.size() == 0)
            return NULL;

        int idx = 0;
        string first;
        while (data[idx] != ',') {
            first += data[idx++];
        }
        idx++;

        int num = stoi(first);
        TreeNode* root = new TreeNode(num);
        q.push(root);
        build(data, q, idx);
        return root;
    }

    void build(string& data, queue<TreeNode*>& q, int& idx) {
        if (data.size() <= 1)
            return;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* newNode = q.front();
                q.pop();

                string s;
                while (idx < data.size() && data[idx] != ',') {
                    s += data[idx++];
                }
                idx++;

                if (s == "n") {
                    newNode->left = NULL;
                } else {
                    int left = stoi(s);
                    TreeNode* newNodeL = new TreeNode(left);
                    newNode->left = newNodeL;
                    q.push(newNode->left);
                }

                s.clear();
                while (idx < data.size() && data[idx] != ',') {
                    s += data[idx++];
                }
                idx++;

                if (s == "n") {
                    newNode->right = NULL;
                } else {
                    int right = stoi(s);
                    TreeNode* newNodeR = new TreeNode(right);
                    newNode->right = newNodeR;
                    q.push(newNode->right);
                }
            }
        }
        return;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));