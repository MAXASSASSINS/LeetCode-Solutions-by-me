/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *itr = head;
        Node *front = head;
        while(itr != NULL){
            front = itr->next;
            Node *copy = new Node(itr->val);
            copy->next = front;
            itr->next = copy;
            itr = front;
        }

        itr = head;
        front = head;
        while(itr != NULL){
            front = itr->next->next;
            if(itr->random != NULL){
                itr->next->random = itr->random->next;
            }
            itr = front;
        }

        itr = head;
        front = head;
        Node *dummy = new Node(-1);
        Node *pseudoHead = dummy;
        while(itr != NULL){
            front = itr->next->next;
            dummy->next = itr->next;
            itr->next = front;
            dummy = dummy->next;
            itr = front;
        }


        return pseudoHead->next;

    }
};