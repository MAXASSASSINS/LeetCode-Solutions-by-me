/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int preInd=0;
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return createTree(preorder,inorder,0,inorder.size() - 1);
}
TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int start, int end){
    if(start > end){
        return NULL;
    }
    TreeNode* node=new TreeNode(preorder[preInd++]);
    int pos;
    for(int i=start;i<=end;i++){
        if(inorder[i]==node->val){
            pos=i;
            break;
        }
    }
    node->left =createTree(preorder, inorder,start,pos-1);
    node->right =createTree(preorder, inorder, pos+1,end);
    return node;
}
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> m){
        
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int inRoot = m[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
        
         root->right = buildTree(preorder, preStart + 1 + numsLeft, preEnd, inorder, inRoot + 1, inEnd, m);
        
        return root;
    }
    
};