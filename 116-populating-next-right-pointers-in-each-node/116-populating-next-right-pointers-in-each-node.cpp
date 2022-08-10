class Solution {
public:

    Node* connect(Node* root) {
        if (!root){
            return root;
        }
        queue<Node *> q;
        q.push(root);
        int count = 1;
        int i = 0;
        while (!q.empty()){
            while (count > 0){
                Node * temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                if(count == 1){
                    temp->next = nullptr;
                }
                else{
                    temp->next = q.front();
                }
                count--;
            }
            i++;
            count += pow(2, i);
        }
        return root;
    }
};