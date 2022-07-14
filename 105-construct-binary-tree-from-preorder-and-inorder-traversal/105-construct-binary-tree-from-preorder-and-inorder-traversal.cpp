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
    int preIndex = 0;
    TreeNode* func(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if(start == end) return root;
        int inIndex;
        for(int i=start; i<=end; i++) {
           if(inorder[i] == root->val) {
               inIndex = i;
               break;
           }
        }
        root->left = func(preorder, inorder, start, inIndex-1);
        root->right = func(preorder, inorder, inIndex+1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        root = func(preorder, inorder, 0, inorder.size()-1);
        return root;
    }
};