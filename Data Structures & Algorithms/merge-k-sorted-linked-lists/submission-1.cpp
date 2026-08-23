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
private:
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode* node : lists){
            if(node != nullptr){
                pq.push(node);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!pq.empty()){
            ListNode* min_node = pq.top();
            pq.pop();
            curr->next = min_node;
            curr = curr->next;
            if(min_node->next != nullptr){
                pq.push(min_node->next);
            }
        }
        return dummy->next;
    }
};
