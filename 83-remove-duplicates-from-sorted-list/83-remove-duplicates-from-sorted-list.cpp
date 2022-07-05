class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = head, *curr = head->next;
        while (curr != nullptr){
            if(curr->val == prev->val){
                while (curr != nullptr && curr->val == prev->val){
                    curr = curr->next;
                }
                if(curr == nullptr){
                    prev->next = nullptr;
                    return head;
                }
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};