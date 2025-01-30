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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> q; 
        
        if (root) {
            q.push({root, {0, 0}});
        }
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes[col][row].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& col : nodes) {
            vector<int> column;
            for (auto& row : col.second) {
                column.insert(column.end(), row.second.begin(), row.second.end());
            }
            result.push_back(column);
        }
        
        return result;
    }
};