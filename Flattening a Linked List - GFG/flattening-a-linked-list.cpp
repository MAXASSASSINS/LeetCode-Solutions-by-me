//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node *l1, Node *l2){
    Node *dummy = new Node(INT_MIN);
    Node *head = dummy;
    
    while(l1 && l2){
        if(l1->data <= l2->data){
            dummy->bottom = l1;
            dummy = l1;
            l1 = l1->bottom;
        }
        else{
            dummy->bottom = l2;
            dummy = l2;
            l2 = l2->bottom;
        }
    }
    while(l1){
        dummy->bottom = l1;
        dummy = l1;
        l1 = l1->bottom;
    }
    while(l2){
        dummy->bottom = l2;
        dummy = l2;
        l2 = l2->bottom;
    }
    
    head->bottom->next = nullptr;
    
    return head->bottom;
}

Node* solve(Node *root){
    if(!root->next) return root;
    Node *l2 = solve(root->next);
    Node *l1 = root;
    Node *l3 = merge(l1, l2);
    return l3;
}    

Node *flatten(Node *root)
{
   return solve(root);
}

