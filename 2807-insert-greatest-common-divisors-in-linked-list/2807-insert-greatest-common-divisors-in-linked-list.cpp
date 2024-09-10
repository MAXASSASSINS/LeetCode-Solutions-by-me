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
    int gcd(int x, int y){
        if(x < y){
            swap(x, y);
        }
        
        while(y != 0){
            int temp = y;
            y = x % y;
            x = temp;
        }
        
        return x;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head;
        ListNode *next = head->next;
        
        while(next){
            int x = gcd(curr->val, next->val);
            ListNode *node = new ListNode(x);
            curr->next = node;
            node->next = next;
            curr = next;
            next = next->next;
        }
        
        return head;
    }
};