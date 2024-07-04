/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr){
            if(curr->val == 0 && curr->next){
                prev->next = curr->next;
                prev = prev->next;
                curr = curr->next;
            }
            else{
                prev->val += curr->val;
            }
            if(!curr->next){
                prev->next = NULL;
            }
            curr = curr->next;
        }
        return head;
    }
};
