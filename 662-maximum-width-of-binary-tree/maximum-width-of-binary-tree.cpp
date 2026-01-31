class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                long long currIndex = index - minIndex;

                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;

                if (node->left)
                    q.push({node->left, currIndex * 2 + 1});

                if (node->right)
                    q.push({node->right, currIndex * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};
