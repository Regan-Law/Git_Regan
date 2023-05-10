package org.ReganLaw.OS;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

public class Adminlogin extends JFrame{

    private final JTextField adminname;
    private final JPasswordField adminpasswd;

    public Adminlogin(){
        setTitle("管理员登录");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100,100,485,320);
        JPanel contentPane=new JPanel();
        contentPane.setBorder(new EmptyBorder(5,5,5,5));
        setContentPane(contentPane);

        adminname=new JTextField();
        adminname.setBounds(185,53,197,32);
        adminname.setColumns(10);

        JButton login=new JButton("登录");
        login.setBounds(142,170,97,23);
        login.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                adminlogin(e);
            }
        });

        JButton register=new JButton("注册");
        register.setBounds(242,170,97,23);

        JLabel name=new JLabel("用户名");
        name.setBounds(99,53,76,32);
        name.setHorizontalAlignment(SwingConstants.CENTER);
        name.setFont(new Font("宋体",Font.PLAIN,20));

        JLabel passwd=new JLabel("密  码");
        passwd.setBounds(99,108,76,32);
        passwd.setHorizontalAlignment(SwingConstants.CENTER);
        passwd.setFont(new Font("宋体",Font.PLAIN,20));

        adminpasswd=new JPasswordField();
        adminpasswd.setBounds(185,108,196,32);
        contentPane.setLayout(null);
        contentPane.add(name);
        contentPane.add(adminname);
        contentPane.add(passwd);
        contentPane.add(adminpasswd);
        contentPane.add(login);
        contentPane.add(register);

        JButton userlogin=new JButton("用户登录");
        userlogin.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                dispose();
                UI.main(null);
            }
        });
        userlogin.setBounds(142,203,197,23);
        contentPane.add(userlogin);
    }

    /**
     * Launch the application.
     */
    public static void main(String[] args){
        EventQueue.invokeLater(new Runnable(){
            public void run(){
                try{
                    Adminlogin frame=new Adminlogin();
                    frame.setVisible(true);
                }catch(Exception e){
                    e.printStackTrace();
                }
            }
        });
    }

    protected void adminlogin(ActionEvent e){
        String name=adminname.getText();
        String passwd=Arrays.toString(adminpasswd.getPassword());
        Admlogin.StuLogin(name,passwd);
    }
}