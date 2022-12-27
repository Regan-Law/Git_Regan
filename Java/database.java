import java.sql.*;

public class database {
    public static Connection getConnection() {
        Connection conn=null;
        String jdbc_driver="com.mysql.cj.jdbc.Driver";
        String jdbc_url="jdbc:mysql://127.0.0.1:3306;DatabaseName=OS";
        try{
            Class.forName(jdbc_driver);
            conn=DriverManager.getConnection(jdbc_url,"root","yan011017");
        }catch(ClassNotFoundException|SQLException ex){
            ex.printStackTrace();
        }
        return conn;
    }

    public static void main(String[] args) throws SQLException{
        Connection conn=getConnection();
        Statement statement=null;
        statement=conn.createStatement();
        try{
            conn.close();
        }catch(SQLException e){
            e.printStackTrace();
        }
        if(statement!=null){
            try{
                statement.close();
            }catch(SQLException e){
                e.printStackTrace();
            }
        }
    }
}