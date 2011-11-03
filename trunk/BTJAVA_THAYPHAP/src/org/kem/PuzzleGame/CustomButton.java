/**
 * 
 */
package org.kem.PuzzleGame;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;

import javax.swing.JButton;

/**
 * @author KEM
 *
 */
public class CustomButton extends JButton{

	/**
	 * 
	 */
	Color fColor, tColor;
	String title;
	private static final long serialVersionUID = 1L;
	public CustomButton(Color f, Color t){		
		this.fColor = f;
		this.tColor = t;
		this.title = "Start";
		this.setToolTipText("Click here to begin play game !");
		this.setActionCommand("Start game");
	}
	@Override
	public void repaint() {
		// TODO Auto-generated method stub
		super.repaint();
	}
	@Override	
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);
		Dimension size = new Dimension(50, 30);
	    setPreferredSize(size);	   
	    setBorder(null);	    
	    setContentAreaFilled(false);	
	    setCursor(new Cursor(Cursor.HAND_CURSOR));
	    g.setColor(fColor);
	    g.fillOval(0, 0, 50, 30);    
	    g.setColor(tColor);
	    g.setFont(new Font("Tahoma", Font.BOLD, 12));
	    g.drawChars(title.toCharArray(), 0, title.length(), 12, 18);
	}
	public void setTitle(String s){
		this.title = s;
	}
	public String getTitle(){
		return this.title;
	}
}
