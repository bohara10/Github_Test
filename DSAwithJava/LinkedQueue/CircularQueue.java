package LinkedQueue;

public class CircularQueue<Type> implements Queue<Type> {

    protected int front;
    protected int rear;
    protected int capacity;
    protected Type[] arr;

    public CircularQueue(int capacity) {
        this.capacity = capacity;
        arr = (Type[]) new Object[capacity];
        front = 0;
        rear = 0;
    }

    public CircularQueue() {
        this.capacity = 15;
        arr = (Type[]) new Object[capacity];
        front = 0;
        rear = 0;
    }

    @Override
    public boolean isEmpty() {
        return (rear + 1) % capacity == front;
    }

    public boolean isFull() {
        return (rear + 1) % capacity == front;
    }

    @Override
    public boolean enqueue(Type item) throws Exception {
        if (isFull()) {
            return false;
        }
        arr[rear++] = item;
        rear%= capacity;
        return true;
    }

    @Override
    public Type dequeue() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is empty");
        }
        Type item = arr[front++];
        front %= capacity;
        return item;
    }

    @Override
    public Type peek() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is empty");
        }
        return arr[front];
    }

    @Override
    public void Traverse() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.print("Queue elements: ");
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    @Override
    public int length() {
        if (rear >= front) {
            return rear - front;
        } else {
            return capacity - front + rear;
        }
    }
}