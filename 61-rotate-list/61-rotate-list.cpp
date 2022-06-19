class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *temp = head;
        ListNode *lastNode = head;
        int countNodes = 0;
        while (temp!= nullptr){
            countNodes++;
            lastNode = temp;
            temp = temp->next;
        }
        int rotateRight = k % countNodes;
        if(rotateRight == 0){
            return head;
        }
        temp = head;
        for (int i = 0; i < countNodes - rotateRight - 1; ++i) {
            temp = temp->next;
        }
        lastNode->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};