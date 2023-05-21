package sims

import java.sql.*

object DatabaseConnection {
	@JvmStatic
	fun get(): Connection? {
		var conn: Connection? = null
		val jdbcUrl = "jdbc:oracle:thin:@localhost:1521:orcl"
		try {
			conn = DriverManager.getConnection(jdbcUrl, "system", "Yan011017")
		} catch (ex: ClassNotFoundException) {
			ex.printStackTrace()
		} catch (ex: SQLException) {
			ex.printStackTrace()
		}
		return conn
	}
	
	@JvmStatic
	@Throws(Exception::class)
	fun close(conn: Connection?) {
		conn?.close()
	}
}