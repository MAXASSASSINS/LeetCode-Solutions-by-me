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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode * temp = head;
        while (temp != nullptr){
            sz++;
            temp = temp->next;
        }
        int posToDelete  = sz - n;
        
        temp = head;
        // delete from head
        if(posToDelete == 0){
            head = temp->next;
            return head;
        }
        
        // delete from any place other than head
        for (int i = 0; i < posToDelete - 1; ++i) {
            temp = temp->next;
        }
        ListNode *temp2 = temp->next;
        if(temp->next != nullptr){
            temp->next = temp2->next;
        }
        delete temp2;
        return head;
    }
};