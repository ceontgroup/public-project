package org.kem.PuzzleGame;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Insets;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;


public class Help extends JDialog{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static String[] dest = {"1", "2", "3", "8", ".", "4", "7", "6", "5"};
	JFrame parent;	
	public Help(JFrame parent) {
		// TODO Auto-generated constructor stub		
		super(parent, "Game help");
		this.parent = parent;		
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		loadGui();
		if (parent != null)
		this.setLocation(parent.getLocation());
		this.setResizable(false);
		this.setModal(true) ;
		this.pack();		
		this.setVisible(true);
	}
	private void loadGui() {
		// TODO Auto-generated method stub
		Container contenPanel = this.getContentPane();
		contenPanel.setLayout(new BorderLayout());		
		JPanel left = new JPanel(new GridLayout(3, 3));
		for (int i = 0; i < 9; i++)
		{
			JButton jb;
			jb = new JButton(dest[i]);
			jb.setBackground(new Color(0, 255, 0));
			jb.setForeground(new Color(102, 102, 102));
			jb.setFont(new Font(null, Font.BOLD, 38));
			left.add(jb);						
		}
		
		JPanel right = new JPanel();
		JTextArea text = new JTextArea();
		text.setFont(new Font("Tahoma", 0, 14));
		text.setMargin(new Insets(5, 5, 5, 5));
		text.setEditable(false);		
		try {							
			InputStream inp = this.getClass().getResourceAsStream("/res/help.txt");
			BufferedReader bf = new BufferedReader(new InputStreamReader(inp));			
			String sb = null;
			do
			{
				sb = bf.readLine();
				if (sb != null) 
					sb += "\n";
				text.append(sb);
			}while (sb != null);
			bf.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("File not found !");
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		right.add(text);
		
		//add Content
		contenPanel.add(left, BorderLayout.WEST);		
		contenPanel.add(right, BorderLayout.EAST);
	}
}
