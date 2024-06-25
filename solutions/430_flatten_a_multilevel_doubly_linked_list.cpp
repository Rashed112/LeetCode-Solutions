/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*>st;
        Node *curr = head;
        while(curr){
            if(curr->child){
                if(curr->next){
                    st.push(curr->next);
                    curr->next->prev = NULL;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            if(curr->next){
                curr = curr->next;
            }
            else{
                break;
            }
        }
        while(!st.empty()){
            curr->next = st.top();
            st.pop();
            curr->next->prev = curr;
            while(curr->next){
                curr = curr->next;
            }
        }
        return head;
    }
};
