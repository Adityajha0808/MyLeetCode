/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPath(TreeNode* root, vector<TreeNode*>& arr, TreeNode* x) {
        if(!root) return false;
        arr.push_back(root);   
        if(root == x) return true;
        if(hasPath(root->left, arr, x) or hasPath(root->right, arr, x)) return true;  
        arr.pop_back();
        return false;           
     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        hasPath(root, v1, p);
        hasPath(root, v2, q);
        int i, j;
        for(i=0, j=0; i<v1.size() and j<v2.size(); ++i, ++j) {
            if(v1[i] != v2[j])
                return v1[i-1];
        }
        if(j==v2.size()) return v2[j-1];
        return v1[i-1];
    }
};