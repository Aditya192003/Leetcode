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
    unordered_map<int,int> mpl; // left tree node val , height 
    unordered_map<int,int> mpr;
    unordered_map<int,int> ans;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        if(!root) return {};
        int n = queries.size();
        findDepth(root);

        find(root->left, mpr[root->val],1);
        find(root->right, mpl[root->val],1);

        vector<int> res(n);

        for(int i=0; i<n; i++){
            res[i] = ans[queries[i]];
        }
        return res;
    }
    
    void find(TreeNode* root, int mxvalue, int depth){
        if(!root) 
            return;
        ans[root->val] =  mxvalue;

        find(root->left, max(mxvalue, depth+ mpr[root->val]), depth+1);
        find(root->right, max(mxvalue, depth+mpl[root->val]), depth+1);
    }
    
    int findDepth(TreeNode* root){
        int depth =0;
        if(!root)
            return 0;
        int l = findDepth(root->left);
        int r = findDepth(root->right);
        mpl[root->val] = l; // cureent node max height 
        mpr[root->val] = r; 
        return 1+ max(l,r);
    }
};