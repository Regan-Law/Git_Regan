package sims

import dao.Studao.stuAdd
import dao.Studao.stuDel
import dao.Studao.stuImg
import dao.Studao.stuList
import dao.Studao.stuSearch
import dao.Studao.stuUpdate
import sims.DatabaseConnection.close
import sims.DatabaseConnection.get
import java.awt.BorderLayout
import java.awt.Dimension
import java.awt.FlowLayout
import java.awt.Toolkit
import java.io.*
import java.sql.Connection
import java.sql.SQLException
import java.util.*
import javax.swing.*
import javax.swing.filechooser.FileNameExtensionFilter
import javax.swing.table.DefaultTableModel
import javax.swing.table.TableModel
import kotlin.system.exitProcess

class LoginGUI {
	private var jf: JFrame? = null
	
	// 水平box
	private val center = Box.createVerticalBox()
	
	// 学号的JPanel
	private val idPanel = JPanel()
	
	// 密码的JPanel
	private val passwordPanel = JPanel()
	private val lUserId = JLabel("用户名")
	private val tUserId = JTextField(15)
	private val lPassword = JLabel("密   码")
	private val tPassword = JPasswordField(15)
	
	// 按钮的JPanel
	private val buttonPanel = JPanel()
	private val bLogin = JButton("登录")
	private val bCancel = JButton("取消")
	
	// 设置运行时窗口的大小
	private var faceSize = Dimension(350, 150)
	
	// 获得屏幕的大小
	private var screenSize = Toolkit.getDefaultToolkit().screenSize
	fun init() {
		jf = JFrame("学生信息管理系统")
		// 设置JFrame的名称
		jf!!.title = "登录"
		// 将lUserId,tUserId放在idPanel中，idPanel默认水平放置
		idPanel.add(lUserId)
		idPanel.add(tUserId)
		passwordPanel.add(lPassword)
		passwordPanel.add(tPassword)
		center.add(idPanel)
		center.add(passwordPanel)
		buttonPanel.add(bLogin)
		buttonPanel.add(bCancel)
		// 登录按钮的监听器
		bLogin.addActionListener {
			val userId = tUserId.text
			val password = String(tPassword.password)
			// 开启接受数据的线程
			if ((userId!!.trim { it <= ' ' } == "") || (password.trim { it <= ' ' } == "")) {
				JOptionPane.showMessageDialog(jf, "用户名或密码不能为空！", "提示", JOptionPane.WARNING_MESSAGE)
			} else {
				if (login.StuLogin(userId, password)) {
					jf!!.isVisible = false
					StudentManageView().init()
				} else {
					loginFailure()
				}
			}
		}
		// 取消按钮的监听器
		bCancel.addActionListener { exitProcess(0) }
		center.add(buttonPanel)
		jf!!.add(center)
		jf!!.pack()
		// 设置JFame运行时的大小
		jf!!.size = faceSize
		// 设置JFame运行时的位置
		jf!!.setLocation(
			(screenSize.width - faceSize.getWidth()).toInt() / 2,
			(screenSize.height - faceSize.getHeight()).toInt() / 2
		)
		// 设置JFrame不可最大化
		jf!!.isResizable = false
		// 设置JFrame单击X时结束程序
		jf!!.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
		// 设置JFrame可见
		jf!!.isVisible = true
	}
	
	//登录方法
	object login {
		fun StuLogin(id: String?, passwd: String): Boolean {
			val conn = get()
			val sql = "select * from Users where Id=? "
			var flag = false
			try {
				val ps = conn!!.prepareStatement(sql)
				ps.setString(1, id)
				val rs = ps.executeQuery()
				if (rs.next()) {
					val pa = rs.getString(2)
					if ((passwd == pa)) {
						flag = true
					}
				}
				rs.close()
				ps.close()
			} catch (e: SQLException) {
				e.printStackTrace()
			}
			return flag
		}
	}
	
	private fun loginFailure() {
		JOptionPane.showMessageDialog(jf, "用户名或密码输入不正确！", "提示", JOptionPane.WARNING_MESSAGE)
		tUserId.text = null
		tPassword.text = null
	}
	
	companion object {
		@Throws(Exception::class)
		@JvmStatic
		fun main(args: Array<String>) {
			LoginGUI().init()
		}
	}
}

