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
    vector<int> v, a;
    void func(TreeNode* root) {
        if(root) {
            root->val += (a.back() - a[lower_bound(v.begin(), v.end(), root->val) - v.begin()]);
            func(root->left);
            func(root->right);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* root1 = root;
        stack<TreeNode*> st;
        while(root1 or st.size()) {
            while(root1) {
                st.push(root1);
                root1 = root1->left;
            }
            root1 = st.top();
            st.pop();
            v.push_back(root1->val);
            root1 = root1->right;
        }
        a = v;
        for(int i=1; i<a.size(); ++i) a[i] += a[i-1];
        func(root);
        return root;
    }
};