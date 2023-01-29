/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *tempA = list1;
        ListNode *tempB = list1;
        ListNode *list2last = list2;
        
        for(int i = 0; i < a - 1; i++){
            tempA = tempA->next;
        }
        
        for(int i = 0; i < b; i++){
            tempB = tempB->next;
        }
        
        while(list2last->next != nullptr){
            list2last = list2last->next;
        }
        
        tempA->next = list2;
        
        list2last->next = tempB->next;
        tempB->next = nullptr;
        
        return list1;
        
        
    }
};