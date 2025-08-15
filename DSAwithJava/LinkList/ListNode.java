package LinkList;

public class ListNode<T> {
    public T val;
    public ListNode<T> next;
    public ListNode<T> prev;

    public ListNode(T val){
        this.val = val;
        this.next = null;
        this.prev = null;
    }

    public ListNode(){
        this.val = null;
        this.next = null;
    }
}
