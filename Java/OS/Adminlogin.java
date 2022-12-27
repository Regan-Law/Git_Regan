package OS;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JPasswordField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Adminlogin extends JFrame {

	private JPanel contentPane;
	private JTextField adminname;
	private JPasswordField adminpasswd;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Adminlogin frame = new Adminlogin();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Adminlogin() {
		setTitle("管理员登录");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 485, 320);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		adminname = new JTextField();
		adminname.setBounds(185, 53, 197, 32);
		adminname.setColumns(10);
		
		JButton login = new JButton("登录");
		login.setBounds(142, 170, 97, 23);
		login.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				adminlogin(e);
			}
		});
		
		JButton register = new JButton("注册");
		register.setBounds(242, 170, 97, 23);

		JLabel name=new JLabel("用户名");
		name.setBounds(99, 53, 76, 32);
		name.setHorizontalAlignment(SwingConstants.CENTER);
		name.setFont(new Font("宋体", Font.PLAIN, 20));

		JLabel passwd=new JLabel("密  码");
		passwd.setBounds(99, 108, 76, 32);
		passwd.setHorizontalAlignment(SwingConstants.CENTER);
		passwd.setFont(new Font("宋体", Font.PLAIN, 20));
		
		adminpasswd = new JPasswordField();
		adminpasswd.setBounds(185, 108, 196, 32);
		contentPane.setLayout(null);
		contentPane.add(name);
		contentPane.add(adminname);
		contentPane.add(passwd);
		contentPane.add(adminpasswd);
		contentPane.add(login);
		contentPane.add(register);
		
		JButton userlogin = new JButton("用户登录");
		userlogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				UI.main(null);
			}
		});
		userlogin.setBounds(142, 203, 197, 23);
		contentPane.add(userlogin);
	}

	protected void adminlogin(ActionEvent e) {
		// TODO �?动生成的方法存根
		String name=adminname.getText().toString();
		String passwd=adminpasswd.getPassword().toString();
		Admlogin.StuLogin(name, passwd);
	}
}
