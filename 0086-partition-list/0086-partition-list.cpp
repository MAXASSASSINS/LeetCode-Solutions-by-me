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
    
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode *hg = NULL, *hs = NULL, *tg = NULL, *ts = NULL;
        
        ListNode *temp = head;
        
        while(temp != nullptr){
            if(temp->val < x){
                if(!hs){
                    hs = temp;
                    ts = temp;
                }
                else{
                    ts->next = temp;
                    ts = temp;
                }
            }    
            else{
                if(!hg){
                    hg = temp;
                    tg = temp;
                }
                else{
                    tg->next = temp;
                    tg = temp;
                }
            }
            temp = temp->next;
        }
        
        if(tg)
            tg->next = nullptr;
        
        if(hs && ts){
            ts->next = hg;      
        }
        
        return hs ? hs : hg;
        
        
    }
};