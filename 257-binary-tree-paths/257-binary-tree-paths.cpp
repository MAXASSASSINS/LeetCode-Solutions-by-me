class Solution {
public:
    string getString(int n){
        string temp;
        bool negative = false;
        if (n < 0){
            negative = true;
            n *= -1;
        }
        while(n != 0){
            temp += char(n % 10 + 48);
            n /= 10;
        }
        if (negative)
            temp += "-";
        reverse(temp.begin(), temp.end());
        return temp;
    }

    void helper(TreeNode *root, string s, vector<string> &ans) {
        if (root == nullptr){
            return;
        }
        if (root->left == nullptr && root->right == nullptr){
            s += getString(root->val);
//            s = s.substr(0, s.length() - 2);
            ans.push_back(s);
            return;
        }
        s += getString(root->val);
        s += "->";
        helper(root->left, s, ans);
        helper(root->right, s, ans);
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};