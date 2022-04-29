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
    void convert(ListNode* head, vector<int>& a) {
        while(head) {
            a.push_back(head->val);
            head = head->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> a;
        convert(head, a);
        int n = a.size();
        for(int i=0; i<n; i+=k) {
            if(i+k-1 >= n) break;
            int l = i, h = i+k-1;
            while(l < h) {
                swap(a[l],a[h]);
                l++;
                h--;
            }
        }
        ListNode* p = head;
        for(auto i: a) {
            p->val = i;
            p = p->next;
        }
        return head;
    }
};