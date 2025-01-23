#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph; 
    
    void buildGraph(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        
        if (parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr); 
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        
        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            if (distance == k) break;
            distance++;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                
                for (TreeNode* neighbor : graph[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};
