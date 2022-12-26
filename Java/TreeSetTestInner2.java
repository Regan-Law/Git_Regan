import java.util.*;

public class TreeSetTestInner2{
    public static void main(String[] args) {
        TreeSet<String>s=new TreeSet<String>(new Comparator<String>() {
            public int compare(String o1,String o2) {
                return o1.compareTo(o2);
            }
        });
        TreeSet<String>sr=new TreeSet<String>(new Comparator<String>() {
            public int compare(String o1,String o2) {
                return o2.compareTo(o1);
            }
        });
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
        System.out.println("升序:");
        Iterator<String>it=s.iterator();
        while(it.hasNext()) {
            System.out.println(it.next());
        } 
        Iterator<String>itersr=sr.iterator();
        System.out.println("降序:");
        while(itersr.hasNext()) {
            System.out.println(itersr.next());
        }
    }
}