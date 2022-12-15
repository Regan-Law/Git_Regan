import java.util.ArrayList;
import java.util.Iterator;

class MyQueue {
    ArrayList<Object> data;

    public MyQueue() {
        data = new ArrayList<Object>();
    }

    public void in(Object o) {
    
		System.out.println("���\t"+o);
        data.add(o);
    }

    public Object out() {
        if (data.size() > 0) {
            
			System.out.print(" "+data.get(0));
            return data.remove(0);
        }
            
        else
            return null;
    }

    public int getSize() {
        return data.size();
    }

    public void toStringQueue() {
        System.out.println("�������Ԫ��Ϊ��");
        Iterator<Object> it = data.iterator();
        while (it.hasNext()) {
            Object object = it.next();
            System.out.print(" " + object);
        }
        System.out.println();
    }
}

class MyQueueTest {
    public void test() {
        MyQueue Queue = new MyQueue();
        Queue.in(1);
        Queue.in(2);
        Queue.in(3);
        Queue.toStringQueue();
        System.out.println("���Ӳ�����");
        Queue.out();
        Queue.out();
        Queue.out();
        Queue.out();
    }
}
public class Queue {
    public static void main(String[] args) {
        MyQueueTest test=new MyQueueTest();
        test.test();
    }
}