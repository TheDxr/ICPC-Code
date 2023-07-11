public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode result = new ListNode(0);
        ListNode ret = result;
        ListNode p = l1, q = l2, current = result;
        while (p != null || q != null)
        {
            int x = (p != null ? p.val : 0);
            int y = (q != null ? q.val : 0);
            if(p != null)p = p.next;
            if(q != null)q = q.next;
            int sum = current.val + x + y;
            if(p != null || q != null || sum/10 != 0)
                current.next = new ListNode(sum/10);
            current.val = sum % 10;
            current = current.next;

        }
        return result;
    }
}