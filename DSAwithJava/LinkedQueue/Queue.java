package LinkedQueue;

public interface Queue<Type>{
    public boolean isEmpty();
    public boolean enqueue(Type item) throws Exception;
    public Type dequeue()throws Exception;
    public Type peek()throws Exception;
    public void Traverse();
    public int length();
}
