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
    int numComponents(ListNode* h, vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));
    int res = 0, connected = 0;
    for (; h != nullptr; h = h->next) {
        if (s.count(h->val)) {
            res += !connected;
            connected = true;
        }
        else
            connected = false;
    }
    return res;
}
};