internal class MyJTable(dm: TableModel?) : JTable(dm) {
	// 设置表格不可编辑
	override fun isCellEditable(rowIndex: Int, columnIndex: Int): Boolean {
		return false
	}
	
	companion object {
		private const val serialVersionUID = -3083638370004874364L
	}
}

internal class StudentManageView {
	// 设置上传照片的按钮
	private val tpath = JTextField(13)
	private val select = JButton("浏览")
	private val uploadChooser = JFileChooser()
	private val downloadChooser = JFileChooser()
	private val upload = JButton("上传")
	private val download = JButton("下载")
	private val jf = JFrame("学生信息管理系统")
	private var faceSize = Dimension(800, 600)
	private val screenSize = Toolkit.getDefaultToolkit().screenSize
	
	// 按学号查询
	private val pSelect = JPanel()
	private val lSelect = JLabel("学号")
	private val tSelect = JTextField(15)
	private val bSelect = JButton("查询")
	
	// 查询结果放在一个JTable
	private var table: MyJTable? = null
	private var dtm: DefaultTableModel? = null
	private var tableScrollPane: JScrollPane? = null
	private val defaulticon = ImageIcon(
		ImageIcon("D:\\Stuimg\\Stu1.jpg").image.getScaledInstance(30, 30, 3)
	)
	private val tableTitle = arrayOf<Any>("学号", "姓名", "性别", "年龄")
	private val tableData = arrayOf(arrayOf<Any>(""))
	
	// 对学生信息进行管理的添加、删除、修改按钮
	private val buttonPanel = JPanel()
	private val check = JButton("查看")
	private val insert = JButton("添加")
	private val delete = JButton("删除")
	private val update = JButton("修改")
	
	// 单击添加、修改时弹出的对话框
	private val dialog = JDialog(jf, "学生管理")
	private val box = Box.createVerticalBox()
	private val pPhoto = JPanel(FlowLayout(FlowLayout.LEFT))
	private val spath = JPanel(FlowLayout(FlowLayout.LEFT))
	private val sPhoto = JPanel(FlowLayout(FlowLayout.LEFT))
	private val pId = JPanel(FlowLayout(FlowLayout.LEFT))
	private val pName = JPanel(FlowLayout(FlowLayout.LEFT))
	private val pSex = JPanel(FlowLayout(FlowLayout.LEFT))
	private val pAge = JPanel(FlowLayout(FlowLayout.LEFT))
	private val lPhoto = JLabel("照片")
	private val photopath = JLabel("照片路径")
	private val lId = JLabel("学 号")
	private val lName = JLabel("姓 名")
	private val lSex = JLabel("性 别")
	private val lAge = JLabel("年 龄")
	private val tPhoto = JLabel(defaulticon)
	private val tId = JTextField(15)
	private val tName = JTextField(15)
	private val bSex = ButtonGroup()
	private val boy = JRadioButton("男")
	private val girl = JRadioButton("女")
	private val tAge = JTextField(15)
	private val pButton = JPanel()
	private val confirm = JButton("确认")
	private val cancel = JButton("取消")
	
