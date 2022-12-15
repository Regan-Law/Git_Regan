package OS;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JPasswordField;

public class UI extends JFrame {

	private JPanel contentPane;
	private JTextField username;
	private JPasswordField userpasswd;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					UI frame = new UI();
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
	public UI() {
		setTitle("用户登录");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 485, 320);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		username = new JTextField();
		username.setBounds(185, 51, 197, 32);
		username.setColumns(10);
		
		userpasswd = new JPasswordField();
		userpasswd.setColumns(10);
		userpasswd.setBounds(185, 106, 197, 32);
		contentPane.add(userpasswd);
		
		JButton login = new JButton("登录");
		login.setBounds(137, 167, 97, 23);
		login.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				login(e);
			}
		});
		
		JButton register = new JButton("注册");
		register.setBounds(237, 167, 97, 23);
		register.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		
		JLabel name = new JLabel("用户名");
		name.setBounds(99, 51, 76, 32);
		name.setFont(new Font("宋体", Font.PLAIN, 20));
		name.setHorizontalAlignment(SwingConstants.CENTER);
		
		JLabel passwd = new JLabel("密  码");
		passwd.setBounds(99, 106, 76, 32);
		passwd.setHorizontalAlignment(SwingConstants.CENTER);
		passwd.setFont(new Font("宋体", Font.PLAIN, 20));
		
		JButton adminlogin = new JButton("管理员登录");
		adminlogin.setBounds(137, 200, 197, 23);
		adminlogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				Adminlogin.main(null);;
			}
		});
		contentPane.setLayout(null);
		contentPane.add(login);
		contentPane.add(register);
		contentPane.add(adminlogin);
		contentPane.add(name);
		contentPane.add(username);
		contentPane.add(passwd);
	}

	protected void login(ActionEvent e) {
		// TODO 自动生成的方法存根
		String name=username.getText().toString();
		String passwd=userpasswd.getPassword().toString();
		Stulogin.StuLogin(name, passwd);
	}
}
