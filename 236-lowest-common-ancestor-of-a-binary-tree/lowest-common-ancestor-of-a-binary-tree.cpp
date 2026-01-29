class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ans1, ans2;
        vector<TreeNode*> queue;
        findPath(root, p, ans1, queue);
        queue.clear();
        findPath(root, q, ans2, queue);
        
        int Size;
        if(ans1.size() > ans2.size()){
            Size = ans2.size();  // Changed: should use the smaller size
        }
        else{
            Size = ans1.size();  // Changed: should use the smaller size
        }
        
        TreeNode* prev = root;
        for(int i = 0; i < Size; i++){
            if((ans1[i]->val) != (ans2[i]->val)){
                break;
            }
            prev = ans1[i];
        }
        return prev;
    }
    
    void findPath(TreeNode *curr, TreeNode* node, vector<TreeNode*> &path, vector<TreeNode*> &q){
        if(curr == NULL) return;
        q.push_back(curr);
        if(curr->val == node->val){
            path = q;
        }
        findPath(curr->left, node, path, q);
        findPath(curr->right, node, path, q);
        q.pop_back();
    }
};