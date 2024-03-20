/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode curr = list1;
        ListNode prev=null;
        while(a-->0)
        {
            prev=curr;
            curr=curr.next;
            b--;
        }
        if(prev!=null)
        prev.next=list2;
       else
        list1=list2; 

        while(list2.next!=null)
        {
            list2=list2.next;
        }

        while(b-->0)
        {
            curr=curr.next;
        }

        list2.next=curr.next;
        curr.next=null;
        return list1;
    }
}