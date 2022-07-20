class Solution {
public:
    int sumOfTilts = 0;
    int getSum(TreeNode* root, int &sum){
        if (root == nullptr){
            return 0;
        }
        getSum(root->left, sum);
        getSum(root->right, sum);
        sum += root->val;
        return sum;
    }

    int findTilt(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        int n1 = getSum(root->left, sum);
        sum = 0;
        int n2 = getSum(root->right, sum);
        cout << n1 << "  " << n2 << endl;
        sumOfTilts += abs(n1 - n2);
        cout<<sumOfTilts<<"  ";
        findTilt(root->left);
        findTilt(root->right);
        return sumOfTilts;
    }
};