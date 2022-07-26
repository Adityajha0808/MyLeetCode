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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* p = head;
        while(p) {
            count++;
            p = p->next;
        }
        p = head;
        if(count == 1) return NULL;
        count = count - n + 1;
        if(count == 1) {
            head = p->next;
            return head;
        }
        ListNode* q = NULL;
        while(count > 1) {
            q = p;
            p = p->next;
            count--;
        }
        q->next = p->next;
        delete(p);
        q = head;
        return q;
    }
};