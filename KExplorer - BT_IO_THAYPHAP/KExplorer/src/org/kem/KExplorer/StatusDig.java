/**
 * 
 */
package org.kem.KExplorer;


import java.awt.Color;
import java.awt.Component;
import java.awt.Container;

import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JProgressBar;

/**
 * @author KEM
 *
 */
public class StatusDig extends JDialog{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JProgressBar prog = new JProgressBar(0, 100);
	ImageIcon iconCopy = ImageStore.store.get_icon(IconType.DLG_COPY);
	ImageIcon iconDel = ImageStore.store.get_icon(IconType.DLG_DELETE);
	JPanel panel;
	Container content;
	JLabel labelCopy;
	JLabel labelDel;
	public StatusDig(JFrame parent) {
		super(parent, "Processing...");
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		content = this.getContentPane();
		content.setLayout(null);
		labelCopy = new JLabel(iconCopy);
		labelDel = new JLabel(iconDel);
		panel = new JPanel();		
		prog.setEnabled(true);
		prog.setValue(0);
		prog.setStringPainted(true);		
		this.setResizable(false);		
		this.setVisible(false);		
		load_gui_cut();
		load_gui_del();
		load_gui_copy();		
	}
	public void load_gui_del() {
		content.removeAll();
		this.setTitle("Deleting...");			
		content.add(prog);
		content.add(labelCopy);		
		labelDel.setBounds(0, -50, 444, 175);
		prog.setBounds(10, 90, 420, 30);		
		this.setSize(444, 170);
		set_location();
	}
	public void load_gui_cut() {
		content.removeAll();
		this.setTitle("Moving...");
		panel.setBounds(0, 105, 444, 40);
		panel.setBackground(new Color(210, 210, 210));
		content.add(prog);
		content.add(panel);
		content.add(labelDel);		
		labelCopy.setBounds(-2, -20, 444, 175);
		prog.setBounds(10, 80, 420, 30);		
		this.setSize(444, 170);	
		set_location();
	}
	public void set_value(int n){
		prog.setValue(n);
		if (n != 0)
			prog.setString(String.valueOf(n)+ "%");
		else
			prog.setString("Calculating...");
	}
	public void load_gui_copy(){
		content.removeAll();
		this.setTitle("Copying...");
		panel.setBounds(0, 105, 444, 40);
		panel.setBackground(new Color(210, 210, 210));
		content.add(prog);
		content.add(panel);
		content.add(labelDel);	
		labelCopy.setBounds(-2, -20, 444, 175);
		prog.setBounds(10, 80, 420, 30);		
		this.setSize(444, 170);
		set_location();
	}
	public void set_location() {		
		Component[] windows = getWindows();
		if (windows != null){
			for (Component window : windows){
				if (window instanceof KExplorer){
					int x = ( window.getWidth() - 444 ) / 2;
					int y = ( window.getHeight() - 170 ) / 2;
					this.setLocation(x, y);
				}
				break;
			}
		}		
	}
}
