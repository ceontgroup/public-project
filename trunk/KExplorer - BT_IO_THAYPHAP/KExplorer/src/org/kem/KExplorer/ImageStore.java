/**
 * 
 */
package org.kem.KExplorer;

import java.util.HashMap;

import javax.swing.ImageIcon;

/**
 * @author KEM
 * 
 */
public class ImageStore {
	public static ImageStore store = new ImageStore();
	private HashMap<IconType, ImageIcon> lists = new HashMap<IconType, ImageIcon>();

	public ImageStore() {
		this.push(IconType.CDISK2,
				new ImageIcon(this.getClass().getResource("/res/cdisk2.png")));
		this.push(IconType.HDISK2,
				new ImageIcon(this.getClass().getResource("/res/hdisk2.png")));
		this.push(IconType.FOLDER2,
				new ImageIcon(this.getClass().getResource("/res/folder2.png")));
		this.push(IconType.FILE,
				new ImageIcon(this.getClass().getResource("/res/system.png")));
		this.push(IconType.BTN_FORWARD, 
				new ImageIcon(this.getClass().getResource("/res/forward.png")));
		this.push(IconType.BTN_UP,
				new ImageIcon(this.getClass().getResource("/res/up.png")));
		this.push(IconType.BTN_BACK,
				new ImageIcon(this.getClass().getResource("/res/back.png")));
		this.push(IconType.BTN_VIEW,
				new ImageIcon(this.getClass().getResource("/res/view.png")));
		this.push(IconType.KEM,
				new ImageIcon(this.getClass().getResource("/res/owner.jpg")));	
		this.push(IconType.COMPUTER,
				new ImageIcon(getClass().getResource("/res/computer.png")));
		this.push(IconType.CDISK,
				new ImageIcon(getClass().getResource("/res/cdisk.png")));
		this.push(IconType.HDISK,
				new ImageIcon(getClass().getResource("/res/hdisk.png")));
		this.push(IconType.FOLDER,
				new ImageIcon(getClass().getResource("/res/folder.png")));
		this.push(IconType.DLG_COPY, new ImageIcon(getClass().getResource("/res/copying.gif")));
		this.push(IconType.DLG_DELETE, new ImageIcon(getClass().getResource("/res/delete.gif")));
	}

	private ImageIcon push(IconType type, ImageIcon icon) {
		return lists.put(type, icon);
	}

	public ImageIcon get_icon(IconType type) {
		return lists.get(type);
	}	
}
