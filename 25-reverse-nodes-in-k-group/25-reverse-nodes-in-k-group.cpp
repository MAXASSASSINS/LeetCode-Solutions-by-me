class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(INT_MIN, head);
        head = dummy;
        ListNode *p = head;
        ListNode *f = head->next;
        ListNode *l = f;
        ListNode *n = l;
        while (n != nullptr){
            for (int i = 0; i < k  - 1; ++i) {
                if (l == nullptr)
                    break;
                l = l->next;
            }
            if (l == nullptr)
                break;
            n = l->next;
            ListNode *temp = f;
            ListNode *temp2 = f->next;
            while (temp != l){
                ListNode *temp3 = temp2->next;
                temp2->next = temp;
                temp = temp2;
                temp2 = temp3;
            }



            p->next = l;
            f->next = n;

            p = f;
            f = n;
            l = f;
        }
        return dummy->next;
    }
};