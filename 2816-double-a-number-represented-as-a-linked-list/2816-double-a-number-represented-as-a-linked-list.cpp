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
    ListNode* doubleIt(ListNode* head) {
        vector<int> num;
        while(head){
            num.push_back(head->val);
            head = head->next;
        }
        
        vector<int> ans;
        int carry = 0;
        reverse(num.begin(), num.end());
        for(int i = 0; i < num.size(); i++){
            int sum = num[i] * 2 + carry;
            if(sum >= 10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            ans.push_back(sum % 10);
        }
        
        if(carry){
            ans.push_back(carry);
        }
        
        reverse(ans.begin(), ans.end());
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for(int i = 0; i < ans.size(); i++){
            ListNode *node = new ListNode(ans[i]);
            tail->next = node;
            tail = node;
        }
        
        return dummy->next;
        
        
    }
};