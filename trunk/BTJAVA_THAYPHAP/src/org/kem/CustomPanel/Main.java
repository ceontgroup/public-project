package org.kem.CustomPanel;

import java.awt.Point;
import java.awt.event.ActionEvent;

import javax.swing.JOptionPane;

/**
 * 
 */

/**
 * @author KEM
 * 
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//Instance with override method actionPerformed
		CustomPanel loginPanel = new CustomPanel("Customer Login",
				new String[] { "User", "Password" }, new String[] { "Cancel",
						"Login" }) {
			private static final long serialVersionUID = 1L;

			@Override
			public void actionPerformed(ActionEvent arg0) {
				int i = -1;
				i++;
				if (arg0.getSource().equals(listButton.get(i))) {
					JOptionPane.showMessageDialog(this, "Overrided action: You click "
							+ listButton.get(i).getText());
					this.dispose();
				}
				i++;
				if (arg0.getSource().equals(listButton.get(i))) {
					JOptionPane.showMessageDialog(this, "Overrided action: You click "
							+ listButton.get(i).getText());
				}
			}
		};
		loginPanel.setLocation(new Point(100, 100));
		// Instance with method actionPerformed default
		CustomPanel registartionPanel = new CustomPanel(
				"Customer Registration", new String[] { "User", "Password",
						"Address", "Email", "Phone" }, new String[] { "Return",
						"Submit" });
		registartionPanel.setLocation(new Point(450, 100));
		// Instance with method actionPerformed default		
		CustomPanel configurationPanel = new CustomPanel(
				"Configuration", new String[] { "Driver", "Database URL",
						"Username", "Password"}, new String[] { "Return",
						"Submit"});
		configurationPanel.setLocation(new Point(100, 300));
	}
	

}
