import java.util.Arrays;
import java.util.Scanner;

public class workC1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        array myarray=new array();
        myarray.print();
        myarray.sort();
        System.out.println("请输入需要插入的数：");
        int n=sc.nextInt();
        myarray.insert(n);
        System.out.println("请输入需要删除的数：");
        int d=sc.nextInt();
        myarray.delete(d);
        System.out.println("请输入需要查找的数：");
        int s=sc.nextInt();
        myarray.search(s);
        sc.close();
    }

    public static class array {
        int a[]={ 1,3,5,7,9,4,6,8,2 };
        public void print() {
            System.out.println(Arrays.toString(a));
        }
        public void sort(){
            Arrays.sort(a);
            System.out.println("排序后为"+Arrays.toString(a));
        }
        public void insert(int n){
            int newa[]=new int[a.length+1];
            System.arraycopy(a, 0, newa, 0, a.length);
            newa[a.length]=n;
            Arrays.sort(newa);
            a=newa;
            System.out.println("插入后的数组为");
            System.out.println(Arrays.toString(newa));
        }
        public void delete(int n){
            int newd[]=new int[a.length-1];
            for(int i=0, k=0;i<a.length;i++){
                if(a[i]!=n){
                    newd[k]=a[i];
                    k++;
                }
            }
            Arrays.sort(newd);
            a=newd;
            System.out.println("删除后的数组为");
            System.out.println(Arrays.toString(newd));
        }
        public void search(int n){
            int position=Arrays.binarySearch(a,n);
            System.out.println("查找到的"+n+"的位置是"+(position+1));
        }
    }
}