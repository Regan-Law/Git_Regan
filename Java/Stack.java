import java.util.ArrayList;

class MyStack {

    ArrayList<Object> arrayList;

    public MyStack() {
        arrayList = new ArrayList<Object>();
    }

    public void pushStack(Object x) {
        System.out.println("压入\t" + x);
        arrayList.add(x);
    }

    public void popStack() {
        if (arrayList.size() == 0) {
            System.out.println("栈为空，无数据弹出");
        } else {
            System.out.println("弹出\t" + arrayList.get(arrayList.size() - 1));
            arrayList.remove(arrayList.size() - 1);
        }
    }

    public void toStringStack() {
        System.out.println("堆栈元素：");
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