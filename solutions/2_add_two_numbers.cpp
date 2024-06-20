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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *res=dummy;
        int carry = 0, sum = 0;
        while(l1 || l2){
            if(l1 && l2){
                sum = l1->val+l2->val+carry;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                sum = l1->val + carry;
                l1=l1->next;
            }
            else{
                sum = l2->val + carry;
                l2 = l2->next;
            }
            carry = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            res->next = newNode;
            res = res->next;
        }
        if(sum/10){
            ListNode *newNode = new ListNode(sum/10);
            res->next = newNode;
        } 
        return dummy->next;  
    }
};
