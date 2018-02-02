/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 此道题有两点注意，一将k-merge转化为多个2-merge，第二，2-merge利用了递归排序的方法，第三，2-merge的时候利用首尾merge的方法，
 * 与从第一个第二个逐个merge的方法对比,可以大大加快merge速度，复杂度为kn*logk，n为list平均长度。
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int len = lists.size();
        while(len > 1){
            for(int i = 0; i < len/2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
            len = (len+1)/2;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
