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
    vector<int> v;
    int i=0;
    void func(TreeNode* root) {
        if(root) {
           v.push_back(root->val);
           func(root->left);
           func(root->right);
        }
    }
    void func2(TreeNode* root) {
        if(root) {
           func2(root->left);
           root->val = v[i++];
           func2(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        func(root);
        sort(v.begin(), v.end());
        func2(root);
    }
};