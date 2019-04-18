/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* temp = new ListNode(0);
        ListNode* dummy = temp;

        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }
        
        temp->next = l1?l1:l2;
        return dummy->next;
    }
};
