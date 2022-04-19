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
    void func(TreeNode* root, TreeNode*& p, TreeNode*& l, TreeNode*& r) {
        if(root) {
            func(root->left, p, l, r);
            if(p) {
                if(root->val < p->val) {
                    if(!l) l = p;
                    r = root;
                }
            }
            p = root;
            func(root->right, p, l, r);
        }
    }
    void recoverTree(TreeNode* root) {
        TreeNode* p = NULL;
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        func(root, p, l, r);
        swap(l->val, r->val);
    }
};