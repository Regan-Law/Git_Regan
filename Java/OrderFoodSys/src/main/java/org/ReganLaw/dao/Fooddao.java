package org.ReganLaw.dao;

import org.ReganLaw.db.Food;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Fooddao{
    public int Foodadd(Connection conn,Food food) throws SQLException{
        String sql="insert into food values(?,?,?)";
        PreparedStatement pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,food.getF_name());
        pstmt.setFloat(2,food.getF_price());
        return pstmt.executeUpdate();
    }

    public int Fooddel(Connection conn,String F_name) throws SQLException{
        String sql="delete from Food where F_name = ?";
        PreparedStatement pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,F_name);
        return pstmt.executeUpdate();
    }

    public int Foodupdate(Connection conn,Food food) throws SQLException{
        String sql="update Food set Food_price=? where F_name=?";
        PreparedStatement pstmt=conn.prepareStatement(sql);
        pstmt.setString(1,food.getF_name());
        pstmt.setFloat(1,food.getF_price());
        return pstmt.executeUpdate();
    }
}