/*
 * @Author: ReganLaw 609607745@qq.com
 * @Date: 2022-12-15 13:19:52
 * @LastEditors: ReganLaw 609607745@qq.com
 * @LastEditTime: 2022-12-26 18:53:09
 * @FilePath: \\Git_Regan\\Java\\Filereadandwrite.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ReganLaw 609607745@qq.com, All Rights Reserved. 
 */
import java.io.*;

public class Filereadandwrite {
    public static void main(String[] args) throws IOException{
        File readpath=new File("D:\\test.txt");
        FileReader read=new FileReader(readpath);
        BufferedReader bufferread=new BufferedReader(read);
        String line=null;        
        File writepath=new File("D:\\test1.txt");
        FileWriter write=new FileWriter(writepath);
        BufferedWriter bufferwrite=new BufferedWriter(write);  
        System.out.println("读取文件内容为：");
        while ((line=bufferread.readLine())!=null) {
            System.out.println(line);
            bufferwrite.write(line);
            bufferwrite.newLine();
        }        
        File overpath=new File("D:\\test.txt");
        FileReader over=new FileReader(overpath);
        BufferedReader bufferover=new BufferedReader(over);
        String overline=null;
        System.out.println("写入后的文件内容为：");
        while ((overline=bufferover.readLine())!=null) {
            System.out.println(overline);
        }  
        bufferread.close();
        read.close();
        bufferwrite.close();
        write.close();
        over.close();
        bufferover.close();
    }
}