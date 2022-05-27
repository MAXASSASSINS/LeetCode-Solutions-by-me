class Solution {
public:
    ListNode * insertNode(int val, ListNode *head){
        ListNode *temp = new ListNode(val);
        if (head == nullptr){
            head = temp;
            return head;
        }
        ListNode *temp2 = head;
        while(temp2->next != nullptr){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        int num1 = 0, num2 = 0, num = 0;
        int i = 0;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int val = l1->val + l2->val;
            val += carry;
            if(val >= 10){
                val %= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            head = insertNode(val, head);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr){
            int val = l1->val + carry;
            if(val >= 10){
                val %= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            head = insertNode(val, head);
            l1 = l1->next;

        }
        while (l2 != nullptr){
            int val = l2->val + carry;
            if(val >= 10){
                val %= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            head = insertNode(val, head);
            l2 = l2->next;
        }
        if(carry == 1){
            head = insertNode(carry, head);
        }
        return head;
    }
};