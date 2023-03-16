/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        int cnta = 0;
        int cntb = 0;
        while(tempA){
            cnta++;
            tempA = tempA->next;
        }
        while(tempB){
            cntb++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        if(cnta <= cntb){
            for(int i = 0; i < cntb - cnta; i++){
                tempB = tempB->next;
            }
        }
        else{
            for(int i = 0; i < cnta - cntb; i++){
                tempA = tempA->next;
            }
        }
        
        while(tempA && tempB){
            if(tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return nullptr;
    }
};