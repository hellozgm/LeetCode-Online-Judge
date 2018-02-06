/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// 分别将小于大于x的node链接到两个新建的链表上，最后再把它们拼接起来！
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummyLess = new ListNode(0);
        ListNode dummyGreater = new ListNode(0);
        ListNode less = dummyLess, greater = dummyGreater, current = head;
        while(current != null){
            if(current.val < x){
                less.next = current;
                less = less.next;
            }
            else{
                greater.next = current;
                greater = greater.next;
            }
            current = current.next;
        }
        greater.next = null; //这一步非常重要，否则会出现循环链表的情况！
        less.next = dummyGreater.next;
        return dummyLess.next;
    }
}
