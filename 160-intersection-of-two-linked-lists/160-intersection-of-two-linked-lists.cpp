class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        map<ListNode *, int> m;
        while (headA != nullptr){
            m[headA] = headA->val;
            headA = headA->next;
        }

        while (headB != nullptr){
            int val = 0;
            val = m[headB];
            if(val != 0){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};