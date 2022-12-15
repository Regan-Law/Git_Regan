package sims;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.io.*;

public class Download {

	private JFrame jf = new JFrame();
	// 页面的总JPanel
	private JPanel total = new JPanel(new BorderLayout());
	private JPanel pDownload = new JPanel(new FlowLayout(FlowLayout.LEFT));
	private JLabel lDownload = new JLabel("下载下面的图片:");
	private JFileChooser downloadChooser = new JFileChooser();
	private JButton bDownload = new JButton("下  载");
	private JPanel pIcon = new JPanel(new FlowLayout(FlowLayout.LEFT));
	private ImageIcon icon = new ImageIcon(new ImageIcon("D:/Stuimg/Stu1.jpg").getImage().getScaledInstance(400, 320, 0));
	private JLabel lIcon = new JLabel(icon);
	public String Stuimg;
	Dimension faceSize = new Dimension(500, 450);
	// 设置运行时窗口的位置
	Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

	/**
	 * @wbp.parser.entryPoint
	 */
	public void photo(Student stu) {
		jf.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		pDownload.add(lDownload);
		pDownload.add(bDownload);
		pIcon.add(lIcon);
		total.add(pDownload, BorderLayout.CENTER);
		total.add(pIcon, BorderLayout.SOUTH);
		jf.getContentPane().add(total);
		jf.setSize(faceSize);
		jf.setLocation((int) (screenSize.width - faceSize.getWidth()) / 2,
				(int) (screenSize.height - faceSize.getHeight()) / 2);
		jf.setResizable(false);
		jf.setVisible(true);
		ImageIcon icons = new ImageIcon(new ImageIcon(stu.getPhoto()).getImage().getScaledInstance(400, 320, 0));
		lIcon.setIcon(icons);
		// 下载按钮的监听器
		bDownload.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				jf.setVisible(true);
				downloadChooser.setCurrentDirectory(new File("D:/"));
				int result = downloadChooser.showOpenDialog(jf);
				if (result == JFileChooser.APPROVE_OPTION) {
					String path = downloadChooser.getSelectedFile().getPath();
					String fromFileName = stu.getPhoto();
					write(fromFileName, path);
					JOptionPane.showMessageDialog(jf, "下载成功！", "提示", JOptionPane.WARNING_MESSAGE);
				}
			}
		});
	}

	// fromFile是源文件，toFile是目的文件
	public void write(String fromFile, String toFile) {
		FileInputStream fis = null;
		FileOutputStream fos = null;
		try {
			fis = new FileInputStream(fromFile);
			fos = new FileOutputStream(toFile);
			byte[] buf = new byte[1024];
			int hasRead = 0;
			while ((hasRead = fis.read(buf)) > 0) {
				fos.write(buf, 0, hasRead);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				fis.close();
				fos.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	public static void main(String args[]) {
		Student stu=new Student();
		new Download().photo(stu);
	}
}
