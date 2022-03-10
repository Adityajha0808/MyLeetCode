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
    bool check(ListNode* l1, ListNode* l2) {
        int a = 0, b = 0;
        while(l1) {
            a++;
            l1 = l1->next;
        }
        while(l2) {
            b++;
            l2 = l2->next;
        }
        return b > a;
    }
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        if(check(list1,list2)) swap(list1,list2);
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        int carry = 0;
        while(l1) {
            int sum = l1->val + (l2 ? l2->val : 0) + carry;
            if(sum < 10) {
                l1->val = sum;
                carry = 0;
            } else {
                l1->val = sum%10;
                carry = sum/10;
            }
            if(!l1->next and carry) {
                ListNode* p = new ListNode;
                p->val = carry;
                l1->next = p;
                p->next = NULL;
                l1 = l1->next;
            }
            l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return list1;
    }
};