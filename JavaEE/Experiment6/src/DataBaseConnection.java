import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DataBaseConnection{
    public static Connection get(){
        Connection conn;
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/javaee?useUnicode=true&characterEncoding=UTF-8","root","yan011017");
        }catch(ClassNotFoundException|SQLException e){
            throw new RuntimeException(e);
        }
        return conn;
    }
}