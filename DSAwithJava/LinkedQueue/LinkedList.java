package LinkedQueue;

public class LinkedList<Type> implements Queue<Type>{

    protected Node<Type> head;
    protected Node<Type> tail;
    public int count;

    public LinkedList(){
        this.head = null;
        this.tail = null;
        this.count = 0;
    }

    @Override
    public boolean isEmpty(){
        return head == null;
    }


    public boolean InsertTop(Type value){
        Node<Type> newNode = new Node<Type>(value);
        if(isEmpty()){
            head = tail = newNode;
        }else{
            newNode.next = head;
            head = newNode;
        }
        tail.next = head;
        ++count;
        return true;
    }

    public boolean InsertTop(Node<Type> newNode){
        if(isEmpty()){
            head = tail = newNode;
        }else{
            newNode.next = head;
            head = newNode;
        }
        tail.next = head;
        ++count;
        return true;
    }

    @Override
    public boolean enqueue(Type value){
        Node<Type> newNode = new Node<>(value);
        if (isEmpty()){
            head = tail = newNode;
        }else{
            tail.next = newNode;
            tail = newNode;
        }
        tail.next = head;
        ++count;
        return true;
    }


    public boolean enqueue(Node<Type> newNode){
        if (isEmpty()){
            head = tail = newNode;
        }else{
            tail.next = newNode;
            tail = newNode;
        }
        tail.next = head;
        ++count;
        return true;
    }

    public boolean Insert(Type value,int index)throws Exception{
        if(head == null || index < 0){
            throw new Exception("Unmatched index");
        }
        if(index == 0||count == 0){
            return InsertTop(value);
        }
        if(index > count){
            index = index % count;
        }
        Node<Type> temp = head;
        for(int i = 0 ; i < index - 1 ;++i){
            temp = temp.next;
        }
        if(temp.next==head){
            return enqueue(value);
        }
        Node<Type> newNode = new Node<>(value);
        newNode.next = temp.next;
        temp.next = newNode;
        ++count;
        return true;
    }

    public boolean Insert(Node<Type> newNode,int index)throws Exception{
        if(head == null || index < 0){
            throw new Exception("Unmatched index");
        }
        if(index == 0||count == 0){
            return InsertTop(newNode);
        }
        if(index > count){
            index = index % count;
        }
        Node<Type> temp = head;
        for(int i = 0 ; i < index - 1 ;++i){
            temp = temp.next;
        }
        if(temp.next==head) {
            return enqueue(newNode);
        }
        newNode.next = temp.next;
        temp.next = newNode;
        ++count;
        return true;
    }


    @Override
    public Type dequeue() throws Exception{
        if(isEmpty()){
            throw new NullPointerException("Is Empty");
        }
        Node<Type> temp = head;
        if(head.next == head){
            head = tail = null;
        }else{
            head = head.next;
            tail.next = head;
        }
        --count;
        return temp.val;
    }


    public Type RemoveEnd() throws Exception{
        if(isEmpty()){
            throw new NullPointerException("Is Empty");
        }
        Node<Type> temp =tail;
        if(head.next==head){
            head=tail=null;
        }else{
            Node<Type> temp2 = head;
                while(temp2.next != tail){
                    temp2 = temp2.next;
                }
            tail = temp2;
            temp2.next = head;
        }
        --count;
        return temp.val;
    }


    public Type Remove(int index) throws Exception {
        if (isEmpty() || index < 0) {
            throw new NullPointerException("Error");
        }
        if (index >= count && count != 0) {
            index = index % count;
        }
        if (index == 0) {
            return dequeue();
        }
        Node<Type> temp = head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp.next;
        }
        if (temp.next == tail) {
            return RemoveEnd();
        }
        Node<Type> toDelete = temp.next;
        temp.next = toDelete.next;
        --count;
        return toDelete.val;
    }

    public Boolean Search(Type object){
        if(isEmpty()){
            return false;
        }
        Node<Type> temp = head;
        do{
            if(temp.val==object){
                return true;
            }
            temp = temp.next;
        }while(temp!=head);
        return false;
    }


    @Override
    public Type peek() throws Exception{
        if(head==null){
            throw new NullPointerException("Is Empty cannot Peek");
        }
        return head.val;
    }

    @Override
    public void Traverse(){
        if(!isEmpty()){
            Node<Type> temp = head;
            do{
                System.out.println(temp.val);
                temp = temp.next;
            }while(temp!=head);
        }
    }

    @Override
    public int length(){
        return this.count;
    }
}

