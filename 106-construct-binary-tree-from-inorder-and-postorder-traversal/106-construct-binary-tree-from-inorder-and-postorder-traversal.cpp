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
    TreeNode* func(vector<int>& inorder, vector<int>& postorder, int start, int end, int* pIndex, unordered_map<int, int>& mp) {
        if(start > end) return NULL;
        int curr = postorder[*pIndex];
        TreeNode* root = new TreeNode(curr);
        (*pIndex)--;
        if(start == end) return root;
        int iIndex = mp[curr];
        root->right = func(inorder, postorder, iIndex+1, end, pIndex, mp);
        root->left = func(inorder, postorder, start, iIndex-1, pIndex, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i=0; i<n; i++)
           mp[inorder[i]] = i;
        int index = n-1;
        return func(inorder, postorder, 0, n-1, &index, mp);
    }
};