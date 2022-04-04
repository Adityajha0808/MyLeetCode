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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head;
        int count = 0;
        while(p) {
            count++;
            p = p->next;
        }
        if(count == 0 || count == 1) return head;
        p = head;
        for(int i=0; i<k-1; i++) {
            p = p->next;
        }
        int firstData = p->val;
        ListNode* q = head;
        for(int i=0; i<count-k; i++) {
            q = q->next;
        }
        swap(p->val, q->val);
        p = head;
        return p;
    }
};