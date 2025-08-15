package LinkList;

public interface List <T>{
    public boolean isEmpty();
    public boolean insert(T value);
    public boolean insert(T value, int index);
    public T remove()throws Exception;
    public T remove(int index)throws Exception;
    public T get(int index)throws Exception;
    public void reverse();
    public void Traverse();
}
