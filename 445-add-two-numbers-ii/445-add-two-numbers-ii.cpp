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
    void convert(ListNode* head, vector<int>& v) {
        ListNode* curr = head;
        while (curr) {
           v.push_back(curr->val);
           curr = curr->next;
        }
    }   
    void insert(ListNode** head, int x) {
        ListNode* temp = new ListNode;
        ListNode* ptr;
        temp->val = x;
        temp->next = NULL;
        if(*head == NULL) *head = temp;
        else {
           ptr = *head;
           while(ptr->next != NULL)
              ptr = ptr->next;
              ptr->next = temp;
           }
    }
    ListNode* arrayToList(vector<int>& v, int n) {
        ListNode* head = NULL;
        for(int i=0; i<n; i++) {
            insert(&head, v[i]);
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2, vect;
        convert(l1, v1);
        convert(l2, v2);
        int s1 = v1.size(), s2 = v2.size(), x = abs(s1-s2);
        if(s1 > s2) v2.insert(v2.begin(), x, 0);
        if(s1 < s2) v1.insert(v1.begin(), x, 0);
        int carry = 0;
        for(int i=max(s1,s2)-1; i>=0; i--) {
            int sum = v1[i] + v2[i] + carry;
            if(sum > 9) {
               carry = 1;
               vect.push_back(sum%10);
            } else {
               carry = 0;
               vect.push_back(sum);
            }
        }
        if(carry == 1) vect.push_back(1);
        reverse(vect.begin(), vect.end());
        return arrayToList(vect, vect.size());
    }
};