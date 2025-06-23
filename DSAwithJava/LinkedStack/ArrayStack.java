package LinkedStack;

public class ArrayStack<T> implements Stack<T> {

    private T[] array;
    public int count;

    public ArrayStack() {
        this.count = 0;
        this.array = (T[]) new Object[10];
    }

    public ArrayStack(int capacity) {
        this.count = 0;
        this.array = (T[]) new Object[capacity];
    }

    @Override
    public boolean isEmpty() {
        return count == 0;
    }

    @Override
    public int length(){
        return this.count;
    }


    @Override
    public boolean push(T object){
        array[count++] = object;
        return true;
    }

    @Override
    public T pop() throws Exception {
        return array[--count];
    }

    public T peek() throws Exception {
        return array[count-1];
    }

    @Override
    public void Traverse() {
        for (int i = 0; i < count; i++) {
            System.out.println(array[i]);
        }
    }


}
