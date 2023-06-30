class Solution {
public:
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *temp = root;
        
        if(!root) return nullptr;
        if(root->val == key) return helper(root);
        
        while(temp){
            if(temp->val > key){
                if(temp->left && temp->left->val == key){
                    temp->left = helper(temp->left);
                }
                else temp = temp->left;
            }
            else{
                if(temp->right && temp->right->val == key){
                    temp->right = helper(temp->right);
                }
                else temp = temp->right;
            }
        }
        
        return root;      
    }
    
    TreeNode *helper(TreeNode *root){
        if(!root->left){
            return root->right;
        }
        if(!root->right){
            return root->left;
        }
        TreeNode *rightChild = root->right;
        TreeNode *leftMostChild = findLeftMost(rightChild);
        leftMostChild->left = root->left;
        return rightChild;
        
    }
    
    TreeNode *findLeftMost(TreeNode *root){
        if(!root->left){
            return root;
        }
        return findLeftMost(root->left);
    }
};