	// 用于标记是添加还是修改
	private var id: String? = null
	fun init() {
		pSelect.add(lSelect)
		pSelect.add(tSelect)
		pSelect.add(bSelect)
		// table
		dtm = DefaultTableModel(tableData, tableTitle)
		table = MyJTable(dtm)
		tableScrollPane = JScrollPane(
			table, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
			JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED
		)
		val stu = Students()
		fill()
		// 查询按钮的监听器
		bSelect.addActionListener {
			val userId = tSelect.text.trim { it <= ' ' }
			stu.id = userId
			val conn: Connection?
			stu.id = userId
			try {
				conn = get()
				val rs = stuSearch((conn)!!, stu)
				dtm!!.rowCount = 0
				if (rs.next()) {
					val v = Vector<String>().apply {
						add(rs.getString("Sno"))
						add(rs.getString("Sname"))
						add(rs.getString("Ssex"))
						add(rs.getString("Sage"))
					}
					dtm!!.addRow(v)
				} else {
					selectFailure()
					dtm!!.rowCount = 0
					Students()
					fill()
				}
			} catch (e1: SQLException) {
				e1.printStackTrace()
			}
		}
		
		// button
		buttonPanel.add(check)
		buttonPanel.add(insert)
		buttonPanel.add(delete)
		buttonPanel.add(update)
		// 查看按钮的监听器
		check.addActionListener {
			photopath.isVisible = false
			tpath.isVisible = false
			select.isVisible = false
			upload.isVisible = false
			download.isVisible = true
			val row = table!!.selectedRow
			boy.isVisible = true
			girl.isVisible = true
			if (row < 0) {
				JOptionPane.showMessageDialog(null, "未选中任何学生")
			} else {
				// 如果要进行修改，就将id=要修改的学号
				id = table!!.getValueAt(row, 0).toString()
				// 设置tId的内容
				tId.text = id
				val conn: Connection?
				try {
					conn = get()
					stu.id = id
					val rs = stuImg((conn)!!, stu)
					while (rs.next()) {
						val icon = ImageIcon(
							ImageIcon(rs.getString("Simg")).image.getScaledInstance(30, 30, 3)
						)
						tPhoto.icon = icon
						stu.photo = rs.getString("Simg")
						// 下载照片的监听器
						download.addActionListener {
							downloadChooser.currentDirectory = File("D:/")
							val filter = FileNameExtensionFilter("图片文件(*.jpg)", "jpg")
							downloadChooser.fileFilter = filter
							val result = downloadChooser.showSaveDialog(jf)
							if (result == JFileChooser.APPROVE_OPTION) {
								val path = downloadChooser.selectedFile.path
								val fromFileName = stu.photo
								write(fromFileName, "$path.jpg")
								JOptionPane.showMessageDialog(
									jf,
									"下载成功！",
									"提示",
									JOptionPane.WARNING_MESSAGE
								)
							}
						}
					}
				} catch (ex: Exception) {
					ex.printStackTrace()
				}
				// 设置tId不可修改
				tId.isEditable = false
				tName.text = table!!.getValueAt(row, 1).toString()
				tName.isEditable = false
				val sex = table!!.getValueAt(row, 2) as String
				// 如果性别是"男",则将单选框中的男选中，否则选中女
				if ((sex == "男")) {
					bSex.setSelected(boy.model, true)
					girl.isVisible = false
				} else {
					bSex.setSelected(girl.model, true)
					boy.isVisible = false
				}
				tAge.text = table!!.getValueAt(row, 3).toString()
				tAge.isEditable = false
				// 设置dialog可见
				confirm.isVisible = false
				confirm.isEnabled = false
				dialog.isVisible = true
			}
		}
		// 添加按钮的监听器
		insert.addActionListener { // 浏览按钮的监听器
			select.addActionListener {
				uploadChooser.currentDirectory = File("D:/")
				val result = uploadChooser.showOpenDialog(jf)
				if (result == JFileChooser.APPROVE_OPTION) {
					val path = uploadChooser.selectedFile.path
					tpath.text = path
				}
			}
			// 上传按钮的监听器
			upload.addActionListener {
				val fromFileName: String = tpath.text
				val toFileName = "D:\\Stuimg\\Stu" + stu.id + ".jpg"
				write(fromFileName, toFileName)
				val icon = ImageIcon(
					ImageIcon(toFileName).image.getScaledInstance(30, 30, 3)
				)
				tPhoto.icon = icon
			}
			// 如果是添加，则将id=null;
			tPhoto.icon = defaulticon
			id = null
			photopath.isVisible = true
			tpath.isVisible = true
			select.isVisible = true
			upload.isVisible = true
			download.isVisible = false
			tId.isEditable = true
			tName.isEditable = true
			tAge.isEditable = true
			boy.isVisible = true
			girl.isVisible = true
			confirm.isVisible = true
			confirm.isEnabled = true
			tpath.text = ""
			tId.text = ""
			tName.text = ""
			bSex.clearSelection()
			tAge.text = ""
			dialog.isVisible = true
		}
		// 删除按钮的监听器
		delete.addActionListener {
			// 获得选择删除的行号数组
			val selected = table!!.selectedRows
			
			// 如果selected的长度为0，说明没有选择要删除的
			if (selected.isEmpty()) {
				JOptionPane.showMessageDialog(jf, "请选择要删除的信息！", "提示", JOptionPane.WARNING_MESSAGE)
			} else {
				// 提示是否要进行删除
				val flag = JOptionPane.showConfirmDialog(jf, "确认删除吗？", "提示", JOptionPane.WARNING_MESSAGE)
				// 如果选择是，则进行删除
				if (flag == JOptionPane.OK_OPTION) {
					for (i in selected.indices.reversed()) {
						val sid = dtm!!.getValueAt(selected[i], 0) as String
						stu.id = sid
						var conn: Connection?
						try {
							conn = get()
							val flag1 = stuDel((conn)!!, stu)
							if (flag1 >= 1) {
								dtm!!.rowCount = 0
								Students()
								fill()
							}
							conn!!.close()
						} catch (e1: Exception) {
							e1.printStackTrace()
							JOptionPane.showMessageDialog(null, "删除失败")
						}
					}
					JOptionPane.showMessageDialog(null, "删除成功")
				}
			}
		}
		// 修改按钮的监听器
		update.addActionListener {
			photopath.isVisible = true
			tpath.isVisible = true
			select.isVisible = true
			upload.isVisible = true
			download.isVisible = true
			tId.isEditable = true
			tName.isEditable = true
			tAge.isEditable = true
			boy.isVisible = true
			girl.isVisible = true
			confirm.isVisible = true
			confirm.isEnabled = true
			// 下载照片的监听器
			download.addActionListener {
				downloadChooser.currentDirectory = File("D:/")
				val filter = FileNameExtensionFilter("图片文件(*.jpg)", "jpg")
				downloadChooser.fileFilter = filter
				val result = downloadChooser.showSaveDialog(jf)
				if (result == JFileChooser.APPROVE_OPTION) {
					val path = downloadChooser.selectedFile.path
					val fromFileName = stu.photo
					write(fromFileName, "$path.jpg")
					JOptionPane.showMessageDialog(jf, "下载成功！", "提示", JOptionPane.WARNING_MESSAGE)
				}
			}
			// 浏览按钮的监听器
			select.addActionListener {
				jf.isVisible = true
				uploadChooser.currentDirectory = File("D:/")
				val result = uploadChooser.showOpenDialog(jf)
				if (result == JFileChooser.APPROVE_OPTION) {
					val path = uploadChooser.selectedFile.path
					tpath.text = path
				}
			}
			// 上传按钮的监听器
			upload.addActionListener {
				val fromFileName = tpath.text
				val toFileName = "D:\\Stuimg\\Stu" + stu.id + ".jpg"
				write(fromFileName, toFileName)
				val icon = ImageIcon(
					ImageIcon(toFileName).image.getScaledInstance(30, 30, 3)
				)
				tPhoto.icon = icon
			}
			val row = table!!.selectedRow
			if (row < 0) {
				JOptionPane.showMessageDialog(null, "未选中任何学生")
			} else {
				// 如果要进行修改，就将id=要修改的学号
				id = table!!.getValueAt(row, 0).toString()
				// 设置tId的内容
				tId.text = id
				var conn: Connection?
				try {
					conn = get()
					stu.id = id
					val rs = stuImg((conn)!!, stu)
					while (rs.next()) {
						tpath.text = rs.getString("Simg")
					}
				} catch (ex: Exception) {
					// TODO Auto-generated catch block
					ex.printStackTrace()
				}
				// 设置tId不可修改
				tId.isEditable = false
				try {
					conn = get()
					stu.id = id
					val rs = stuImg((conn)!!, stu)
					while (rs.next()) {
						val icon = ImageIcon(
							ImageIcon(rs.getString("Simg")).image.getScaledInstance(30, 30, 3)
						)
						tPhoto.icon = icon
					}
				} catch (ex: Exception) {
					// TODO Auto-generated catch block
					ex.printStackTrace()
				}
				tName.text = table!!.getValueAt(row, 1).toString()
				val sex = table!!.getValueAt(row, 2) as String
				// 如果性别是"男",则将单选框中的男选中，否则选中女
				if ((sex == "男")) {
					bSex.setSelected(boy.model, true)
				} else {
					bSex.setSelected(girl.model, true)
				}
				tAge.text = table!!.getValueAt(row, 3).toString()
				// 设置dialog可见
				dialog.isVisible = true
			}
		}
		jf.layout = BorderLayout()
		// 设置pSelect在jf的北面
		jf.add(pSelect, BorderLayout.NORTH)
		// 设置pSelect在jf的中心
		tableScrollPane?.let { jf.add(it, BorderLayout.CENTER) }
		// 设置pSelelct在jf的南面
		jf.add(buttonPanel, BorderLayout.SOUTH)
		jf.pack()
		jf.size = faceSize
		jf.setLocation(
			(screenSize.width - faceSize.getWidth()).toInt() / 2,
			(screenSize.height - faceSize.getHeight()).toInt() / 2
		)
		jf.isResizable = false
		jf.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
		jf.isVisible = true
		pPhoto.add(lPhoto)
		pPhoto.add(tPhoto)
		spath.add(photopath)
		spath.add(tpath)
		sPhoto.add(select)
		sPhoto.add(upload)
		sPhoto.add(download)
		pId.add(lId)
		pId.add(tId)
		pName.add(lName)
		pName.add(tName)
		pSex.add(lSex)
		bSex.add(boy)
		bSex.add(girl)
		pSex.add(boy)
		pSex.add(girl)
		pAge.add(lAge)
		pAge.add(tAge)
		pButton.add(confirm)
		pButton.add(cancel)
		// 确定按钮的监听器
		confirm.addActionListener {
			stu.id = tId.text
			stu.name = tName.text
			var sex: String? = null
			if (boy.isSelected) {
				sex = "男"
			}
			if (girl.isSelected) {
				sex = "女"
			}
			stu.sex = sex
			stu.age = tAge.text
			stu.photo = tpath.text
			if (id == null) {
				val conn: Connection?
				try {
					conn = get()
					val flag = stuAdd((conn)!!, stu)
					if (flag == 1) {
						JOptionPane.showMessageDialog(null, "添加成功")
						dialog.dispose()
					} else {
						JOptionPane.showMessageDialog(null, "添加失败")
					}
				} catch (e1: SQLException) {
					e1.printStackTrace()
				}
			} else {
				val conn: Connection?
				try {
					conn = get()
					val flag = stuUpdate((conn)!!, stu)
					if (flag == 1) {
						JOptionPane.showMessageDialog(null, "修改成功")
						table!!.updateUI()
						dialog.dispose()
					} else {
						JOptionPane.showMessageDialog(null, "修改失败")
					}
				} catch (e1: SQLException) {
					// TODO 自动生成的 catch 块
					e1.printStackTrace()
				}
			}
		}
		// 取消按钮的监听器
		cancel.addActionListener { dialog.dispose() }
		box.add(pPhoto)
		box.add(spath)
		box.add(sPhoto)
		box.add(pId)
		box.add(pName)
		box.add(pSex)
		box.add(pAge)
		box.add(pButton)
		box.add(pButton)
		dialog.add(box)
		dialog.setBounds((screenSize.width - 280) / 2, (screenSize.height - 300) / 2, 280, 350)
	}
	
