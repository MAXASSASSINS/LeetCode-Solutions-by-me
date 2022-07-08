class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val){
            head = head->next;
        }
        if(head == nullptr){
            return head;
        }

        ListNode *curr = head->next;
        ListNode *prev = head;

        while (curr != nullptr) {
            while (curr != nullptr && curr->val == val){
                curr = curr->next;
            }
            prev->next = curr;
            prev = curr;
            if(curr != nullptr){
                curr = curr->next;
            }
        }
        return head;
    }
};