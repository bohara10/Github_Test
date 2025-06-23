package LinkedStack;

public interface Stack<T> {
    public boolean push(T object);
    public T pop()throws Exception;
    public void Traverse();
    public boolean isEmpty();
    public T peek() throws Exception;
    public int length();
}
