package LinkedStack;


public class ListNode<T>{
    public T val;
    public ListNode<T> next;

    public ListNode(){}

    public ListNode(T data){
        this.val = data;
        this.next = null;
    }
}