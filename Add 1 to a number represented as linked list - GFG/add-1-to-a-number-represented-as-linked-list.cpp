//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    void reverse(Node* &head){
        Node *curr = head;
        Node *prev = nullptr;
        while(curr != nullptr){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        reverse(head);
        int carry = 1;
        Node *temp = head;
        while(temp){
            int val = temp->data + carry;
            if(val >= 10) carry = 1;
            else carry = 0;
            temp->data = val % 10;
            temp = temp->next;
        }
        
        if(carry){
            Node *newNode = new Node(1);
            temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        reverse(head);
        
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends