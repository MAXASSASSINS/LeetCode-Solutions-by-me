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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return head->next;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowPrev = slow;
        
        while(fast && fast->next){
            slowPrev = slow;
            slow = slow->next;
            if(fast->next){
                fast = fast->next->next;
            }
        }
        
        slowPrev->next = slow->next;
        return head;
        
    }
};