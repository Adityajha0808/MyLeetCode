/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vect;
        if(!root) return vect;
        queue<Node*> q;
        q.push(root);
        vector<int> v;
        v.push_back(root->val);
        vect.push_back(v);
        while(!q.empty()) {
           int size = q.size(); 
           v.clear();
           while(size--) {
              Node* t = q.front();
              for(auto node: t->children){
                  v.push_back(node->val);
                  q.push(node);
              }
              q.pop();
           }
           if(v.empty()) continue;
           vect.push_back(v);
        }
        return vect;
    }
};