//Solutoin-1: Brute Force
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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode *curr = head;
        if(head->next == NULL){
            return head;
        }
        while(curr != NULL){
            curr = curr->next;
            cnt++;
        }
        curr = head;
        cnt = cnt/2;
        while(cnt--){
            curr = curr->next;
        }
        return curr;
    }
};

//Solution-2: Using Slow and Fast pointers
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
    ListNode* middleNode(ListNode* head) {
        /*slow go 1 step while fast go 2 step. As a result, when fast arrives at the end, slow will arrive right in the middle*/
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
