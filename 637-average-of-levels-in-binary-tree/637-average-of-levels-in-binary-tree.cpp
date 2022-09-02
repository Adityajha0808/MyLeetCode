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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int size = q.size(), cnt = 0;
            long total = 0;
            while(size--) {
                auto x = q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                total += x->val;
                cnt++;
            }
            res.push_back((double)total/cnt);
        }
        return res;
    }
};