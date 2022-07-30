class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        int count = 1;
        int nextCount = count * 2;
        while (!q.empty()){
            vector<int> vec;
            for (int i = 0; i < count; ++i) {
                TreeNode *temp  = q.front();
                vec.push_back(temp->val);
                q.pop();
                if(temp->left == nullptr){
                    nextCount--;
                }
                else{
                    q.push(temp->left);
                }
                if (temp->right == nullptr){
                    nextCount--;
                }
                else{
                    q.push(temp->right);
                }
            }
            count = nextCount;
            nextCount = count * 2;
            ans.push_back(vec);
        }
        return ans;
    }
};