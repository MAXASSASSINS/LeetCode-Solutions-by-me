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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> temp1;
        vector<int> temp2;
        while(l1 != nullptr){
            temp1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            temp2.push_back(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        int i = temp1.size() - 1;
        int j = temp2.size() - 1;
        vector<int> resSum;
        
        while(i >= 0 && j >= 0){
            int sum = temp1[i] + temp2[j] + carry;
            carry = 0;
            if(sum >= 10){
                carry = 1;
                sum %= 10;
            }
            
            resSum.push_back(sum);
            i--;
            j--;
        }
        
        while(i >= 0){
            int sum = temp1[i] + carry;
            carry = 0;
            if(sum >= 10){
                carry = 1;
                sum %= 10;
            }
            resSum.push_back(sum);
            i--;
        }
        
        while(j >= 0){
            int sum = temp2[j] + carry;
            carry = 0;
            if(sum >= 10){
                carry = 1;
                sum %= 10;
            }
            resSum.push_back(sum);
            j--;
        }
        
        if(carry){
            resSum.push_back(1);
        }
        
       
        
        reverse(resSum.begin(), resSum.end());
        
        
        
        ListNode *head;
        ListNode *ans;
        for(int i = 0; i < resSum.size(); i++){
            ListNode *temp = new ListNode(resSum[i]);
            if(i == 0){
                ans = temp;
            }
            else head->next = temp;
            head = temp;
        }
        
        return ans;
        
    }
};