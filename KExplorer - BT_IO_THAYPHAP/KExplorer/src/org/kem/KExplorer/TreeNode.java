package org.kem.KExplorer;

import javax.swing.tree.DefaultMutableTreeNode;

/**
 * @author KEM
 * 
 */
public class TreeNode extends DefaultMutableTreeNode {

	/**
	 * 
	 */
	boolean state = false;
	IconType iconType;
	String path = null;
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 */
	public TreeNode(Object userObject) {
		super(userObject);
	}

	public TreeNode(Object userObject, IconType type) {
		super(userObject);
		iconType = type;
	}

	public IconType get_icon_type() {
		return iconType;
	}

	public void set_icon_type(IconType type) {
		iconType = type;
	}

	public boolean get_ready() {
		return state;
	}

	public void set_state(boolean s) {
		state = s;
	}

	public void set_path(String s) {
		path = s;
	}

	public String get_path() {
		return path;
	}
}
