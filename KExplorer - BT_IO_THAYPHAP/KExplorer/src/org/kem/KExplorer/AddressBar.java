package org.kem.KExplorer;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 * 
 */

/**
 * @author KEM
 * 
 */
public class AddressBar extends JPanel implements KeyListener {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	// Controls
	String path = null;
	Image image;
	private JTextField txtAddress = new JTextField();

	public AddressBar() {
		load_gui();
		txtAddress.addKeyListener(this);
	}

	// Public Method
	public void set_path(String path) {
		this.path = path;
		if (path != null) {
			txtAddress.setText(path);			
			image = ImageStore.store.get_icon(IconType.BTN_UP).getImage();
			txtAddress.setText(path);
			updateUI();
		} else {
			image = ImageStore.store.get_icon(IconType.COMPUTER).getImage();
			txtAddress.setText("My Computer");
			updateUI();
		}
	}

	@Override
	public void paintComponent(Graphics g) {		
		g.clearRect(0, 0, this.getWidth(), this.getHeight());
		g.setColor(Color.BLACK);
		g.drawRoundRect(1, 1, this.getWidth() - 2, this.getHeight() - 2, 5, 5);
		g.setColor(Color.WHITE);
		g.drawRoundRect(2, 2, this.getWidth() - 4, this.getHeight() - 4, 5, 5);
		g.setColor(new Color(223, 229, 236));
		g.fillRoundRect(3, 3, this.getWidth() - 6, this.getHeight() - 6, 5, 5);			
		g.drawImage(image, 4, 6, this);
		txtAddress.setSize(this.getWidth() - 8 - 24, this.getHeight() - 8);
	}

	private void load_gui() {
		// AddressBar
		this.setLayout(null);
		this.setSize(300, 25);
		repaint();
		// txtAddress
		txtAddress.setLocation(24, 3);
		txtAddress.setBackground(new Color(223, 229, 236));
		txtAddress.setBorder(null);
		txtAddress.setVisible(true);
		this.add(txtAddress);
	}

	@Override
	public void keyPressed(KeyEvent e) {
		txtAddress.setEditable(true);
		if (e.getSource() == txtAddress) {
			if (e.getKeyCode() == 10) {
				String path = txtAddress.getText();
				if (path.equals("My Computer") || path.length() < 1) {
					return;
				}				
				MyObservable.monitor.open(path);
			}
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
	}

	@Override
	public void keyTyped(KeyEvent e) {
	}
}
