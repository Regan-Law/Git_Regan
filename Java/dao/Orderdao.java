package dao;

import java.sql.*;

import com.microsoft.sqlserver.jdbc.StringUtils;

import db.Order;

public class Orderdao {
    public int orderadd(Connection conn,Order order) throws SQLException {
        String sql="insert into Customer_order values(?,?,?,?,?,?)";
        PreparedStatement pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, order.getCo_id());
        pstmt.setString(2,order.getC_id());
        pstmt.setString(3,order.getC_name());
        pstmt.setString(4,order.getC_address());
        pstmt.setString(5,order.getC_pho());
        return pstmt.executeUpdate();
    }
    public int foodadd(Connection conn,Order order) throws SQLException {
        String sql="insert into Food_order values(?,?,?,?)";
        PreparedStatement pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, order.getFood_name());
        pstmt.setFloat(2,order.getFood_price());
        pstmt.setInt(3,order.getFood_num());
        pstmt.setString(4,order.getCo_id());
        return pstmt.executeUpdate();
    }
    public ResultSet orderlist(Connection conn,Order order) throws SQLException {
        StringBuffer sb = new StringBuffer("select * from Customer_order");
        if(StringUtils.isEmpty(order.getCo_id())) {
            sb.append("and Co_id like"+order.getCo_id());
        }
        if(StringUtils.isEmpty(order.getC_name())) {
            sb.append("and C_name like"+order.getC_id());
        }
        PreparedStatement pstmt = conn.prepareStatement(sb.toString());
        return pstmt.executeQuery();
    }
    public int orderdel(Connection conn,Order order) throws SQLException {
        String sql="delete from Customer_order where Co_id = ? ";
        PreparedStatement pstmt1 = conn.prepareStatement(sql);
        pstmt1.setString(1,order.getCo_id());
        pstmt1.executeUpdate();
        sql="delete from Food_order where Co_id =?";
        PreparedStatement pstme2 = conn.prepareStatement(sql);
        pstme2.setString(1,order.getCo_id());
        return pstme2.executeUpdate();
    }
}
