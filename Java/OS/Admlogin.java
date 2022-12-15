package OS;

import java.sql.*;

public class Admlogin {
    public static boolean StuLogin(String username, String passwd) {
        Connection conn = DatabaseConnection.get(username,passwd);
        String sql = "select Username from Stu where M_id=? and M_assword=?";
        boolean flag = false;
        try {
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setString(1, username);
            ps.setString(2, passwd);
            ResultSet rs = ps.executeQuery();
            if (rs.next()) {
                flag = true;
            }
            rs.close();
            ps.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return flag;
    }
}
