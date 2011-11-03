package org.kem.CustomPanel;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;


/**
 * @author KEM
 *
 */
public class CustomPanel extends JFrame implements ActionListener {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	protected String title;
	protected String []labels;
	protected String [] buttonTexts;
	protected ArrayList<JButton> listButton;
	protected ArrayList<JTextField> listField;
	protected ArrayList<JLabel> listLabel; 
	public CustomPanel(String title, String []labels, String []buttonTexts){
		super(title);
		this.title = title;
		this.labels = labels;
		this.buttonTexts = buttonTexts;		
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		listButton = new ArrayList<JButton>();
		listField = new ArrayList<JTextField>();
		listLabel = new ArrayList<JLabel>();
		loadGui();
		this.pack();
		this.setVisible(true);		
	}
	private void loadGui() {
		// TODO Auto-generated method stub
		Container content = this.getContentPane();
		content.setLayout(new BorderLayout());
		//Title label
		JPanel titlePanel = new JPanel(new FlowLayout(FlowLayout.CENTER));		
		JLabel jMainLabel = new JLabel(title);
		jMainLabel.setFont(new Font("Tahoma", Font.BOLD, 22));
		titlePanel.add(jMainLabel);
		//Fields
		JPanel fieldPanel = new JPanel(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		c.fill = GridBagConstraints.BOTH;
		c.insets = new Insets(5, 10, 5, 10);
		for (int i = 0; i < labels.length; i++) {
			
			if (i == 0){
				c.insets.top = 20;
			}
			else
			{
				c.insets.top = 5;
			}			
			c.gridx = 0; c.gridy = i;
			String label = labels[i];					
			JLabel jLabel = new JLabel(label);
			fieldPanel.add(jLabel, c);
			listLabel.add(jLabel);
			
			c.gridx = 1; c.gridy = i;
			if (label.toLowerCase().equals("password")){
				JPasswordField jPass = new JPasswordField(15);
				jPass.setEchoChar('*');							
				listField.add(jPass);
				fieldPanel.add(jPass, c);
			}
			else
			{
				JTextField jText = new JTextField(15);		
				listField.add(jText);
				fieldPanel.add(jText, c);
			}			
		}
		//Buttons
		JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
		buttonPanel.setBackground(Color.WHITE);
		JButton jButton = new JButton("Reset");		
		jButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				for (int i = 0; i < listField.size(); i++){
					listField.get(i).setText(null);
				}
			}
		});
		
		buttonPanel.add(jButton);
		for (String buttonText : buttonTexts){
			jButton = new JButton(buttonText);
			jButton.addActionListener(this);
			listButton.add(jButton);			
			buttonPanel.add(jButton);
		}
		//Add to Main content
		content.add(titlePanel, BorderLayout.NORTH);		
		content.add(fieldPanel, BorderLayout.CENTER);
		content.add(buttonPanel, BorderLayout.SOUTH);			
	}
	@Override
	public void actionPerformed(ActionEvent arg0){
		for (int i = 0; i < listButton.size(); i++) {
			if (arg0.getSource() == listButton.get(i)) {
				System.out.println(listButton.get(i).getText());
				JOptionPane.showMessageDialog(this, "Default action: You click "
						+ listButton.get(i).getText());
				if (listButton.get(i).getText().toLowerCase().equals("cancel"))
				{
					this.dispose();
				}
				break;
			}			
		}
	}

}
