package org.kem.KExplorer;

import java.awt.Component;

import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;

/**
 * @author KEM
 * 
 */
public class CellRenderer extends DefaultTreeCellRenderer {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 */
	public CellRenderer() {
		// TODO Auto-generated constructor stub
		super();
	}

	public Component getTreeCellRendererComponent(JTree tree, Object value,
			boolean selection, boolean expanded, boolean leaf, int row,
			boolean hasFocus) {
		super.getTreeCellRendererComponent(tree, value, selection, expanded,
				leaf, row, hasFocus);
		if (value instanceof TreeNode) {
			TreeNode node = (TreeNode) value;
			if (node.get_icon_type() == IconType.COMPUTER) {
				setIcon(ImageStore.store.get_icon(IconType.COMPUTER));
			} 
			else if (node.get_icon_type() == IconType.CDISK) {
				setIcon(ImageStore.store.get_icon(IconType.CDISK));
			} 
			else if (node.get_icon_type() == IconType.HDISK) {
				setIcon(ImageStore.store.get_icon(IconType.HDISK));
			} 
			else {
				setIcon(ImageStore.store.get_icon(IconType.FOLDER));
			}
		} else {
			setIcon(null);
			setText(null);
		}
		return this;
	}

}
