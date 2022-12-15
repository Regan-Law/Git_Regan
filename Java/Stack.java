import java.util.ArrayList;

class MyStack {

    ArrayList<Object> arrayList;

    public MyStack() {
        arrayList = new ArrayList<Object>();
    }

    public void pushStack(Object x) {
        System.out.println("ѹ��\t" + x);
        arrayList.add(x);
    }

    public void popStack() {
        if (arrayList.size() == 0) {
            System.out.println("ջΪ�գ������ݵ���");
        } else {
            System.out.println("����\t" + arrayList.get(arrayList.size() - 1));
            arrayList.remove(arrayList.size() - 1);
        }
    }

    public void toStringStack() {
        System.out.println("��ջԪ�أ�");
        for (Object i : arrayList) {
            System.out.println("\t" + i);
        }
    }

}

public class Stack {

    public static void main(String[] args) {
        MyStack stack = new MyStack();
        stack.pushStack(1);
        stack.pushStack("t");
        stack.pushStack("2");
        stack.toStringStack();
        stack.popStack();
        stack.popStack();
        stack.popStack();
        stack.popStack();
    }

}