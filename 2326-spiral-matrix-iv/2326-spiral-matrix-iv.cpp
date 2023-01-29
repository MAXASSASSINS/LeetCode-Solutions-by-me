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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int rs = 0;
        int cs = 0;
        int re = m - 1;
        int ce = n - 1;
        while(head != nullptr){
            
            // left to right
            int i = cs;
            while(head != nullptr && i <= ce){
                ans[rs][i] = head->val;
                i++;
                head = head->next;
                
            }
            rs++;
            
            // top to bottom
            i = rs;
            while(head != nullptr && i <= re){
                ans[i][ce] = head->val;
                head = head->next;
                i++;
            }
            ce--;
            
            // right to left
            i = ce;
            while(head != nullptr && i >= cs){
                ans[re][i] = head->val;
                i--;
                head = head->next;
            }
            re--;
            
            // bottom to top
            i = re;
            while(head != nullptr && i >= rs){
                ans[i][cs] = head->val;
                i--;
                head = head->next;
            }
            cs++;
        }
        
        return ans;;
        
    }
};