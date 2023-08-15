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
    void insert(ListNode *t1, int val){
        ListNode *node = new ListNode(val);
        t1->next = node;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode *t1 = new ListNode(INT_MIN);
        ListNode *t2 = new ListNode(INT_MIN);
        ListNode *h1 = t1, *h2 = t2;
        
        ListNode *temp = head;
        while(temp != nullptr){
            if(temp->val < x){
                insert(t1, temp->val);
                t1 = t1->next;
            }
            else{
                insert(t2, temp->val);
                t2 = t2->next;
            }
            temp = temp->next;
        }
        
        t1->next = h2->next;
        return h1->next;
    }
};