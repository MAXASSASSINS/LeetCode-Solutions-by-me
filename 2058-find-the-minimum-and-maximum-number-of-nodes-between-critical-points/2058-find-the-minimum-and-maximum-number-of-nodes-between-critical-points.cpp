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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if(!head->next->next) return {-1, -1};
        
        
        ListNode *temp = head->next;
        ListNode *prev = head;
        
        int cpIndex = -1;
        int minCpIndex = -1;
        
        int index = 1;
        
        while(temp && temp->next){
            ListNode *next = temp->next;
            
            if((next->val < temp->val && prev->val < temp->val) || (next->val > temp->val && prev->val > temp->val)){
                cout<<prev->val<<temp->val<<next->val<<endl;
                if(cpIndex == -1){
                    minCpIndex = index;
                    cpIndex = index; 
                }
                else{
                    cout<<cpIndex<<index<<minCpIndex<<endl;
                    int dis = index - cpIndex;
                    int maxDis = index - minCpIndex;
                    cpIndex = index;
                    
                    if(ans[0] == -1){
                        ans[0] = dis;
                        ans[1] = dis;
                    }
                    else{
                        ans[0] = min(ans[0], dis);
                        ans[1] = maxDis;
                    }
                }
                
            }
            index++;
            prev = temp;
            temp = temp->next;
        }
        
        return ans;
        
        
    }
};