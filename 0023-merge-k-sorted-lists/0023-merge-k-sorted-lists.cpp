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

class cmp{
    public:
  bool operator() (ListNode* a, ListNode *b){
      return a->val > b->val;
  }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size() == 0) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){   
                pq.push(lists[i]);
            }
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            if(node->next){
                pq.push(node->next);
            }
            
            tail->next = new ListNode(node->val);
            tail = tail->next;
        }
        
        
        return dummy->next;
        
        
        
        
        
        
    }
};