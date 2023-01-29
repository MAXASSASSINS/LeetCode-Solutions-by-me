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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* f = head;
        ListNode* s = head;
        
        int len = 0;
        while(s != nullptr){
            s = s->next;
            len++;
        }
        
        for(int i = 0; i < k - 1; i++){
            f = f->next;
        }
        
        s = head;
        for(int i = 0; i < len - k; i++){
            s = s->next;
        }
        
        int temp = f->val;
        f->val = s->val;
        s->val = temp;
        
        return head;
    }
};