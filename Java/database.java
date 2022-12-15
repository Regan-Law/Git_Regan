import java.sql.*;

public class database {
    public static Connection getConnection() {
        Connection conn = null;
        String jdbc_driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        String jdbc_url = "jdbc:sqlserver://127.0.0.1:1433;DatabaseName=OS";
        try {
            Class.forName(jdbc_driver);
            conn = DriverManager.getConnection(jdbc_url, "sa", "011017");
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        return conn;
    }

    public static void main(String[] args) throws SQLException {
        Connection conn = getConnection();
        Statement statement =null;
        statement= conn.createStatement();
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if (statement != null) {
            try {
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}