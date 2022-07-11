class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* next = nullptr;
       ListNode *prev = nullptr;
        while (head != nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};