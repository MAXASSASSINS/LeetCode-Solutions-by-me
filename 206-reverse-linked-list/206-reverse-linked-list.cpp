class Solution {
public:
    ListNode *helper(ListNode *prev, ListNode *next, ListNode *head){
        if (head == nullptr){
            return prev;
        }
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        return helper(prev, next, head);
    }
    ListNode* reverseList(ListNode* head) {
        return helper(nullptr, nullptr, head);
//       ListNode* next = nullptr;
//       ListNode *prev = nullptr;
//        while (head != nullptr){
//            next = head->next;
//            head->next = prev;
//            prev = head;
//            head = next;
//        }
    }
};