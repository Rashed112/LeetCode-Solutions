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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(list1 && list2 ){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1){
            tail->next = list1; 
        }
        if(list2){
            tail->next = list2;
        }
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0){
            return NULL;
        }
        while(n>1){
            for(int i=0;i<n/2;i++){
                lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists.front();
    }
};

// Time: O(n * logk)
// Space: O(n)
