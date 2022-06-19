class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *temp = head;
        int countNodes = 0;
        while (temp!= nullptr){
            countNodes++;
            temp = temp->next;
        }
        int rotateRight = k % countNodes;
        for (int i = 0; i < rotateRight; ++i) {
            ListNode *temp2 = head;
            ListNode *prevTemp2 = head;
            while (temp2->next != nullptr){
                prevTemp2 = temp2;
                temp2 = temp2->next;
            }
            temp2->next = head;
            prevTemp2->next = nullptr;
            head = temp2;
        }
        return head;
    }
};