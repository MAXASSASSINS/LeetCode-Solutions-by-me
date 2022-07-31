class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr){
            if(fast->next != nullptr){
                fast = fast->next->next;
            }
            else{
                break;
            }
            slow = slow->next;
        }
        return slow;
    }
};