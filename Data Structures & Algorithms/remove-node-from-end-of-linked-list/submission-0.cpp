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
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        if(len == 1) return nullptr;
        int target_prev = len - n;
        if(target_prev == 0) return head->next;
        curr = head;
        while((target_prev-1) != 0){
            target_prev--;
            curr = curr->next;
        }
        ListNode* nextNode = curr->next->next;
        curr->next = nextNode;
        return head;
    }
};
