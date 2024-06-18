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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = head;
        // to check if is there any group of k
        for(int i=0;i<k;i++){
            if(dummy == NULL){
                return head;
            }
            dummy = dummy->next;
        }
        ListNode *prev = NULL, *curr=head, *nxt=NULL;
        int count = 0;
        while(count<k && curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        // making joins with those k groups
        head->next = reverseKGroup(nxt, k);
    
        return prev;
    }
};

// Time : O(n)
// Space : O(n)
