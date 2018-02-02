/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 *这道题没必要开辟新的内存空间，直接复用l1,l2即可，第二种解法是用递归解决。

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* rear = dummyHead;
        while(l1 && l2){
            if(l1->val <= l2->val){
                rear->next = l1;
                l1 = l1->next;
            }
            else{
                rear->next = l2;
                l2 = l2->next;
            }
            rear = rear->next;            
        }
        if(l1)
            rear->next = l1;
        else
            rear->next = l2;
        return dummyHead->next;
    }
};
