/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**方法一： 这道题关键点有两个：1，要在head前面插入一个新的头结点dummyHead，目的是为了删除倒数第n个节点（此时链表长度为n）时候，也就是删除头节点的时候，
  * 避免出现头节点删除出错的情况。2，要设置2个快慢不同的指针。 方法二：不在head前面插入一个新的节点，但是要在最后删除节点的时候做一个判断，
  * 判断要删除的节点是否为头节点，其他情况一样。
  */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        ListNode *front = new ListNode(0);
        front->next = head;
        ListNode *p1 = front;
        ListNode *p2 = front;
        for(int i = 1; i <= n+1; i++)
            p1 = p1->next;
        while(p1 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *tmp = p2->next;
        p2->next = p2->next->next;
        delete tmp;
        return front->next;
    }
};
