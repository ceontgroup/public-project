/**
 * 
 */
package org.kem.KExplorer;

import java.awt.Component;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;

/**
 * @author KEM
 * 
 */
public class KPopupMenu extends JPopupMenu implements MouseListener {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 */
	ArrayList<JMenuItem> listMenu = new ArrayList<JMenuItem>();
	Component parent = null;
	ActionListener listener = null;

	public KPopupMenu(Component parent) {
		super();
		this.parent = parent;
		try {
			this.listener = (ActionListener) parent;
		} catch (Exception e) {
		}
	}

	public void add(String m, String[] ss) {
		JMenu menu = new JMenu(m);
		for (String s : ss) {
			if (s.equals("")) {
				menu.addSeparator();
			} else {
				JMenuItem item = new JMenuItem(s);
				menu.add(item);
				item.addActionListener(listener);
				item.setActionCommand(s);
				listMenu.add(item);
			}
		}
		this.add(menu);
	}

	@Override
	public JMenuItem add(String s) {
		JMenuItem item = null;
		if (s.equals("")) {
			this.addSeparator();
		} else {
			item = new JMenuItem(s);
			item.addActionListener(listener);
			item.setActionCommand(s);
			listMenu.add(item);
			this.add(item);
		}
		return item;
	}

	public ArrayList<JMenuItem> get_list_action() {
		return listMenu;
	}

	@Override
	public void mouseClicked(MouseEvent e) {
	}

	@Override
	public void mouseEntered(MouseEvent e) {
	}

	@Override
	public void mouseExited(MouseEvent e) {
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		if (e.getButton() == MouseEvent.BUTTON3) {
			if (!this.isShowing())
				super.show(parent, e.getX(), e.getY());
		}
	}

	@Override
	public void mousePressed(MouseEvent e) {
	}
}
