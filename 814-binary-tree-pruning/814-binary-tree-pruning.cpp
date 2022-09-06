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
    void func(TreeNode* root) {
        if(!root) return;
        if(root->left && !root->left->left && !root->left->right && root->left->val == 0) {
            root->left = NULL;
        }
        if(root->right && !root->right->left && !root->right->right && root->right->val == 0) {
            root->right = NULL;
        }
        func(root->left);
        func(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int n = 200;
        while(n--) {
          func(root);
        }
        if(!root->left && !root->right && root->val == 0) return {};
        return root;
    }
};