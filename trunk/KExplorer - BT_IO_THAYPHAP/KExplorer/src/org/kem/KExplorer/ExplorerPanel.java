package org.kem.KExplorer;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * @author KEM
 * 
 */
public class ExplorerPanel extends JPanel implements ActionListener, Observer {

	/**
	 * 
	 */
	int maxWidth = 500;
	int cellWidth = 90, cellHeight = 90;
	int maxCol = maxWidth / cellHeight;	
	File file = null;
	String typeShow = null;
	ArrayList<FileNode> listFolder = new ArrayList<FileNode>();
	ArrayList<FileNode> listFile = new ArrayList<FileNode>();
	ArrayList<FileNode> listNew = new ArrayList<FileNode>();
	private static final long serialVersionUID = 1L;
	KPopupMenu popupMenu;

	public ExplorerPanel() {
		super();
		file = null;
		this.setLayout(null);
		popupMenu = new KPopupMenu(this);
		this.addMouseListener(popupMenu);
		popupMenu.add("View", new String[] { "Thumbnails", "Tiles", "Icons",
				"List", "Details" });
		popupMenu.add("");
		popupMenu.add("Paste");
		popupMenu.add("New file");
		popupMenu.add("New folder");
		popupMenu.add("");
		popupMenu.add("Properties");
		MyObservable.monitor.addObserver(this);
	}
	public File get_file() {
		return file;
	}
	private void add_list_item() {
		super.updateUI();
		int col = 0, row = 0;
		this.removeAll();
		if (typeShow.equals("")) {
			maxCol = maxWidth / cellWidth;
			if (maxCol < 1) {
				maxCol = 1;
			}
			if (!listFolder.isEmpty())
				for (FileNode node : listFolder) {
					super.add(node);
					node.setLocation(10 + cellWidth * col, 10 + cellHeight
							* row);
					node.setSize(new Dimension(cellWidth - 10, cellHeight - 10));
					col++;
					if (col >= maxCol) {
						col = 0;
						row++;
					}
				}
			if (!listFile.isEmpty())
				for (FileNode node : listFile) {
					node.setLocation(10 + cellWidth * col, 10 + cellHeight
							* row);
					node.setSize(new Dimension(cellWidth - 10, cellHeight - 10));
					super.add(node);
					col++;
					if (col >= maxCol) {
						col = 0;
						row++;
					}
				}
			if (!listNew.isEmpty())
				for (FileNode node : listNew) {
					node.setLocation(10 + cellWidth * col, 10 + cellHeight
							* row);
					node.setSize(new Dimension(cellWidth - 10, cellHeight - 10));
					super.add(node);
					col++;
					if (col >= maxCol) {
						col = 0;
						row++;
					}
				}
		}
		this.setPreferredSize(new Dimension(col * cellWidth + 40, row
				* cellHeight + 180));
		super.updateUI();
	}

	private void dir_driver() {
		reset_list();
		File[] roots = File.listRoots();
		for (int index = 0; index < roots.length; index++) {
			String name = new String(roots[index].getAbsolutePath());
			// Print out each drive/partition			
			String partitionName = KExplorer.get_display_name(name);
			if (partitionName.indexOf("CD") >= 0) {				
				FileNode child = new FileNode(partitionName, IconType.CDISK2,
						name);
				listFolder.add(child);
			} else {
				FileNode child = new FileNode(partitionName, IconType.HDISK2,
						name);
				listFolder.add(child);
			}
		}
	}
	public void show_path(String path) {
		show_path(path, getWidth());
	}
	public void show_path(String path, int width) {
		if (path != null) {
			file = new File(path);
		}		
		else
			file = null;
		maxWidth = width;
		typeShow = "";
		if (file != null) {
			dir();
		} else {
			dir_driver();
		}
		add_list_item();
	}

	private void reset_list() {
		if (!listFile.isEmpty()) {
			listFile.clear();
		}
		if (!listFolder.isEmpty()) {
			listFolder.clear();
		}
		if (!listNew.isEmpty()) {
			listNew.clear();
		}
	}

