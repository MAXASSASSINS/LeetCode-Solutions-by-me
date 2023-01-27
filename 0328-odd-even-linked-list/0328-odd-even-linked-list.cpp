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
        if(!head || !head->next) return head;
        
        ListNode *f, *s, *sec;
        f = head;
        s = f->next;
        sec = s;
        
        int count = 1;
        
        while(s != nullptr){
            count++;
            if(count % 2 == 0 && s->next == nullptr){
                f->next = sec;
                return head;
            }
            f->next = s->next;
            f = s;
            s = s->next;
        }
        
        f->next = sec;
        
        return head;
    }
};