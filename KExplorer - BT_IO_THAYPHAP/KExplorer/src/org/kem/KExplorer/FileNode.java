package org.kem.KExplorer;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 * @author KEM
 * 
 */
public class FileNode extends JPanel implements MouseListener, ActionListener,
		KeyListener {

	/**
	 * 
	 */	
	private static final long serialVersionUID = 1L;		
	/**
	 * 
	 */
	KPopupMenu popupMenu;
	JLabel name;
	JTextField rename;
	JLabel icon;	
	File file;	
	static boolean allowAction = false;
	static FileNode selected = null;			
	public FileNode(String n, IconType type, String path) {
		super(new BorderLayout());		
		allowAction = false;
		this.addMouseListener(this);
		if (path == null){
			file = null;
			icon = new JLabel(ImageStore.store.get_icon(type), JLabel.CENTER);			
		}		
		else{
			file = new File(path);			
			icon = new JLabel(ImageStore.store.get_icon(type), JLabel.CENTER);			
		}
		name = new JLabel(n, JLabel.CENTER);
		rename = new JTextField(n);
		rename.setVisible(false);
		rename.addKeyListener(this);
		this.add(icon, BorderLayout.NORTH);
		this.add(rename, BorderLayout.SOUTH);
		this.add(name, BorderLayout.CENTER);
		popupMenu = new KPopupMenu(this);
		this.addMouseListener(popupMenu);
		popupMenu.add("Open");
		popupMenu.add("Search...");
		popupMenu.add("");
		popupMenu.add("Copy");
		popupMenu.add("Cut");
		popupMenu.add("Delete");
		if (file.isDirectory())
			popupMenu.add("Paste");
		popupMenu.add("Rename");
		popupMenu.add("");
		popupMenu.add("Properties");
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		if (e.getClickCount() == 2) {
			if (this.IsDirectory() == true)
				MyObservable.monitor.open(this.get_path());
		}
	}

	@Override
	public void mouseEntered(MouseEvent e) {
	}

	@Override
	public void mouseExited(MouseEvent e) {
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		if (selected != null) {
			selected.setBackground(null);
			selected.rename.setVisible(false);
			selected.name.setVisible(true);
		}
		allowAction = true;
		selected = this;
		selected.setBackground(Color.gray);
		System.out.println("Node: " + selected.get_path());		

	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	public static FileNode get_selected() {
		if (allowAction)
			return selected;
		else
			return null;
	}

	public boolean IsDirectory() {
		if (file != null)
			return file.isDirectory();
		return false;
	}

	public String get_path() {
		if (file == null)
			return null;
		return file.getAbsolutePath();
	}
	public File get_file() {
		return file;
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("Open")) {
			if (IsDirectory()) {
				MyObservable.monitor.open(get_path());
			} else {
				// Open file
			}
		} else if (e.getActionCommand().equals("Delete")) {
			MyObservable.monitor.delete(get_path());
		} else if (e.getActionCommand().equals("Rename")) {
			MyObservable.monitor.rename(this);
		} else if (e.getActionCommand().equals("Copy")) {
			MyObservable.monitor.copy(this.get_path());
		} else if (e.getActionCommand().equals("Cut")) {
			MyObservable.monitor.cut(this.get_path());
		} else if (e.getActionCommand().equals("Paste")) {
			if (IsDirectory())
				MyObservable.monitor.paste(this.get_path());
		} else if (e.getActionCommand().equals("Properties")) {
			if (IsDirectory()) {
				JOptionPane.showMessageDialog(null, "Type: Folder \n Path: "
						+ get_path());
			} else {
				JOptionPane.showMessageDialog(null, "Type: File\n Path: "
						+ get_path());
			}
		} else {
			String msg = "Under construction, please come back soon :)\n";
			msg += "^^ KEM ^^";
			JOptionPane.showMessageDialog(this, msg);
		}
	}

	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == rename) {
			if (e.getKeyCode() == 10) {
				System.out.println(file.getParent());								
				if (file.getParent() == null) {
					JOptionPane.showMessageDialog(null,
							"Not support rename a disk driver !");
					return;
				}				
				File file2 = new File(file.getParent(), rename.getText());
				if (file.renameTo(file2)) {
					if (IsDirectory())
						MyObservable.monitor.update_tree();
					MyObservable.monitor.update(file.getParent());
				} else {
					JOptionPane.showMessageDialog(null, "Rename fail !");
				}
			}
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub

	}
}
