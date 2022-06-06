/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        while(p!=q) {
            p = (p ? p->next : l2);
            q = (q ? q->next : l1);
        }
        return p;
    }
};