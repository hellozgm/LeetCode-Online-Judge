/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * 利用快慢指针的原理，让快指针指向重复元素的最后一个，然后对比慢指针的下一个元素是否为快指针，否则认为是发现了重复元素，进行删除操作。
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = head, slow = dummy;
        while(fast != null){
            while(fast.next != null && fast.val == fast.next.val)
                fast = fast.next;
            if(slow.next != fast){
                slow.next = fast.next;
                fast = fast.next;
            }
            else{
                fast = fast.next;
                slow = slow.next;
            }
        }
        return dummy.next;
    }
}
