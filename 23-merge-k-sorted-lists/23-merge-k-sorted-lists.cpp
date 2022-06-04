/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* p;
        if(l1->val < l2->val) {
            p = l1;
            p->next = mergeTwoLists(l1->next, l2);
        }
        else {
            p = l2;
            p->next = mergeTwoLists(l1, l2->next);
        }
        return p;
    }
    ListNode* mergeKLists(vector<ListNode*>& l) {
        if(l.size() < 1) return NULL;
        while(l.size() > 1) {
            l.push_back(mergeTwoLists(l[0], l[1]));
            l.erase(l.begin(), l.begin() + 2);
        }
        return l.front();
    }
};