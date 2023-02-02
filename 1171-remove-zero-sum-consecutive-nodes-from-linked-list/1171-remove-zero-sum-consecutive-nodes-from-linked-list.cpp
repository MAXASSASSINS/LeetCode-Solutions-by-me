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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head;
        unordered_map<int, ListNode*> m;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        m[0] = dummy;
        
        int sum = 0;
        while(temp != nullptr){
            sum += temp->val;
            if(m.find(sum) == m.end()){
                m[sum]  = temp;
            }
            else{
                ListNode *start = m[sum];
                int tmpSum = sum;
                while(start != nullptr && start != temp){
                    start = start->next;
                    tmpSum += start->val;
                    if(start != temp)
                        m.erase(tmpSum);
                }
                m[sum]->next = temp->next;
            }
            if(temp == nullptr) break;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};