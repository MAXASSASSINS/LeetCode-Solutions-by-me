class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0;
        int l2 = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA != nullptr){
            l1++;
            tempA = tempA->next;
        }
        while (tempB != nullptr){
            l2++;
            tempB = tempB->next;
        }
        int move1 = max(0, l1 - l2);
        int move2 = max(0, l2 - l1);

        tempA = headA;
        tempB = headB;
        while (move1 > 0){
            tempA = tempA->next;
            move1--;
        }
        while (move2 > 0){
            tempB = tempB->next;
            move2--;
        }
        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};