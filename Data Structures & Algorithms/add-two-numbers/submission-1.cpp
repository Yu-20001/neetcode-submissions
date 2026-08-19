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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int rem = 0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(l1 != nullptr && l2 != nullptr){
            rem = (carry + (l1->val + l2->val)) % 10;
            carry = (carry + (l1->val + l2->val)) / 10;
            ListNode* newNode = new ListNode(rem);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == nullptr && l2 == nullptr && carry > 0){
            ListNode* newNode = new ListNode(carry);
            cur->next = newNode;
            return dummy->next;
        }
        if(l1 == nullptr){
            while(l2 != nullptr){
                rem = (carry + l2->val) % 10;
                carry = (carry + l2->val) / 10;
                ListNode* newNode = new ListNode(rem);
                cur->next = newNode;
                cur = cur->next;
                l2 = l2->next;
            }
            if(carry > 0){
                ListNode* newNode = new ListNode(carry);
                cur->next = newNode;
            }
        }
        else if(l2 == nullptr){
            while(l1 != nullptr){
                rem = (carry + l1->val) % 10;
                carry = (carry + l1->val) / 10;
                ListNode* newNode = new ListNode(rem);
                cur->next = newNode;
                cur = cur->next;
                l1 = l1->next;
            }
            if(carry > 0){
                ListNode* newNode = new ListNode(carry);
                cur->next = newNode;
            }
        }
        return dummy->next;
    }
};
