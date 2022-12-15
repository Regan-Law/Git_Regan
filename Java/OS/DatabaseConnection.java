package OS;

import java.sql.*;

public class DatabaseConnection {

    public static Connection get(String name,String passwd) {
        Connection conn = null;
        String jdbc_driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        String jdbc_url = "jdbc:sqlserver://localhost:1433;DatabaseName=OS";
        try {
            Class.forName(jdbc_driver);
            conn = DriverManager.getConnection(jdbc_url, "name", "passwd");
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        return conn;
    }
    public static void close(ResultSet rs,PreparedStatement pstmt,Connection conn) throws Exception {
        if (rs != null) {
            rs.close();
        }
        if (pstmt!= null) {
            pstmt.close();
        }
        if (conn != null) {
            conn.close();
        }
    }
    public static void close(PreparedStatement pstmt,Connection conn) throws Exception {
        if (pstmt!= null) {
            pstmt.close();
        }
        if (conn != null) {
            conn.close();
        }
    }
}