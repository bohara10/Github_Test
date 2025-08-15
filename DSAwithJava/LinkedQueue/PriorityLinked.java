package LinkedQueue;

public class PriorityLinked<Type extends Number> extends LinkedList<Type> implements Queue<Type>{

    @Override
    public boolean enqueue(Type object) {
        Node<Type> newNode = new Node<>(object);
        if (super.isEmpty()) {
            super.head = newNode;
            return true;
        }
        double newValue = object.doubleValue();
        if (newValue <=super.head.val.doubleValue()) {
            return super.InsertTop(object);
        }
        Node<Type> temp =super.head;
        while (temp.next != null && newValue>temp.next.val.doubleValue()) {
            temp = temp.next;
        }
        newNode.next =temp.next;
        temp.next= newNode;
        return true;
    }

}
