
class Solution {
public:
    int count=0;
pair<int,int> valueSum(TreeNode* root){
	if(root==NULL) return {0,0};
	auto left=valueSum(root->left);
	auto right=valueSum(root->right);
	int sum=(left.first+right.first+root->val);
	int n=(left.second+right.second+1);        
	count+=((sum/n)==root->val);
	return {sum,n};
}
int averageOfSubtree(TreeNode* root) {
	auto p1=valueSum(root);
	return count;
}

};