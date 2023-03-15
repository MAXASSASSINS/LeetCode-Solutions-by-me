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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* odd = oddHead;
        ListNode* even = evenHead;
        
        bool flag = false;
        while(odd && even){
            if(!flag){
                flag = true;
                odd->next = even->next;
                odd = even->next;
            }
            else{
                flag = false;
                even->next = odd->next;
                even = odd->next;
            }
        }
        
        if(!odd){
            odd = oddHead;
            while(odd->next != nullptr){
                odd = odd->next;
            }
        }
        
        odd->next = evenHead;
        
        return head;
        
        
        
    }
};