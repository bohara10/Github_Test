package LinkedStack;

public class LinkedList<T> implements Stack<T>{

    private ListNode<T> head;
    public int count;

    public LinkedList(){
        this.head = null;
        this.count = 0;
    }

    @Override
    public boolean isEmpty(){
        return head == null;
    }

    @Override
    public boolean push(T value){
        ListNode<T> Node = new ListNode<T>(value);
        if(head != null){
            Node.next = head;
        }
        head = Node;
        ++count;
        return true;
    }


    public boolean push(ListNode<T> Node){
        if(head != null){
            Node.next = head;
        }
        head = Node;
        ++count;
        return true;
    }

    public boolean InsertEnd(T value){
        ListNode<T> Node = new ListNode<T>(value);
        if (head == null){
            head = Node;
            ++count;
            return true;
        }
        ListNode<T> temp = head;
        while(temp.next!=null){
            temp = temp.next;
        }
        temp.next = Node;
        ++count;
        return true;
    }

    public boolean InsertEnd(ListNode<T> Node){
        if (head == null){
            head = Node;
            ++count;
            return true;
        }
        ListNode<T> temp = head;
        while(temp.next!=null){
            temp = temp.next;
        }
        temp.next = Node;
        ++count;
        return true;
    }

    public boolean Insert(T value,int index)throws Exception{
        if(head == null || index < 0){
            throw new Exception();
        }
        if(index == 0||count == 0){
            return push(value);
        }
        if(index > count){
            throw new Exception("Out of bounds");
        }
            ListNode<T> temp = head;
            for(int i = 0 ; i < index - 1 ;++i){
                temp = temp.next;
            }
            ListNode<T> newNode = new ListNode<>(value);
            newNode.next = temp.next;
            temp.next = newNode;
            ++count;
            return true;
    }

    public boolean Insert(ListNode<T> newNode,int index)throws Exception{
        if(head == null || index < 0){
            throw new Exception();
        }
        if(index == 0||count == 0){
            return push(newNode);
        }
        if(index > count){
            throw new Exception("Out of bounds");
        }
        ListNode<T> temp = head;
        for(int i = 0 ; i < index - 1 ;++i){
            temp = temp.next;
        }
        newNode.next = temp.next;
        temp.next = newNode;
        ++count;
        return true;
    }


    @Override
    public T pop() throws Exception{
        if(head==null){
            throw new NullPointerException();
        }
        ListNode<T> temp = head;
        head = head.next;
        --count;
        return temp.val;
    }

    public T deleteEnd() throws Exception{
        if(head == null){
            throw new NullPointerException();
        }
        if(head.next==null){
            T x = head.val;
            head=null;
            return x;
        }
        ListNode<T> temp = head;
        while(temp.next.next!=null){
            temp=temp.next;
        }
        T retval = temp.next.val;
        temp.next=null;
        --count;
        return retval;
    }

    public T Remove(int index) throws Exception{

        if(head == null || index < 0){
            throw new NullPointerException();
        }
        if(index>count||count!=0){
            throw new Exception("Out of bounds");
        }
        if(index == 0){
            return pop();
        }
        ListNode<T> temp = head;
        for(int i = 0 ; i < index ;++i){
            temp = temp.next;
        }
        if(temp.next==null){
            return deleteEnd();
        }
        ListNode<T> newNode = temp;
        temp.next = temp.next.next;
        --count;
        return newNode.val;
    }

    public Boolean Search(T object){
        ListNode<T> temp = head;
        while(temp!=null){
            if(temp.val==object){
                return true;
            }
            temp = temp.next;
        }
        return false;
    }


    @Override
    public T peek() throws Exception{
        if(head==null){
            throw new NullPointerException();
        }
        return head.val;
    }

    @Override
    public int length(){
        return this.count;
    }

    @Override
    public void Traverse() {
        if (head != null) {
            ListNode<T> temp = head;
            while (temp != null) {
                System.out.print(temp.val+" ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public void reverseList() {
        if (head == null || head.next == null) return;

        ListNode<T> prev = null;
        ListNode<T> current = head;
        ListNode<T> next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
            }
            head = prev;
    }
}
