import java.util.Arrays;
import java.util.Scanner;

public class workC1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        array myarray=new array();
        myarray.print();
        myarray.sort();
        System.out.println("��������Ҫ���������");
        int n=sc.nextInt();
        myarray.insert(n);
        System.out.println("��������Ҫɾ��������");
        int d=sc.nextInt();
        myarray.delete(d);
        System.out.println("��������Ҫ���ҵ�����");
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
            System.out.println("�����Ϊ"+Arrays.toString(a));
        }
        public void insert(int n){
            int newa[]=new int[a.length+1];
            System.arraycopy(a, 0, newa, 0, a.length);
            newa[a.length]=n;
            Arrays.sort(newa);
            a=newa;
            System.out.println("����������Ϊ");
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
            System.out.println("ɾ���������Ϊ");
            System.out.println(Arrays.toString(newd));
        }
        public void search(int n){
            int position=Arrays.binarySearch(a,n);
            System.out.println("���ҵ���"+n+"��λ����"+(position+1));
        }
    }
}