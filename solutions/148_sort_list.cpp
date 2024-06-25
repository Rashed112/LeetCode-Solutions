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
    ListNode* getMid(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while(left && right){
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if(left){
            tail->next = left;
        }
        if(right){
            tail->next = right;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        // break linked list into halves    
        ListNode *mid = getMid(head);

        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        // recursive calls to sort both halves
        left = sortList(left);
        right = sortList(right);

        // merge both left and right halves
        return merge(left, right);
    }
};

// Time : O(nlogn)
// Space: O(logn)
