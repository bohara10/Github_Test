package LinkList;

public class LinkedList<T>implements List<T>{

    public ListNode<T> head;
    public int count;

    public LinkedList(){
        this.head = null;
        this.count = 0;
    }

    @Override
    public boolean isEmpty(){
        return head == null;
    }

    public boolean insertTop(T value){
        ListNode<T> Node = new ListNode<T>(value);
        if(head != null){
            head.prev = Node;
            Node.next = head;
        }
        head = Node;
        ++count;
        return true;
    }

    public boolean insertTop(ListNode<T> Node){
        if(head != null){
            head.prev = Node;
            Node.next = head;
        }
        head = Node;
        ++count;
        return true;
    }

    @Override
    public boolean insert(T value){
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
        Node.prev = temp;
        ++count;
        return true;
    }

    public boolean insert(ListNode<T> Node){
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
        Node.prev = temp;
        ++count;
        return true;
    }

    @Override
    public boolean insert(T value,int index){
        if(head == null || index < 0){
            return false;
        }
        if(index == 0||count == 0){
            return insertTop(value);
        }
        if(index > count+1){
            return false;

        }
        ListNode<T> temp = head;
        for(int i = 0 ; i < index - 1 ;++i){
            temp = temp.next;
        }
        if(temp.next==null){
            return insert(value);
        }
        ListNode<T> newNode = new ListNode<>(value);
        newNode.next = temp.next;
        temp.next.prev = newNode;
        newNode.prev = temp;
        temp.next = newNode;
        ++count;
        return true;
    }

    public boolean insert(ListNode<T> newNode,int index)throws Exception{
        if(head == null || index < 0){
            throw new Exception();
        }
        if(index == 0||count == 0){
            return insertTop(newNode);
        }
        if(index > count+1) {
            throw new Exception("Out of bounds");
        }
        ListNode<T> temp = head;
        for(int i = 0 ; i < index - 1 ;++i){
            temp = temp.next;
        }
        if(temp.next == null){
            return insert(newNode);
        }
        newNode.next = temp.next;
        temp.next.prev = newNode;
        newNode.prev = temp;
        temp.next = newNode;
        ++count;
        return true;
    }


    public T removeTop() throws Exception{
        if(head == null){
            throw new NullPointerException();
        }
        ListNode<T> temp = head;
        head = head.next;
        if (head != null) {
            head.prev = null;
        }
        --count;
        return temp.val;
    }

    @Override
    public T remove() throws Exception{
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
        T valX = temp.next.val;
        temp.next=null;
        --count;
        return valX;
    }

    @Override
    public T remove(int index) throws Exception{
        if(head == null ||index < 0||index >= count){
            throw new NullPointerException();
        }
        if(index == 0){
            return this.removeTop();
        }
        ListNode<T> temp = head;
        for(int i = 0 ; i < index - 1 ;++i){
            temp = temp.next;
        }
        ListNode<T> Delete = temp.next;
        if(Delete.next == null){
            temp.next = null;
            --count;
            return Delete.val;
        }
        temp.next = Delete.next;
        Delete.next.prev = temp;
        --count;
        return Delete.val;
    }

    public Boolean Search(T object){
        ListNode<T> temp = head;
        while(temp!=null){
            if(temp.val.equals(object)){
                return true;
            }
            temp = temp.next;
        }
        return false;
    }



    public T peek() throws Exception{
        if(head==null){
            throw new NullPointerException();
        }
        return head.val;
    }

    public int length(){
        return this.count;
    }


    @Override
    public void Traverse(){
        if(head!=null){
            ListNode<T> temp = head;
            while(temp!=null){
                System.out.println(temp.val);
                temp = temp.next;
            }
        }
    }

    @Override
    public T get(int index) throws Exception{
        if(index < 0 || index >= count) {
            throw new Exception("Index out of bounds");
        }
        if(index == 0) {
            return head.val;
        }
        ListNode<T> temp = head;
        for(int i = 0; i < index; ++i) {
            temp = temp.next;
        }
        return temp.val;
    }

    @Override
    public void reverse() {
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
        this.head = prev;
    }
}

