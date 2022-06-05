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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *head1 = list1, *head2 = list2, *prev1 = nullptr, *prev2 = nullptr;
        ListNode *head;
        if (list1->val <= list2->val) {
            head = list1;
            prev1 = head1;
            head1 = head1->next;
        }
        if (list1->val > list2->val) {
            head = list2;
            prev2 = head2;
            head2 = head2->next;
        }
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                if (prev2 != nullptr) {
                    prev2->next = head1;
                    prev2 = nullptr;
                }
                prev1 = head1;
                head1 = head1->next;
            } else {
                if (prev1 != nullptr) {
                    prev1->next = head2;
                    prev1 = nullptr;
                }
                prev2 = head2;
                head2 = head2->next;
            }
        }
        if (head1 != nullptr) {
            prev2->next = head1;
        }
        if (head2 != nullptr) {
            prev1->next = head2;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            return lists.at(0);
        }
        ListNode *ans = mergeTwoLists(lists.at(0), lists.at(1)); 
        for (int i = 2; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists.at(i));
        }
        return ans;
    }
};