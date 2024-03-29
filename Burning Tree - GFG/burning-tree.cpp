//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void getParents(Node *root, unordered_map<Node*, Node*> &parent_track){
        queue<Node *> q;
        q.push(root);
        
        
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                parent_track[node->left] = node;
            } 
            
            if(node->right) {
                q.push(node->right);    
                parent_track[node->right] = node;
            }
        }
    }
  
    int minTime(Node* root, int target) 
    {
        // finding parent first
        queue<Node *> q;
        q.push(root);
        
        Node *targetNode;
        
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            
            if(node->data == target){
                targetNode = node;
                break;
            }
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        // getting parents list
        unordered_map<Node *, Node *> parent_track;
        getParents(root, parent_track);
        
        // doing the bfs traversal to find the answer
        unordered_map<Node *, bool> visited;
        queue<Node *> q2;
        q2.push(targetNode);
        visited[targetNode] = true;
        
        int ans = 0;
        
        while(!q2.empty()){
            
            int size = q2.size();
            bool burnt = false;
            for(int i = 0; i < size; i++){
                Node *node = q2.front();
                q2.pop();
                
                if(node->left && !visited[node->left]){
                    burnt = true;
                    q2.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && !visited[node->right]){
                    burnt = true;
                    q2.push(node->right);
                    visited[node->right] = true;
                }
                
                if(parent_track[node] && !visited[parent_track[node]]){
                    burnt = true;
                    q2.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
            
            if(burnt) ans++;
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends