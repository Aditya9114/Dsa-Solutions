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

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = findNode(root,key);
        if(node == NULL) return root;

        // Case 1: Leaf node
        if(node->left == NULL && node->right == NULL){
            TreeNode* parent = findParent(root,key);

            if(parent == NULL){ // node is root
                delete node;
                return NULL;
            }

            if(parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;

            delete node;
            return root;
        }

        // Case 2: One child
        if(node->left == NULL || node->right == NULL){
            TreeNode* parent = findParent(root,key);

            TreeNode* child;
            if(node->left)
                child = node->left;
            else
                child = node->right;

            if(parent == NULL){ // deleting root
                delete node;
                return child;
            }

            if(parent->left == node)
                parent->left = child;
            else
                parent->right = child;

            delete node;
            return root;
        }

        // Case 3: Two children
        auto p = findPredecessor(node);
        TreeNode* predecessor = p.first;
        TreeNode* parent = p.second;

        node->val = predecessor->val;

        if(parent->right == predecessor)
            parent->right = predecessor->left;
        else
            parent->left = predecessor->left;

        delete predecessor;

        return root;
    }

    TreeNode *findParent(TreeNode *r, int k){
        while(r){
            if((r->left && r->left->val == k) ||
               (r->right && r->right->val == k))
                return r;

            if(k < r->val)
                r = r->left;
            else
                r = r->right;
        }
        return NULL;
    }

    TreeNode* findNode(TreeNode* r,int k){
        while(r){
            if(r->val == k)
                return r;

            if(k < r->val)
                r = r->left;
            else
                r = r->right;
        }
        return NULL;
    }

    pair<TreeNode*, TreeNode*> findPredecessor(TreeNode *r){
        TreeNode* pre = r->left;
        TreeNode* prepar = r;

        while(pre->right){
            prepar = pre;
            pre = pre->right;
        }

        return {pre, prepar};
    }
};