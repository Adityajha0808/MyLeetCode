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
    void getPath(TreeNode* root, vector<vector<int>>& vect, vector<int>& v, int x) {
        if(!root) return;
        v.push_back(root->val);
        if(!root->left && !root->right && x == root->val) {
            vect.push_back(v);
            v.pop_back();
            return;
        }
        getPath(root->left, vect, v, x - root->val);
        getPath(root->right, vect, v, x - root->val);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int x) {
        vector<vector<int>> vect;
        vector<int> v;
        getPath(root, vect, v, x);
        return vect;
    }
};