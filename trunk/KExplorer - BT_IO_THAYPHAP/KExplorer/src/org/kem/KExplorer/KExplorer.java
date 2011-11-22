package org.kem.KExplorer;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.io.File;
import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;
import java.util.Stack;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JToolBar;
import javax.swing.JTree;
import javax.swing.event.TreeExpansionEvent;
import javax.swing.event.TreeExpansionListener;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.filechooser.FileSystemView;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.MutableTreeNode;
import javax.swing.tree.TreePath;

/**
 * @author KEM
 * 
 */
public class KExplorer extends JFrame implements ActionListener,
		TreeExpansionListener, TreeSelectionListener, ComponentListener,
		Observer {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	MenuBar menu;
	JTree tree;
	TreeNode treeTop;
	DefaultTreeModel treeMode;
	ExplorerPanel explorerPanel;
	JScrollPane explorerScroll;
	JToolBar toolbar;
	JButton btnUp, btnForward, btnBack, btnView;
	AddressBar addressBar;
	ImageIcon icon;
	Stack<String> historyBack = new Stack<String>();
	Stack<String> historyForward = new Stack<String>();

	public static void main(String[] args) {
		new KExplorer();
	}

	public KExplorer() {
		super("KExplorer");
		load_gui();
		this.setSize(500, 500);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setVisible(true);
	}

	private void load_gui() {
		// Add menubar
		menu = new MenuBar(this);
		this.setJMenuBar(menu);
		// set Layout manager for ContainPanel
		Container content = this.getContentPane();
		content.setLayout(new BorderLayout());
		// Adressbar
		addressBar = new AddressBar();
		// Right panel
		explorerPanel = new ExplorerPanel();
		explorerScroll = new JScrollPane(explorerPanel);
		explorerScroll.setAutoscrolls(true);
		explorerScroll.addComponentListener(this);
		// Tree
		treeTop = new TreeNode("My Computer", IconType.COMPUTER);
		init_top(treeTop);
		treeMode = new DefaultTreeModel(treeTop);
		tree = new JTree(treeMode);
		CellRenderer cellRenderer = new CellRenderer();
		tree.setCellRenderer(cellRenderer);
		tree.addTreeExpansionListener(this);
		tree.addTreeSelectionListener(this);
		// ScrollPanel
		JScrollPane treeScroll = new JScrollPane(tree);
		treeScroll.setPreferredSize(new Dimension(150, 500));
		// JSplit
		JSplitPane splitContent = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
				treeScroll, explorerScroll);
		// Toolbar
		toolbar = new JToolBar("Address", JToolBar.CENTER);
		toolbar.setFloatable(false);
		icon = ImageStore.store.get_icon(IconType.BTN_UP);		
		btnUp = new JButton(icon);
		btnUp.addActionListener(this);
		icon = ImageStore.store.get_icon(IconType.BTN_FORWARD);
		btnForward = new JButton(icon);
		btnForward.addActionListener(this);
		icon = ImageStore.store.get_icon(IconType.BTN_BACK);
		btnBack = new JButton(icon);
		btnBack.addActionListener(this);
		icon = ImageStore.store.get_icon(IconType.BTN_VIEW);
		btnView = new JButton(icon);
		// btnUp.setPreferredSize(new Dimension(30, 30));
		toolbar.add(btnBack);
		toolbar.add(btnForward);
		toolbar.add(btnUp);
		toolbar.add(btnView);
		toolbar.add(addressBar);
		btnBack.setEnabled(false);
		btnForward.setEnabled(false);
		btnUp.setEnabled(false);
		btnView.setEnabled(false);
		content.add(toolbar, BorderLayout.PAGE_START);
		content.add(splitContent, BorderLayout.CENTER);
		MyObservable.monitor.addObserver(this);
	}

	private void init_top(TreeNode top) {
		File[] roots = File.listRoots();
		TreeNode partition;
		for (int index = 0; index < roots.length; index++) {
			String name = new String(roots[index].getPath());
			// Print out each drive/partition
			System.out.println(name);
			String partitionName = get_display_name(name);
			if (partitionName.indexOf("CD") >= 0) {
				partition = new TreeNode(partitionName, IconType.CDISK);
			} else {
				partition = new TreeNode(partitionName, IconType.HDISK);
			}
			partition.set_path(name);
			if (has_sub_dir(partition)) {
				partition.add(new DefaultMutableTreeNode());
			}
			top.add(partition);
		}
		explorerPanel.show_path(top.get_path(), (int) explorerPanel
				.getPreferredSize().getWidth());
		addressBar.set_path(top.get_path());
		top.set_state(true);
	}

	private boolean has_sub_dir(TreeNode node) {
		File file;
		file = new File(node.get_path());
		String[] names = file.list();
		if (names != null)
			for (String s : names) {
				file = new File(node.get_path() + s);
				if (file.isDirectory())
					return true;
			}
		return false;
	}

	public static String get_display_name(String absolutePath) {
		FileSystemView view = FileSystemView.getFileSystemView();
		File dir = new File(absolutePath);
		String name = view.getSystemDisplayName(dir);
		name.trim();
		int index = 0;
		if (name.length() < 1) {
			name = view.getSystemTypeDescription(dir);
		} else {
			index = name.indexOf("(");
			name = name.substring(0, index);
		}
		return name.trim();
	}

	@Override
	public void treeCollapsed(TreeExpansionEvent arg0) {
		System.out.println("treeCollapsed");
	}

	@Override
	public void treeExpanded(TreeExpansionEvent arg0) {
		System.out.println("treeExpanded");
		TreePath parent = arg0.getPath();
		TreeNode node = (TreeNode) parent.getLastPathComponent();
		if (!node.get_ready()) {
			get_dir(node);
		}
	}

	private void get_dir(TreeNode node) {
		File file;
		file = new File(node.get_path());
		String[] names = file.list();
		if (names != null)
			for (String s : names) {
				file = new File(node.get_path() + s);
				if (file.isDirectory()) {
					TreeNode child = new TreeNode(s, IconType.FOLDER2);
					child.set_path(node.get_path() + s + "\\");
					System.out.println(child.get_path());
					if (has_sub_dir(child)) {
						child.add(new DefaultMutableTreeNode());
					}
					treeMode.insertNodeInto(child, node, node.getChildCount());
				}

			}
		treeMode.removeNodeFromParent((MutableTreeNode) node.getFirstChild());
		node.set_state(true);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		ArrayList<JMenuItem> listMenu = menu.get_list_item();
		if (e.getSource() == btnUp) {					
			if (explorerPanel.get_path().length() > 3)
				MyObservable.monitor.open(explorerPanel.file.getParent());
			else{
				MyObservable.monitor.open(null);
			}
			System.out.println(explorerPanel.get_path() );
			if (explorerPanel.get_path() == null) {
				btnUp.setEnabled(false);
			} else
				btnUp.setEnabled(true);
		}
		if (e.getSource() == btnBack) {						
			if (historyForward.size() > 20) {
				historyForward.pop();
			}
			String path = explorerPanel.get_path();
			historyForward.push(path);
			MyObservable.monitor.update(historyBack.pop());
			System.out.println("Back: " + path);
			if (historyBack.size() > 0) {
				btnBack.setEnabled(true);
			} else {
				btnBack.setEnabled(false);
			}
			if (historyForward.size() > 0) {
				btnForward.setEnabled(true);
			} else {
				btnForward.setEnabled(false);
			}
			if (explorerPanel.get_path() != null){
				btnUp.setEnabled(true);
			}
			else
				btnUp.setEnabled(false);
		}
		if (e.getSource() == btnForward) {					
			if (historyBack.size() > 20) {
				historyBack.pop();
			}
			String path = historyForward.pop();
			historyBack.push(explorerPanel.get_path());
			MyObservable.monitor.update(path);
			System.out.println("Forward: " + path);
			if (historyBack.size() > 0) {
				btnBack.setEnabled(true);
			} else {
				btnBack.setEnabled(false);
			}
			if (historyForward.size() > 0) {
				btnForward.setEnabled(true);
			} else {
				btnForward.setEnabled(false);
			}
			if (explorerPanel.get_path() != null){
				btnUp.setEnabled(true);
			}
			else
				btnUp.setEnabled(false);
		}
		for (JMenuItem menuItem : listMenu) {
			if (e.getSource() == menuItem) {
				if (menuItem.getActionCommand().equals("Close")) {
					System.out.println("actionPerformed: "
							+ e.getActionCommand());
					System.exit(ABORT);
				} else if (menuItem.getActionCommand().equals("About")) {
					ImageIcon icon = ImageStore.store.get_icon(IconType.KEM);
					String msg = "KExplorer - Version 1.1\n";								
					//msg += "Written by Kem \n";
					msg += "Le Sua - 08T1 - IT Faculty - Danang University of Technology\n";
					msg += "E-Mail: sualbk@gmail.com";
					JOptionPane.showMessageDialog(this, msg, "About KExplorer",
							1, icon);
				} else if (menuItem.getActionCommand().equals("Rename")) {
					FileNode file = FileNode.get_selected();
					if (file != null) {
						MyObservable.monitor.rename(file);
					}
				} else if (menuItem.getActionCommand().equals("Open")) {
					FileNode file = FileNode.get_selected();
					if (file != null) {
						if (file.IsDirectory()) {
							MyObservable.monitor.open(file.get_path());
						} else {
							// Open file
						}
					}

				} else if (menuItem.getActionCommand().equals("Delete")) {
					FileNode file = FileNode.get_selected();
					if (file != null) {
						MyObservable.monitor.delete(file.get_path());
					}
				} else if (menuItem.getActionCommand().equals("Copy")) {
					FileNode file = FileNode.get_selected();
					if (file != null) {
						MyObservable.monitor.copy(file.get_path());
					}
				} else if (menuItem.getActionCommand().equals("Cut")) {
					FileNode file = FileNode.get_selected();
					if (file != null) {
						MyObservable.monitor.cut(file.get_path());
					}
				} else if (menuItem.getActionCommand().equals("Paste")) {
					FileNode file = FileNode.get_selected();
					if (file != null) {
						if (explorerPanel.get_path() == null) {
							JOptionPane.showMessageDialog(null,
									"Can't paste here !");
						} else
							MyObservable.monitor.paste(explorerPanel
									.get_path());
					}
				} else if (menuItem.getActionCommand().equals("Properties")) {
					FileNode file = FileNode.get_selected();
					if (file != null) {
						if (file.IsDirectory()) {
							JOptionPane.showMessageDialog(null,
									"Type: Folder \n Path: " + file.get_path());
						} else {
							JOptionPane.showMessageDialog(null,
									"Type: File\n Path: " + file.get_path());
						}
					}
				} else {
					String msg = "Under construction, please come back soon :)\n";
					msg += "^^ KEM ^^";
					JOptionPane.showMessageDialog(this, msg);
				}
				break;
			}
		}
	}

	@Override
	public void valueChanged(TreeSelectionEvent arg0) {

		TreePath parent = arg0.getPath();
		System.out.println("Path: " + parent);
		TreeNode node = (TreeNode) parent.getLastPathComponent();
		System.out.println(node.get_path());
		MyObservable.monitor.open(node.get_path());
	}

	@Override
	public void componentResized(ComponentEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == explorerScroll) {
			int width = explorerScroll.getWidth();
			explorerPanel.update_show(width);
			int height = (int) explorerPanel.getPreferredSize().getHeight();
			width = (int) explorerPanel.getPreferredSize().getWidth();
			explorerScroll.getVerticalScrollBar().setValue(height);
			explorerScroll.getHorizontalScrollBar().setValue(100);
			System.out.println("valueChanged "
					+ explorerPanel.getPreferredSize().getHeight() + " - "
					+ width);
		}
	}

	@Override
	public void componentHidden(ComponentEvent e) {
	}

	@Override
	public void componentMoved(ComponentEvent e) {
	}

	@Override
	public void componentShown(ComponentEvent e) {
	}

	@Override
	public void update(Observable arg0, Object arg1) {
		if (arg1 instanceof FileAction) {
			FileAction action = (FileAction) arg1;
			if (action.get_type() == FileActionType.ACT_UPDATE) {
				{
					explorerPanel.show_path(action.get_action_path(),
							explorerScroll.getWidth());
					addressBar.set_path(action.get_action_path());
				}
			}
			if (action.get_type() == FileActionType.ACT_OPEN) {
				if (historyBack.size() > 20) {
					historyBack.pop();
				}
				historyBack.push(explorerPanel.get_path());// push into
																	// history
				if (historyBack.size() > 0) {
					btnBack.setEnabled(true);
				} else {
					btnBack.setEnabled(false);
				}
				if (historyForward.size() > 0) {
					btnForward.setEnabled(true);
				} else {
					btnForward.setEnabled(false);
				}
				explorerPanel.show_path(action.get_action_path(),
						explorerScroll.getWidth());
				addressBar.set_path(action.get_action_path());
				System.out.println(explorerPanel.get_path() );
				if (explorerPanel.get_path() == null) {
					btnUp.setEnabled(false);
				} else
					btnUp.setEnabled(true);
			}
		} 
		else if (arg1 instanceof String) {

		}
		else {
			//Default is update tree
			while (treeTop.getChildCount() > 0)
				treeMode.removeNodeFromParent((MutableTreeNode) treeTop
						.getLastChild());
			init_top(treeTop);
			treeMode.reload();
		}
	}
}
