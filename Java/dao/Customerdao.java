package dao;
import java.sql.*;

import db.Customer;
public class Customerdao {
    public int Customeradd(Connection conn,Customer customer) throws Exception {
        String sql = "insert into Customer values(?,?,?,?,?)";
        PreparedStatement pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, customer.getC_id());
        pstmt.setString(2, customer.getC_name());
        pstmt.setString(3, customer.getC_passwd());
        pstmt.setString(4, customer.getC_address());
        pstmt.setString(5, customer.getC_phone());
        return pstmt.executeUpdate();
    }
    public boolean isCustomerexist(Connection conn,Customer customer) throws Exception {
        String sql = "select * from Customer where C_id=?";
        PreparedStatement pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, customer.getC_id());
        ResultSet rs = pstmt.executeQuery();
        return rs.next();
    }
}
