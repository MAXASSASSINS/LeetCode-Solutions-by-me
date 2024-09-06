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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        
        while(curr){
            if(st.find(curr->val) != st.end()){
                ListNode *next = curr->next;
                curr->next = nullptr;
                prev->next = next;
                delete(curr);
                curr = next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy->next;
        
        
    }
};