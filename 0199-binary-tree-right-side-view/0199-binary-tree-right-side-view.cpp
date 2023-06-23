
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        
        if(root) q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                if(i == size - 1){
                    ans.push_back(node->val);
                }
            }
        }
        
        return ans;
    }
};