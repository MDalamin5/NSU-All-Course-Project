package menus;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.TextArea;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextPane;
import javax.swing.border.EmptyBorder;

import login_page.AdminLogWindow;
import others.InvoiceWindow;
import source.BookCollection;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Menu1 extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Menu1 frame = new Menu1();
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
	public Menu1() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 698, 510);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(125, 90, 80));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JTextPane txtpnLogin = new JTextPane();
		txtpnLogin.setForeground(Color.WHITE);
		txtpnLogin.setEditable(false);
		txtpnLogin.setBackground(new Color(125, 90, 80));
		txtpnLogin.setFont(new Font("Nunito ExtraBold", Font.BOLD, 45));
		txtpnLogin.setText("Options\r\n");
		txtpnLogin.setBounds(250, 0, 186, 68);
		contentPane.add(txtpnLogin);
		
		JButton btnNewButton = new JButton("Sort Books");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Sort sort = new Sort();
				sort.setVisible(true);
				dispose();
			}
		});
		btnNewButton.setBackground(new Color(229, 178, 153));
		btnNewButton.setForeground(Color.WHITE);
		btnNewButton.setFont(new Font("Nunito Medium", Font.PLAIN, 25));
		btnNewButton.setBounds(0, 291, 684, 47);
		contentPane.add(btnNewButton);
		
		JButton btnRemoveBook = new JButton("Reset Books\r\n");
		btnRemoveBook.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnRemoveBook.setFont(new Font("Nunito Medium", Font.PLAIN, 25));
		btnRemoveBook.setForeground(Color.WHITE);
		btnRemoveBook.setBackground(new Color(121, 135, 119));
		btnRemoveBook.setBounds(0, 426, 684, 47);
		contentPane.add(btnRemoveBook);
		
		JButton btnBookInformation = new JButton("Book Information");
		btnBookInformation.setForeground(Color.WHITE);
		btnBookInformation.setFont(new Font("Nunito Medium", Font.PLAIN, 25));
		btnBookInformation.setBackground(new Color(189, 210, 182));
		btnBookInformation.setBounds(0, 336, 684, 47);
		contentPane.add(btnBookInformation);
		
		JButton btnNewButton_1_2_1 = new JButton("Remove Book\r\n");
		btnNewButton_1_2_1.setForeground(Color.WHITE);
		btnNewButton_1_2_1.setFont(new Font("Nunito Medium", Font.PLAIN, 25));
		btnNewButton_1_2_1.setBackground(new Color(162, 178, 159));
		btnNewButton_1_2_1.setBounds(0, 380, 684, 47);
		contentPane.add(btnNewButton_1_2_1);
		
		JButton btnNewButton_1_2_1_1 = new JButton("Add Book\r\n");
		btnNewButton_1_2_1_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				AddBooks addBooks = new AddBooks();
				addBooks.setVisible(true);
				dispose();
			}
		});
		btnNewButton_1_2_1_1.setForeground(Color.WHITE);
		btnNewButton_1_2_1_1.setFont(new Font("Nunito Medium", Font.PLAIN, 25));
		btnNewButton_1_2_1_1.setBackground(new Color(180, 132, 108));
		btnNewButton_1_2_1_1.setBounds(0, 246, 684, 47);
		contentPane.add(btnNewButton_1_2_1_1);
		
		JButton btnNewButton_1 = new JButton("Back");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				AdminLogWindow alw = new AdminLogWindow();
				alw.setVisible(true);
				dispose();
			}
		});
		btnNewButton_1.setFont(new Font("Nunito Medium", Font.PLAIN, 15));
		btnNewButton_1.setBackground(new Color(254, 222, 190));
		btnNewButton_1.setBounds(0, 52, 85, 27);
		contentPane.add(btnNewButton_1);
	}

}
