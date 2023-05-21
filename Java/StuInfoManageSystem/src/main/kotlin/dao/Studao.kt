package dao

import sims.Students
import java.sql.Connection
import java.sql.ResultSet
import java.sql.SQLException

object Studao {
	@JvmStatic
	@Throws(SQLException::class)
	fun stuAdd(conn: Connection, stu: Students): Int {
		val sql = "insert into Students values(?,?,?,?,?)"
		val stmt = conn.prepareStatement(sql).apply {
			setString(1, stu.id)
			setString(2, stu.name)
			setString(3, stu.sex)
			setString(4, stu.age)
			setString(5, stu.photo)
		}
		return stmt.executeUpdate()
	}
	
	@JvmStatic
	@Throws(SQLException::class)
	fun stuDel(conn: Connection, stu: Students): Int {
		val sql = "delete from Student where Sno = ?"
		val stmt = conn.prepareStatement(sql)
		stmt.setString(1, stu.id)
		return stmt.executeUpdate()
	}
	
	@JvmStatic
	@Throws(SQLException::class)
	fun stuList(conn: Connection): ResultSet {
		val sql = "select * from Students"
		val stmt = conn.prepareStatement(sql)
		return stmt.executeQuery()
	}
	
	@JvmStatic
	@Throws(SQLException::class)
	fun stuSearch(conn: Connection, stu: Students): ResultSet {
		val sql = "select * from Students where Sno= ?"
		val stmt = conn.prepareStatement(sql)
		stmt.setString(1, stu.id)
		return stmt.executeQuery()
	}
	
	@JvmStatic
	@Throws(SQLException::class)
	fun stuUpdate(conn: Connection, stu: Students): Int {
		val sql = "update Students set Sno=? ,Sname=?,Ssex=?,Sage=?,Simg=? where Sno=?"
		val stmt = conn.prepareStatement(sql)
		stmt.setString(1, stu.id)
		stmt.setString(2, stu.name)
		stmt.setString(3, stu.sex)
		stmt.setString(4, stu.age)
		stmt.setString(5, stu.photo)
		stmt.setString(6, stu.id)
		return stmt.executeUpdate()
	}
	
	@JvmStatic
	@Throws(SQLException::class)
	fun stuImg(conn: Connection, stu: Students): ResultSet {
		val sql = "select Simg from Students where Sno= ?"
		val stmt = conn.prepareStatement(sql)
		stmt.setString(1, stu.id)
		return stmt.executeQuery()
	}
}