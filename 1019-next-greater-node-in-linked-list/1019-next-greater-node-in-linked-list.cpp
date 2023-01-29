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
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> temp;
        while(head != nullptr){
            temp.push_back(head->val);
            head = head->next;
        }
        
        int n = temp.size();
        vector<int> ans(n, 0);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            
            while(!st.empty() && temp[i] > temp[st.top()]){
                ans[st.top()] = temp[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        return ans;
        
        
    }
};