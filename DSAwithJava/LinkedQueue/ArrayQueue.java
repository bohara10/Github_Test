package LinkedQueue;

public class ArrayQueue<K> implements Queue<K> {

    private K[] arr;
    private int front;
    private int rear;
    public int count;
    private int capacity;

    public ArrayQueue() {
        this.capacity = 15;
        this.arr = (K[])new Object[capacity];
        this.front = 0;
        this.rear = -1;
        this.count = 0;
    }

    public ArrayQueue(int capacity) {
        this.capacity = capacity;
        this.arr = (K[])new Object[capacity];
        this.front = 0;
        this.rear = -1;
        this.count = 0;
    }

    @Override
    public boolean isEmpty() {
        return rear<front;
    }

    public boolean isFull() {
        return rear+1 == capacity;
    }

    @Override
    public boolean enqueue(K item) {
        arr[++rear]=item;
        count++;
        return true;
    }

    @Override
    public K dequeue() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is empty");
        }
        count--;
        return arr[front++];
    }

    @Override
    public K peek() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is empty");
        }
        return arr[front];
    }

    @Override
    public int length(){
        return this.count;
    }

    @Override
    public void Traverse() {
        for(int i=front;i<=rear;i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
