class Solution {
public:
    ListNode* reverse(ListNode *head, ListNode* tail){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != tail){
            ListNode * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        tail->next = prev;
        return tail;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right){
            return head;
        }
        ListNode *temp = head;
        ListNode *temp2 = head;
        ListNode *leftPrev = nullptr;
        ListNode *rightNext = nullptr;
        for (int i = 0; i < left - 1; ++i) {
            leftPrev = temp;
            temp = temp->next;
        }
        for (int i = 0; i < right - 1; ++i) {
            temp2 = temp2->next;
            if (temp2 != nullptr) {
                rightNext = temp2->next;
            } else {
                rightNext = nullptr;
            }
        }
        ListNode *headOfReverseList = reverse(temp, temp2);
        if(leftPrev == nullptr){
            head = headOfReverseList;
        }
        else{
            leftPrev->next = headOfReverseList;
        }
        temp->next = rightNext;
        return head;
    }
};