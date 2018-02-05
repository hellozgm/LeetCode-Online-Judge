/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 此题要注意，dummyHead的使用，最后返回的是dummy->next 而不是head
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* phead = dummy;
        while(phead->next && phead->next->next){
            ListNode* first = phead->next;
            ListNode* second = first->next;
            phead->next = second;
            first->next = second->next;
            second->next = first;
            phead = second->next;
        }
        return dummy->next;
    }
};
