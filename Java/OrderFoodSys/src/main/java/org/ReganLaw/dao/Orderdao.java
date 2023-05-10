package org.ReganLaw.dao;

import org.ReganLaw.db.Order;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Orderdao{
    public int orderadd(Connection conn,Order order) throws SQLException{
        String sql="insert into Customer_order values(?,?,?,?,?,?)";
        PreparedStatement pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,order.getCo_id());
        pstmt.setString(2,order.getC_id());
        pstmt.setString(3,order.getC_name());
        pstmt.setString(4,order.getC_address());
        pstmt.setString(5,order.getC_pho());
        return pstmt.executeUpdate();
    }

    public int foodadd(Connection conn,Order order) throws SQLException{
        String sql="insert into Food_order values(?,?,?,?)";
        PreparedStatement pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,order.getFood_name());
        pstmt.setFloat(2,order.getFood_price());
        pstmt.setInt(3,order.getFood_num());
        pstmt.setString(4,order.getCo_id());
        return pstmt.executeUpdate();
    }

    public ResultSet orderlist(Connection conn,Order order) throws SQLException{
        StringBuilder sb=new StringBuilder("select * from Customer_order");
        if(order.getCo_id().isEmpty()){
            sb.append("and Co_id like").append(order.getCo_id());
        }
        if((order.getC_name().isEmpty())){
            sb.append("and C_name like").append(order.getC_id());
        }
        PreparedStatement pstmt=conn.prepareStatement(sb.toString());
        return pstmt.executeQuery();
    }

    public int orderdel(Connection conn,Order order) throws SQLException{
        String sql="delete from Customer_order where Co_id = ? ";
        PreparedStatement pstmt1=conn.prepareStatement(sql);
        pstmt1.setString(1,order.getCo_id());
        pstmt1.executeUpdate();
        sql="delete from Food_order where Co_id =?";
        PreparedStatement pstme2=conn.prepareStatement(sql);
        pstme2.setString(1,order.getCo_id());
        return pstme2.executeUpdate();
    }
}