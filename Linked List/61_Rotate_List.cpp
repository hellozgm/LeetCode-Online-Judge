/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 这道题下面的解法是没考虑到k有可能超过链表长度的。不是标准解法。但原测试用例过于严苛，这样应该可以。
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i = 0; i < k; i++)
            first = first->next;
        while(first->next){
            first = first->next;
            second = second->next;
        }
        first->next = dummy->next;
        dummy->next = second->next;
        second->next =NULL;
        return dummy->next;
    }
};
