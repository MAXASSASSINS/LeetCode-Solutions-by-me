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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int cnt = 0;
        ListNode *temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        
        int numList = 0;
        int rem = 0;
        int size = 0;
        
        if(k >= cnt){
            rem = cnt;
        }
        else{
            rem = cnt % k;
            size = cnt / k;
        }
        
        
        
        temp = head;
        while(k > 0){
            res.push_back(temp);
            ListNode *prev = temp;
            for(int i = 0; i < size + (rem > 0); i++){
                prev = temp;
                temp = temp->next;
            }
            if(prev)
                prev->next = nullptr;
            rem--;
            k--;
        }
        
        return res;
        
        
        
    }
};