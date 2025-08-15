package LinkedQueue;

    public class PriorityQueue<Type extends Number> extends CircularQueue<Type> implements Queue<Type> {
        @Override
        public boolean enqueue(Type t) throws Exception {
            if (super.isFull()) return false;
            if (super.isEmpty()) return super.enqueue(t);

            double newValue = t.doubleValue();

            if (super.arr[super.front].doubleValue() > newValue) {
                if (super.front != 0) {
                    super.front = (super.front - 1 + super.capacity) % super.capacity;
                    super.arr[super.front] = t;
                } else {
                    super.front = super.capacity - 1;
                    super.arr[super.front] = t;
                }
                return true;
            }
            int i = super.front;
            while (i != super.rear && super.arr[i % super.capacity].doubleValue() < newValue) {
                i = (i + 1) % super.capacity;
            }
            if (i == super.rear) {
                super.rear = (super.rear + 1) % super.capacity;
                super.arr[super.rear] = t;
                return true;
            }
            int k = super.rear;
            super.rear = (super.rear + 1) % super.capacity;
            while (k != i) {
                super.arr[(k + 1) % super.capacity] = super.arr[k % super.capacity];
                k = (k - 1 + super.capacity) % super.capacity;
            }
            super.arr[i % super.capacity] = t;
            return true;
        }
    }
