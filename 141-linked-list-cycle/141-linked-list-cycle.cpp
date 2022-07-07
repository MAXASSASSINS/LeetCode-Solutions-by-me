class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            slow = slow->next;
            if(fast->next != nullptr){
                fast = fast->next->next;
            }
            else{
                return false;
            }
            if(slow == nullptr || fast == nullptr){
                return false;
            }

        }while(slow != fast);
        return true;
    }
};