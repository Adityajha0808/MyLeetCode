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
    void func(TreeNode* root, vector<int> &v) {
        if(root) {
           v.push_back(root->val);
           func(root->left, v);
           func(root->right, v);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        func(root, v);
        sort(v.begin(), v.end());
        TreeNode* root1 = new TreeNode;
        root1 = root;
        root1->val = v[0];
        TreeNode* r1 = root1;
        for(int i=1; i<v.size(); ++i) {
            r1->left = NULL;
            TreeNode* p = new TreeNode;
            p->val = v[i];
            r1->right = p;
            r1 = p;
        }
        return root1;
    }
};