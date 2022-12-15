import java.io.*;

public class Filecopy{
    public static void main(String args[]) {
        try {
            FileInputStream a=new FileInputStream("D:\\test.txt");
            BufferedInputStream b=new BufferedInputStream(a);
            FileOutputStream aout=new FileOutputStream("D:\\test1.txt");
            BufferedOutputStream bout=new BufferedOutputStream(aout);
            int len=0;
            byte[] bytes=new byte[1024];
            while ((len=b.read(bytes, 0, 1024))!=-1) {
                bout.write(bytes, 0, len);
            }
            b.close();
            bout.close();
        }catch(FileNotFoundException e) {
            e.printStackTrace();
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}