	// fromFile是源文件，toFile是目的文件
	private fun write(fromFile: String?, toFile: String?) {
		var fis: FileInputStream? = null
		var fos: FileOutputStream? = null
		try {
			fis = fromFile?.let { FileInputStream(it) }
			fos = toFile?.let { FileOutputStream(it) }
			val buf = ByteArray(1024)
			var hasRead: Int
			if (fis != null) {
				while ((fis.read(buf).also { hasRead = it }) > 0) {
					fos?.write(buf, 0, hasRead)
				}
			}
		} catch (e: FileNotFoundException) {
			e.printStackTrace()
		} catch (e: IOException) {
			e.printStackTrace()
		} finally {
			try {
				fis!!.close()
				fos!!.close()
			} catch (e: IOException) {
				e.printStackTrace()
			}
		}
	}
	
	//连接数据库填充表格数据
	private fun fill() {
		dtm!!.rowCount = 0
		var conn: Connection? = null
		try {
			conn = get()
			val rs = stuList((conn)!!)
			while (rs.next()) {
				val v = Vector<String>()
				v.add(rs.getString("Sno"))
				v.add(rs.getString("Sname"))
				v.add(rs.getString("Ssex"))
				v.add(rs.getString("Sage"))
				dtm!!.addRow(v)
			}
		} catch (e: Exception) {
			e.printStackTrace()
		} finally {
			try {
				close(conn)
			} catch (e: Exception) {
				e.printStackTrace()
			}
		}
	}
	
	private fun selectFailure() {
		JOptionPane.showMessageDialog(jf, "不存在该学号的学生!", "提示", JOptionPane.WARNING_MESSAGE)
	}
}