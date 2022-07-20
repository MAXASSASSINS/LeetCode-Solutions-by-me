class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        vector<vector<int>> levels;
        queue<TreeNode *> q;
        q.push(root);
        int queueSize = 1;
        int nextQueueSize = 2;
        while (!q.empty()){
            double average = 0;
            for (int i = 0; i < queueSize; ++i) {
                TreeNode *temp = q.front();
                average += (double)temp->val;
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                else{
                    nextQueueSize--;
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
                else{
                    nextQueueSize--;
                }
                q.pop();
            }
            averages.push_back(average / queueSize);
            queueSize = nextQueueSize;
            nextQueueSize = queueSize * 2;
        }
        return averages;
    }
};