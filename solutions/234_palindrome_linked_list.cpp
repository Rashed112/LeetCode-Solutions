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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }

        // get the middle node
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *middle = slow;
        
        // reverse the 2nd part of the list
        ListNode *curr = middle->next, *prev=NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // compare
        ListNode *head1 = head, *head2 = prev;
        while(head2){
            if(head2->val != head1->val){
                return false;
            }
            head2 = head2->next;
            head1 = head1->next;
        }
        return true;

    }
};
