/**
 * 
 */
package org.kem.PuzzleGame;

import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.border.BevelBorder;

/**
 * @author KEM
 *
 */
public class MenuBar extends JMenuBar{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;	
	String []listMenuGame;
	String []listMenuHelp;
	ArrayList<JMenuItem> listMenuItem;
	ActionListener parent;
	public MenuBar(ActionListener parent){
		this.parent = parent;	
		listMenuItem = new ArrayList<JMenuItem>();
		listMenuGame = new String[]{"New game", "Save game", "Load game", "Change color", "Exit game"};
		listMenuHelp = new String[]{"About game", "How to play"};
		loadMenu();
		this.setBorder(new BevelBorder(BevelBorder.RAISED));
	}
	private void loadMenu() {
		// TODO Auto-generated method stub
		JMenuItem jMenuItem;
		JMenu menuGame = new JMenu("Game");		
		//Add MenuItem for Menu Game
		for (String s : listMenuGame){
			jMenuItem = new JMenuItem(s);
			jMenuItem.addActionListener(parent);
			menuGame.add(jMenuItem);
			listMenuItem.add(jMenuItem);
		}		
		//Add menuGame into MenuBar
		this.add(menuGame);
		//Menu Help
		JMenu menuHelp = new JMenu("Help");
		//Add MenuItem for Menu Help
		for (String s : listMenuHelp){
			jMenuItem = new JMenuItem(s);
			jMenuItem.addActionListener(parent);
			menuHelp.add(jMenuItem);
			listMenuItem.add(jMenuItem);
		}		
		this.add(menuHelp);							
	}
	public ArrayList<JMenuItem> getMenuItems() {
		return this.listMenuItem;		
	}

}