	private void dir() {
		reset_list();		
		String[] listName = file.list();
		if (listName != null) {
			for (String name : listName) {
				File fi = new File(file, name);
				if (fi.isDirectory()) {
					FileNode child = new FileNode(name, IconType.FOLDER2, fi.getAbsolutePath());					
					listFolder.add(child);
				} else {
					FileNode child = new FileNode(name, IconType.FILE, fi.getAbsolutePath());
					// System.out.println(child.getPath());
					listFile.add(child);
				}
			}
		}
	}

	public String get_path() {		
		if (file == null)
			return null;
		return file.getAbsolutePath();
	}

	public void update_show(int width) {
		maxWidth = width;
		add_list_item();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println("class ExplorerPanle: actionPerformed "
				+ e.getActionCommand());
		if (e.getActionCommand().equals("New folder")) {
			MyObservable.monitor.new_folder(this.get_path());
		} else if (e.getActionCommand().equals("New file")) {
			MyObservable.monitor.new_file(this.get_path());
		} else if (e.getActionCommand().equals("Properties")) {
			if (this.get_path() == null) {
				JOptionPane.showMessageDialog(null, "Location: My Computer");
			} else {
				JOptionPane.showMessageDialog(null, "Location: " + get_path());
			}
		} else if (e.getActionCommand().equals("Paste")) {
			if (get_path() == null) {
				JOptionPane.showMessageDialog(null, "Can't paste here !");
			} else {
				MyObservable.monitor.paste(this.get_path());
			}
		} else {
			String msg = "Under construction, please come back soon :)\n";
			msg += "^^ KEM ^^";
			JOptionPane.showMessageDialog(this, msg);
		}
	}

	@Override
	public void update(Observable arg0, Object arg1) {
		if (arg1 instanceof FileAction) {
			FileAction action = (FileAction) arg1;
			if (action.get_type() == FileActionType.ACT_NEW_FOLDER) {				
				if (action.get_action_path() == null) {
					JOptionPane.showMessageDialog(null,
							"You can't make folder this place.");
					return;
				}
				File file = new File(action.get_action_path());
				if (!file.canWrite()) {
					JOptionPane.showMessageDialog(null,
							"You can't make folder this place.");
					return;
				}
				int i;
				for (i = 0; i < 10000; i++) {
					if (!new File(action.get_action_path(), "NewFolder" + i)
							.exists()) {
						file = new File(action.get_action_path(), "NewFolder"
								+ i);
						if (file.mkdir()) {
							System.out.println("Make new folder ");							
							break;
						}
					}
				}
				FileNode child = new FileNode("NewFolder" + i,
						IconType.FOLDER2, file.getAbsolutePath());
				listNew.add(child);
				update_show(this.maxWidth);
				child.name.setVisible(false);
				child.rename.setVisible(true);
			} 
			else if (action.get_type() == FileActionType.ACT_NEW_FILE) {				
				if (action.get_action_path() == null) {
					JOptionPane.showMessageDialog(null,
							"You can't make file this place.");
					return;
				}
				File file = new File(action.get_action_path());
				if (!file.canWrite()) {
					JOptionPane.showMessageDialog(null,
							"You can't make file this place.");
					return;
				}
				int i;
				for (i = 0; i < 10000; i++) {
					if (!new File(action.get_action_path(), "NewFile" + i).exists()) {
						file = new File(action.get_action_path(), "NewFile" + i);
						try {
							if (file.createNewFile()) {
								System.out.println("Make new file ");								
								break;
							}
						} catch (IOException e) {
						}
					}
				}
				FileNode child = new FileNode("NewFile" + i, IconType.FILE, file.getAbsolutePath());
				listNew.add(child);
				update_show(this.maxWidth);
				child.name.setVisible(false);
				child.rename.setVisible(true);
			}
		}
	}

}
