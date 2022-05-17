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
    TreeNode* res;
    void func(TreeNode* root, TreeNode* target) {
        if(root->val == target->val) {
            res = root;
            return;
        }
        if(root->left) func(root->left, target);
        if(root->right) func(root->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        func(cloned, target);
        return res;
    }
};