// Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int temp = 0;
        int ss = p1->val + p2->val + temp;
        if(ss >= 10) {
            temp = 1;
            ss -= 10;
        } else {
            temp = 0;
        }
        ListNode *res = new ListNode(ss);
        p1 = p1->next;
        p2 = p2->next;
        ListNode *p = res;
        while((p1 != NULL) && (p2 != NULL)) {
            ss = p1->val + p2->val + temp;
            if(ss >= 10) {
                temp = 1;
                ss -= 10;
            } else {
                temp = 0;
            }
            ListNode *cur = new ListNode(ss);
            p->next = cur;
            p = cur;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 != NULL) {
            ss = p1->val + temp;
            if(ss >= 10) {
                temp = 1;
                ss -= 10;
            } else {
                temp = 0;
            }
            ListNode *cur = new ListNode(ss);
            p->next = cur;
            p = cur;
            p1 = p1->next;
        }
        while(p2 != NULL) {
            ss = p2->val + temp;
            if(ss >= 10) {
                temp = 1;
                ss -= 10;
            } else {
                temp = 0;
            }
            ListNode *cur = new ListNode(ss);
            p->next = cur;
            p = cur;
            p2 = p2->next;
        }
        if(temp == 1) {
            ListNode *cur = new ListNode(1);
            p->next = cur;
        }
        return res;
    }
};
