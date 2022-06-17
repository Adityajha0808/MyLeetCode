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
    int cams;
    set<TreeNode*> st;
public:
    void func(TreeNode* root, TreeNode* p) {
        if(root) {
            func(root->left, root);
            func(root->right, root);
            if(!p and st.find(root) == st.end() or st.find(root->left) == st.end() or st.find(root->right) == st.end()) {
                cams++;
                st.insert(root);
                st.insert(p);
                st.insert(root->left);
                st.insert(root->right);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        cams = 0;
        st.insert(NULL);
        func(root, NULL);
        return cams;
    }
};