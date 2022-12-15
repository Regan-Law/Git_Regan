import java.util.Arrays;

public class workC2{
    public static void main(String args[])
    {
        arrayreserve array=new arrayreserve();
        int[] a={1,2,3,4,5,6,7,8,9};
        array.reserve(a);
        System.out.println(Arrays.toString(a));
    }
    public static class arrayreserve{
        public int[] reserve(int a[]){
            int length=a.length;
            for(int i=0;i<length/2;i++){
                int temp=a[i];
                a[i]=a[length-i-1];
                a[length-i-1]=temp;
            }
            return a;
        }
    }
}