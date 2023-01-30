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
    ListNode* removeNodes(ListNode* head) {
        ListNode *ans = nullptr;
        stack<int> st;
        while(head != nullptr){
            while(!st.empty() && head->val > st.top()){
                st.pop();
            }
            st.push(head->val);
            head = head->next;
        }
        
        
        while(!st.empty()){
            ListNode *temp = new ListNode(st.top());
            st.pop();
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
};