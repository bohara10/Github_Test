package LinkList;

public class Test {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.insertTop(5);
        list.insertTop(5);
        list.insertTop(5);
        list.insertTop(5);
        list.insertTop(4);
        list.insertTop(4);
        list.insertTop(3);
        list.insertTop(3);
        list.insertTop(3);
        list.insertTop(2);
        list.insertTop(1);
        list.insertTop(0);
        list.insertTop(0);
        list.Traverse();
        LinkedListTests.removeDuplicates(list.head);
        System.out.println();
        list.Traverse();
    }
}
