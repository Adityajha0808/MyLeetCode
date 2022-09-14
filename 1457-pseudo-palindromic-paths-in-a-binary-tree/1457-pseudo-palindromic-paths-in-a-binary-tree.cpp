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
    int res = 0;
    void func(TreeNode* root, int x) {
        if(!root) return;
        x ^= (1 << root->val);
        if(!root->left and !root->right) {
            if((x & (x - 1)) == 0)
                res++;
        }
        func(root->left, x);
        func(root->right, x);
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        func(root, 0);
        return res;
    }
};