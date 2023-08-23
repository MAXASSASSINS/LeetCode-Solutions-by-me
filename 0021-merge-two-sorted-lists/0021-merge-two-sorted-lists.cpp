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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *p1 = list1, *p2 = list2;
        ListNode *curr = nullptr;
        
        ListNode *head = nullptr;
        if(list1->val > list2->val){
            head = list2;
            curr = head;
            p2 = p2->next;
        }
        else{
            head = list1;
            curr = head;
            p1 = p1->next;
        }
        
        while(p2 && p1){
            if(p2->val <= p1->val){
                curr->next = p2;
                p2 = p2->next;
            }
            else{
                curr->next = p1;
                p1 = p1->next;
            }
            curr = curr->next;
        }
        
        if(p2){
            curr->next = p2;
        }
        
        if(p1){
            curr->next = p1;
        }
        
        return head;
    }
};