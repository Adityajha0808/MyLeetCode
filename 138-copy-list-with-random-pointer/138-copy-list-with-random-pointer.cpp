/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        if(mp.find(head)!=mp.end()) return mp[head];
        Node* p = new Node(head->val);
        mp[head] = p;
        p->next = copyRandomList(head->next);
        p->random = copyRandomList(head->random);
        return p;
    }
};