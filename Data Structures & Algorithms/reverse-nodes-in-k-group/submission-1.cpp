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
    ListNode* reverseK(ListNode* h, int k){
            int cnt = 0;
            ListNode* curr = h;
            ListNode* prev = nullptr;
            ListNode* nextNode;
            while(cnt != k){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                cnt++;
            }
            return prev;
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;
        ListNode* group_head = curr;
        ListNode* group_tail;
        ListNode* reversed_head;
        int first = 0;
        while(curr != nullptr){
            ListNode* temp_head;
            curr = curr->next;
            cnt++;
            if(cnt == k){
                temp_head = reverseK(group_head, k);
                if(first == 0){
                    reversed_head = temp_head;
                    first = 1;
                    group_tail = group_head;
                    group_head = temp_head;
                    group_tail->next = curr;
                }
                else{
                    group_tail->next = temp_head;
                    group_tail = group_head;
                    group_tail->next = curr;
                }
                group_head = curr;
                cnt = 0;
            }
        }
        return reversed_head;
    }
};
