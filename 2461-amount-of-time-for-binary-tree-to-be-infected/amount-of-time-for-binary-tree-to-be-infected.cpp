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

    void markParent(unordered_map<TreeNode* , TreeNode*>& p,TreeNode* r){
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left){
                    p[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    p[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
    }

    TreeNode* find(TreeNode *node, int num){
        if(node == NULL)return NULL;
        if(node->val == num)return node;
        TreeNode *left = find(node->left, num);
        if(left!=NULL)return left;
        return find(node->right,num);
        return NULL;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> parents;
        int ans = -1;
        unordered_map<TreeNode* , bool> visited;
        markParent(parents,root);
        TreeNode *node = find(root, start);
        queue<TreeNode*> queue;
        queue.push(node);
        visited[node] = true;
        while(!queue.empty()){
            int size = queue.size();
            for(int i=0;i<size;i++){
                TreeNode *temp = queue.front();
                queue.pop();
                if(temp->left && (!visited[temp->left])){
                    visited[temp->left] = true;
                    queue.push(temp->left);
                }
                if(temp->right && (!visited[temp->right])){
                    visited[temp->right] = true;
                    queue.push(temp->right);
                }
                if(parents[temp] && (!visited[parents[temp]])){
                    visited[parents[temp]] = true;
                    queue.push(parents[temp]);
                }
            }
            ans++;
        }
        return ans;
    }
};