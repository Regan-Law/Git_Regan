import java.util.Arrays;

public class workC3{
    public static void main(String[] args)
    {
        array myarray=new array();
        myarray.print();
        myarray.insert(2, 10);
        myarray.print();
        myarray.delete(6);
        myarray.print();
    }
    public static class array{
        int[]a={1,3,7,9,4,6,8,5,2};
        int count=9;
        public void insert(int position,int data){
            if(a.length==count){
                int [] newa=new int[a.length+1];
                System.arraycopy(a, 0, newa, 0, a.length);
                a=newa;
            }
            for(int i=count;i>position;i--){
                a[i]=a[i-1];
            }
            a[position]=data;
            count++;
        }
        public void delete(int position){
            int newd[]=new int[a.length-1];
            for(int i=0;i<newd.length;i++){
                if (i<position) {
                    newd[i]=a[i];
                }
                else {
                    newd[i]=a[i+1];
                }
            }
            a=newd;
        }
        public void print(){
            System.out.println(Arrays.toString(a));
        }
    }
}