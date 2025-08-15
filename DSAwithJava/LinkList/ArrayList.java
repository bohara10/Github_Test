package LinkList;

public class ArrayList<T> implements List<T>{
    private T[] arr;
    public int count;
    private int capacity;

    public ArrayList(){
        this.capacity = 10;
        this.arr = (T[]) new Object[this.capacity];
        this.count = 0;
    }

    public ArrayList(int capacity){
        this.capacity = capacity;
        arr = (T[]) new Object[capacity];
        count = 0;
    }

    @Override
    public boolean isEmpty(){
        return count == 0;
    }

    @Override
    public boolean insert(T value){
        if(count+1 == this.capacity) return false;
        arr[count++] = value;
        return true;
    }

    @Override
    public boolean insert(T value,int index){
        if(index < 0 || index > this.count) return false;
        if(count+1 == this.capacity)return false;
        if(index == count) return insert(value);
        ++count;
        for(int i = this.count; i > index; i--){
            arr[i]=arr[i-1];
        }
        arr[index]=value;
        return true;
    }

    @Override
    public T remove()throws Exception{
        if(isEmpty()) throw new Exception("List is empty");
        return arr[count--];
    }

    @Override
    public T remove(int index) throws Exception{
        if(index < 0 || index >= this.capacity) throw new IndexOutOfBoundsException("Index out of bounds");
        T item = arr[index];
        for(int i = index; i < this.count; i++){
            arr[i]=arr[i+1];
        }
        --count;
        return item;
    }

    @Override
    public T get(int index) throws Exception {
        if(isEmpty()||index<0||index>=count) throw new Exception("Error.The index does not exist");
        return arr[index];
    }

    @Override
    public void reverse() {
        int left = 0;
        int right = this.count - 1;

        while (left < right) {
            T temp = this.arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    @Override
    public void Traverse(){
        if(!isEmpty()){
            for(int i = 0 ; i < count; i++){
                System.out.print(arr[i]+" ");
            }
        }
    }
}
