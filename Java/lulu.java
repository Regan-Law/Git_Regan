import java.util.*;

public class lulu {
    public static void main(String args[]) {
        TreeSet<String> s = new TreeSet<String>(new MyComparatorup());
        TreeSet<String> sr = new TreeSet<String>(new MyComparatordown());
        s.add("HashSet");
        s.add("ArrayList");
        s.add("TreeMap");
        s.add("HashMap");
        s.add("TreeSet");
        s.add("LinkedList");

        sr.add("HashSet");
        sr.add("ArrayList");
        sr.add("TreeMap");
        sr.add("HashMap");
        sr.add("TreeSet");
        sr.add("LinkedList");
        System.out.println("ÉýÐò:");
        Iterator<String> it = s.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
        System.out.println("½µÐò:");
        Iterator<String> itersr = sr.iterator();
        while (itersr.hasNext()) {
            System.out.println(itersr.next());
        }
    }

    static class MyComparatorup implements Comparator<String> {
        public int compare(String o1, String o2) {
            return o1.compareTo(o2);
        }
    }

    static class MyComparatordown implements Comparator<String> {
        public int compare(String o1, String o2) {
            return o2.compareTo(o1);
        }
    }
}