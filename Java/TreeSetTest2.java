import java.util.*;

public class TreeSetTest2 {
    public static void main(String[] args) {
        TreeSet<Integer>cc=new TreeSet<Integer>(new MyComparator());
        for(int i=1;i<=10;i++) {
            cc.add(i);
        }
        for(Integer i:cc)
		{
			System.out.print(i+" ");
		}
    }
}

class MyComparator implements Comparator<Integer>{

    public int compare(Integer o1,Integer o2) {
        if(o1%2==1&&o2%2==0) {
            return-1;
        }
        if(o1%2==0&&o2%2==1) {
            return 1;
        }

        if(o1%2==1&&o2%2==1) {
            return o1-o2;
        }

        if(o1%2==0&&o2%2==0) {
            return o2-o1;
        }
        return 0;
    }
}