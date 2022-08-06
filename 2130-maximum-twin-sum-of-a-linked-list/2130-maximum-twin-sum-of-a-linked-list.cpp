class Solution {
public:
    int pairSum(ListNode *head) {
        vector<int> vec;
        ListNode *temp = head;
        while (temp != nullptr){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int ans = INT_MIN;
        for (int i = 0; i < vec.size()/2; ++i) {
            ans = max(ans, vec.at(i) + vec.at(vec.size() - 1 - i));
        }

        return ans;

    }
};