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
        stack<ListNode*> st;
        ListNode *temp = head;
        while(temp != nullptr){
            int val = temp->val;
            while(!st.empty() && val > st.top()->val){
                st.pop();
            }
            st.push(temp);
            cout<<st.top()->val<<"\t";
            temp = temp->next;
        }
        
        cout<<st.size();
        
        ListNode *dummy = new ListNode(INT_MAX);
        while(!st.empty()){
            ListNode *top = st.top();
            top->next = dummy->next;
            dummy->next = top;
            st.pop();
        }
        return dummy->next;
    }
};