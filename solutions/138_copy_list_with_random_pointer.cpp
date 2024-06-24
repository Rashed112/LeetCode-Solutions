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
        unordered_map<Node*, Node*>m;
        //m[NULL]=NULL;
        Node* curr = head;
        while(curr){
            Node *copy = new Node(curr->val);
            m[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            Node *copy = m[curr];
            copy->next = m[curr->next];
            copy->random = m[curr->random];
            //m[curr] = copy;
            curr = curr->next;
        }
        return m[head];
    }
};
