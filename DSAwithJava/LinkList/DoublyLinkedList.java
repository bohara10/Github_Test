package LinkList;

public class DoublyLinkedList<T> implements List<T> {

    private ListNode<T> head;
    private ListNode<T> tail;
    public int count;

    public DoublyLinkedList(){
        this.head = null;
        this.tail = null;
        this.count = 0;
    }

    @Override
    public boolean isEmpty(){
        return head == null;
    }

    public boolean insertTop(T value){
        ListNode<T> newNode = new ListNode<T>(value);
        if(isEmpty()){
            head = tail = newNode;
            head.next = tail;
            head.prev = tail;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        tail.next = head;
        head.prev = tail;
        ++count;
        return true;
    }

    public boolean insertTop(ListNode<T> newNode){
        if(isEmpty()){
            head = tail = newNode;
            head.next = tail;
            head.prev = tail;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        tail.next = head;
        head.prev = tail;
        ++count;
        return true;
    }

    @Override
    public boolean insert(T value){
        ListNode<T> newNode = new ListNode<T>(value);
        if(isEmpty()){
            head = tail = newNode;
            head.next = tail;
            head.prev = tail;
        } else {
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        head.prev = tail;
        tail.next = head;
        ++count;
        return true;
    }


    public boolean insert(ListNode<T> newNode){
        if(isEmpty()){
            head = tail = newNode;
            head.next = tail;
            head.prev = tail;
        } else {
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        head.prev = tail;
        tail.next = head;
        ++count;
        return true;
    }

    @Override
    public boolean insert(T value, int index){
        if(index < 0 || index > count) {
            return false;
        }
        if(index == 0) {
            return insertTop(value);
        } else if(index == count) {
            return insert(value);
        }

        ListNode<T> temp = head;
        for(int i = 0; i < index - 1; ++i){
            temp = temp.next;
        }
        ListNode<T> newNode = new ListNode<>(value);
        newNode.next = temp.next;
        newNode.prev = temp;
        temp.next.prev = newNode;
        temp.next = newNode;
        ++count;
        return true;
    }


    public boolean insert(ListNode<T> newNode, int index) throws Exception {
        if(index < 0 || index > count) {
            throw new Exception("Index out of bounds");
        }
        if(index == 0) {
            return insertTop(newNode);
        } else if(index == count) {
            return insert(newNode);
        }

        ListNode<T> temp = head;
        for(int i = 0; i < index - 1; ++i){
            temp = temp.next;
        }
        newNode.next = temp.next;
        newNode.prev = temp;
        temp.next.prev = newNode;
        temp.next = newNode;
        ++count;
        return true;
    }

    public T removeTop() throws Exception {
        if(isEmpty()) {
            throw new NullPointerException("List is empty");
        }
        ListNode<T> temp = head;
        if(head == tail) {
            head = tail = null;
        } else {
            head = head.next;
            head.prev = tail;
            tail.next = head;
        }
        --count;
        return temp.val;
    }

    @Override
    public T remove() throws Exception {
        if(isEmpty()) {
            throw new NullPointerException("List is empty");
        }
        ListNode<T> temp = tail;
        if(head == tail) {
            head = tail = null;
        } else {
            tail = tail.prev;
            tail.next = head;
            head.prev = tail;
        }
        --count;
        return temp.val;
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
    public T remove(int index) throws Exception {
        if(index < 0 || index >= count) {
            throw new Exception("Index out of bounds");
        }
        if(index == 0) {
            return removeTop();
        }
        if(index == count - 1) {
            return remove();
        }

        ListNode<T> temp = head;
        for(int i = 0; i < index; ++i) {
            temp = temp.next;
        }
        temp.prev.next = temp.next;
        temp.next.prev = temp.prev;
        --count;
        return temp.val;
    }

    public Boolean Search(T object) {
        ListNode<T> temp = head;
        if(isEmpty()) return false;
        do {
            if(temp.val.equals(object)) {
                return true;
            }
            temp = temp.next;
        } while(temp != head);
        return false;
    }

    @Override
    public void Traverse() {
        if(!isEmpty()) {
            ListNode<T> temp = head;
            do {
                System.out.print(temp.val + " ");
                temp = temp.next;
            } while(temp != head);
            System.out.println();
        }
    }

    public void TraverseReverse() {
        if(!isEmpty()) {
            ListNode<T> temp = tail;
            do {
                System.out.print(temp.val + " ");
                temp = temp.prev;
            } while(temp != tail);
            System.out.println();
        }
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