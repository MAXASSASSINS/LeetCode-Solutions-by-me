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
    void deleteNode(ListNode* node) {
        ListNode *temp = node;
        ListNode *temp2 = node->next;
        while(temp2->next != nullptr){
            swap(temp->val, temp2->val);
            temp2 = temp2->next;
            temp = temp->next;
        }
        swap(temp->val, temp2->val);
        temp->next = nullptr;
        
    }
};