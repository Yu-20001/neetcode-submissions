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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* r_curr = slow->next;
        ListNode* r_prev = nullptr;
        slow->next = nullptr;
        while(r_curr){
            ListNode* nextNode = r_curr->next;
            r_curr->next = r_prev;
            r_prev = r_curr;
            r_curr = nextNode;
        }
        while(head && r_prev){
            ListNode* l_nextNode = head->next;
            head->next = r_prev;
            r_prev = r_prev->next;
            head = head->next;
            head->next = l_nextNode;
            head = head->next;
        }
        
    }
};