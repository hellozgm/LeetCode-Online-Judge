/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * The most import is to insert a dummyHead at the begining.
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p=dummyHead;
        int out=0;
        while(l1 != NULL && l2 != NULL){
            p->next=new ListNode(0);
            p =p->next;
            p->val = (l1->val + l2->val + out)%10;
            out = (l1->val + l2->val + out)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 != NULL){
            p->next=new ListNode(0);
            p =p->next;
            p->val = (l1->val + out)%10;
            out = (l1->val + out)/10;
            l1=l1->next;            
        }
        while(l2 != NULL){
            p->next=new ListNode(0);
            p =p->next;
            p->val = (l2->val + out)%10;
            out = (l2->val + out)/10;
            l2=l2->next;            
        }
        if(out != 0)
            p->next=new ListNode(out);
        return dummyHead->next;
    }
};
