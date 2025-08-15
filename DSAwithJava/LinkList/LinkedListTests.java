package LinkList;

public class LinkedListTests {
    public static ListNode<Integer> removeDuplicates(ListNode<Integer> head){
        if(head==null||head.next==null) return head;
        ListNode<Integer> temp = head;
        ListNode<Integer> tempNext = head.next;

        while(tempNext!=null){
            if(temp.val.equals(tempNext.val)){
                tempNext = tempNext.next;
                temp.next = tempNext;
            }else{
                temp = tempNext;
                tempNext = tempNext.next;
            }
        }
        return head;
    }
}
