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
    int cnt = 0, curr = 0;
    int add(TreeNode* root) {
        if(!root) return 0;
        curr++;
        return (root->val + add(root->left) + add(root->right));
    }
    void func(TreeNode* root) {
        if(!root) return;
        if(root->val == add(root)/curr) cnt++;
        curr = 0;
        func(root->left);
        func(root->right);
        return;
    }
    int averageOfSubtree(TreeNode* root) {
        func(root);
        return cnt;
    }
};