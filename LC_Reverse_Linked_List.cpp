// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* p = head;
        ListNode* q = p->next;
        p->next = nullptr;
        ListNode* t;
        while(q) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};
