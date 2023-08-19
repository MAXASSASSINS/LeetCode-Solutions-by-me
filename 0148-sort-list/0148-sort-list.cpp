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
    
    ListNode *merge(ListNode *left, ListNode* right){
        if(!left) return right;
        if(!right) return left;
        
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *head = dummy;
        
        while(left && right){
            if(left->val <= right->val){
                dummy->next = left;
                left = left->next;
            }
            else{
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        
        while(left){
            dummy->next = left;
            left = left->next;
            dummy = dummy->next;
        }
        
        while(right){
            dummy->next = right;
            right = right->next;
            dummy = dummy->next;
        }
        
        return head->next;
        
    }
    
    ListNode *findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *mergeSort(ListNode *head){
        if(!head || !head->next) return head;
        
        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr;
        
        ListNode *l = mergeSort(left);
        ListNode *r = mergeSort(right);
        return merge(l, r);
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};