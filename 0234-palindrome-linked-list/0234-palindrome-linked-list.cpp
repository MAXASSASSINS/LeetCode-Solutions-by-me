class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        int length = 0;
        while (temp != nullptr){
            temp = temp->next;
            length++;
        }
        int first = 0, second;
        if (length % 2 == 0){
            second = length / 2;
        }
        else{
            second = length / 2 + 1;
        }
        temp = head;
        ListNode *temp2 = head;
        while (second != 0){
            second--;
            temp2 = temp2->next;
        }
        ListNode *head2 = temp2;
        ListNode *prev = nullptr, *next = nullptr;
        while (temp2 != nullptr){
            next = temp2->next;
            temp2->next = prev;
            prev = temp2;
            temp2 = next;
        }
        head2 = prev;
        temp = head;
        while(head2 != nullptr){
            if(temp->val != head2->val){
                return false;
            }
            head2 = head2->next;
            temp = temp->next;
        }
        return true;
    }
};