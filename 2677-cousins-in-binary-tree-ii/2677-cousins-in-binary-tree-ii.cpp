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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            int level_sum = 0;
            vector<TreeNode*> level_nodes;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level_nodes.push_back(node);

                if (node->left) {
                    level_sum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    level_sum += node->right->val;
                    q.push(node->right);
                }
            }

            for (TreeNode* node : level_nodes) {
                int sibling_sum = 0;
                if (node->left) sibling_sum += node->left->val;
                if (node->right) sibling_sum += node->right->val;

                if (node->left) node->left->val = level_sum - sibling_sum;
                if (node->right) node->right->val = level_sum - sibling_sum;
            }
        }
        
        return root;
    }
};
