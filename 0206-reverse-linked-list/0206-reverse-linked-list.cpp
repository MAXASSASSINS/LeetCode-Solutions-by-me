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
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
        if(curr == nullptr) {
            head = prev;
            return;
        }
        reverse(head, curr->next, curr);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        reverse(head, head, nullptr);
        
        return head;
    }
};