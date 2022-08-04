class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *headAns = nullptr;
        ListNode *temp = new ListNode();
        ListNode *prev = head;
        ListNode *curr  = head->next;
        while (curr != nullptr){
            int tempSum = 0;
            while (curr != nullptr && curr->val != 0){
                tempSum += curr->val;
                curr = curr->next;
            }
            prev = curr;
            curr = curr->next;
            ListNode *temp2 = new ListNode(tempSum, nullptr);
            if(headAns == nullptr){
                headAns = temp2;
                temp = headAns;
            }
            else{
                temp->next = temp2;
                temp = temp2;
            }
        }
        return headAns;
    }
};