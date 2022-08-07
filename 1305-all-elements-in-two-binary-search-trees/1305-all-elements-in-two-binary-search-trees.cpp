class Solution {
public:
    void helper(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        vector<int> ans;
        helper(root1, a);
        helper(root2, b);
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()){
            if(a.at(i) <= b.at(j)){
                ans.push_back(a.at(i));
                i++;
            }
            else{
                ans.push_back(b.at(j));
                j++;
            }
        }
        while (i < a.size()){
            ans.push_back(a.at(i));
            i++;
        }
        while (j < b.size()){
            ans.push_back(b.at(j));
            j++;
        }
        
        return ans;
    }
};