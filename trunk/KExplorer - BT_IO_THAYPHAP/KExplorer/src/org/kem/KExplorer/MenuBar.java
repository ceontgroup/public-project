package org.kem.KExplorer;

import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

/**
 * @author KEM
 * 
 */
public class MenuBar extends JMenuBar {

	/**
	 * 
	 */
	ArrayList<JMenuItem> listMenuItem;
	private static final long serialVersionUID = 1L;
	String[] textMenuFile = { "Open", "Properties", "Close" };
	String[] textMenuEdit = { "Cut", "Copy", "Paste", "Rename", "Delete" };
	String[] textMenuHelp = { "About" };
	ActionListener parent;

	public MenuBar(ActionListener parent) {
		this.parent = parent;
		listMenuItem = new ArrayList<JMenuItem>();
		load_gui();
	}

	private void load_gui() {
		JMenu file = new JMenu("File");
		// Menu file
		for (String s : textMenuFile) {
			JMenuItem jMenuItem = new JMenuItem(s);
			jMenuItem.addActionListener(parent);
			file.add(jMenuItem);
			listMenuItem.add(jMenuItem);
		}
		JMenu edit = new JMenu("Edit");
		// Menu Edit
		for (String s : textMenuEdit) {
			JMenuItem jMenuItem = new JMenuItem(s);
			jMenuItem.addActionListener(parent);
			edit.add(jMenuItem);
			listMenuItem.add(jMenuItem);
		}
		JMenu about = new JMenu("Help");
		// Menu Help
		for (String s : textMenuHelp) {
			JMenuItem jMenuItem = new JMenuItem(s);
			jMenuItem.addActionListener(parent);
			about.add(jMenuItem);
			listMenuItem.add(jMenuItem);
		}
		// add MenuBar
		this.add(file);
		this.add(edit);
		this.add(about);
	}

	public ArrayList<JMenuItem> get_list_item() {
		return listMenuItem;
	}
}
