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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* p = head;
        ListNode* q = NULL;
        int count = 0;
        while(p) {
            count++;
            p = p->next;
        }
        p = head;
        if(k%count == 0) return head;
        if(k > count) k %= count;
        while(k--) {
            while(p->next) {
            q = p;
            p = p->next;
            }
            q->next = NULL;
            p->next = head;
            head = p;
        }
        return head;
    }
};