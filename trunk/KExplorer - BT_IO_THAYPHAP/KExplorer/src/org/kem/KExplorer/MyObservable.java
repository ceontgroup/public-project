package org.kem.KExplorer;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Observable;
import java.util.Stack;

import javax.swing.JOptionPane;

/**
 * 
 */

/**
 * @author KEM
 * 
 */

public class MyObservable extends Observable implements Runnable {
	static MyObservable monitor = new MyObservable();
	private String pathSrc = null;
	private String pathDes = null;
	private String pathDel = null;
	private boolean cutAction = false;
	private boolean copyAction = false;
	private boolean delAction = false;
	private boolean yesAll = false;
	private StatusDig statusDialog = new StatusDig(null);

	public void update_tree() {
		setChanged();
		notifyObservers();
	}
	public void open(String path) {
		setChanged();
		notifyObservers(new FileAction(FileActionType.ACT_OPEN, path));
	}
	public void update(String path) {
		System.out.println("Method update called !");
		setChanged();
		notifyObservers(new FileAction(FileActionType.ACT_UPDATE, path));
	}

	public void new_folder(String path) {
		setChanged();
		notifyObservers(new FileAction(FileActionType.ACT_NEW_FOLDER, path));
	}
	public void new_file(String path) {
		setChanged();
		notifyObservers(new FileAction(FileActionType.ACT_NEW_FILE, path));
	}
	public void rename(FileNode fileNode) {
		System.out.println("Rename !!");
		File file = new File(fileNode.get_path());

		if (file.canWrite()) {
			fileNode.name.setVisible(false);
			fileNode.rename.setText(fileNode.name.getText());
			fileNode.rename.setVisible(true);
		} else {
			JOptionPane.showMessageDialog(null,
					"File or folder can read-only..");
			return;
		}
	}

	public void paste(String path) {
		if (pathSrc != null && path != null) {
			pathDes = path;
			File fs = new File(pathSrc);
			File fd = new File(pathDes);
			if (!fd.canWrite()) {
				JOptionPane.showMessageDialog(null, "Folder is read-only.");
				return;
			}
			if ((fd = new File(fd, fs.getName())).exists()) {
				int choose = JOptionPane.showConfirmDialog(null,
						fd.getAbsolutePath()
								+ " is exists !!, do you want replace ?");
				if (choose != JOptionPane.OK_OPTION) {
					return;
				}
			}
			new Thread(this).start();
		}
	}

	public void delete(String path) {
		File f = new File(path);
		if (!f.canWrite()) {
			JOptionPane.showMessageDialog(null,
					"Folder or file is read-only !!");
			return;
		}
		int choose = JOptionPane.showConfirmDialog(null,
				"Are you sure you want delete " + path);
		if (choose != JOptionPane.OK_OPTION) {
			return;
		}
		{
			pathDel = path;
			delAction = true;
			new Thread(this).start();
		}
	}

	public void copy(String path) {
		copyAction = true;
		cutAction = false;
		pathSrc = path;
	}

	public void cut(String path) {
		if (new File(path).canWrite()) {
			cutAction = true;
			copyAction = false;
			pathSrc = path;
		} else
			JOptionPane.showMessageDialog(null,
					"Folder or file is read-only !!");
	}
	
	private void execute_del(String path) {
		Stack<File> stack = new Stack<File>();
		Stack<File> files = new Stack<File>();
		Stack<File> folders = new Stack<File>();
		statusDialog.set_value(0);
		statusDialog.load_gui_del();
		statusDialog.setVisible(true);
		File fs = new File(path);
		if (fs.isFile()) {
			fs.delete();
		} else {
			stack.push(fs);
			folders.push(fs);
		}
		while (!stack.isEmpty() && statusDialog.isShowing()) {
			fs = stack.pop();
			File childs[] = null;
			childs = fs.listFiles();
			if (childs != null)
				for (File child : childs) {
					if (child.isFile()) {
						files.push(child);
					} else {
						stack.push(child);
						folders.push(child);
					}
				}
		}
		while (!files.isEmpty()) {
			folders.push(files.pop());
		}
		int max = 0;
		max = folders.size();
		while (!folders.isEmpty() && statusDialog.isShowing()) {
			folders.pop().delete();
			if (max > 0) {
				int percent = (max - files.size()) * 100 / max;
				statusDialog.set_value(percent);
			}
		}
		yesAll = false;
		statusDialog.setVisible(false);
	}

	private void execute_cut(String src, String des) throws IOException {
		Stack<File> stack = new Stack<File>();
		Stack<File> filesDes = new Stack<File>();
		Stack<File> folders = new Stack<File>();
		Stack<File> filesSrc = new Stack<File>();
		Stack<File> folders_remove_after = new Stack<File>();
		statusDialog.set_value(0);
		statusDialog.load_gui_cut();
		statusDialog.setVisible(true);
		File fs = new File(src);
		File fd = new File(des, fs.getName());
		if (fs.isFile()) {
			copy_file(fs, fd);
		} else {
			stack.push(fs);
			folders.push(fd);
			folders_remove_after.push(fs);
		}
		while (!stack.isEmpty() && statusDialog.isShowing()) {
			fs = stack.pop();
			fd = folders.pop();
			// if (!fd.exists()){
			// fd.mkdir();
			// }
			// Important !!! if put before
			// When src = C:\exam and des = C:\exam --> infinite loop
			// --> put after
			File childs[] = null;
			childs = fs.listFiles();
			if (childs != null)
				for (File child : childs) {
					if (child.isFile()) {
						filesSrc.push(child);
						filesDes.push(new File(fd, child.getName()));
					} else {
						folders.push(new File(fd, child.getName()));
						stack.push(child);
						folders_remove_after.push(child);
					}
				}
			// Here
			if (!fd.exists()) {
				fd.mkdir();
			}
		}
		int max = 0;
		max = filesSrc.size();
		while (!filesSrc.isEmpty() && statusDialog.isShowing()) {
			fs = filesSrc.pop();
			fd = filesDes.pop();
			if (fd.compareTo(fs) != 0) {
				copy_file(fs, fd);
				fs.delete();
			}
			if (max > 0) {
				int percent = (max - filesSrc.size()) * 100 / max;
				statusDialog.set_value(percent);
			}
		}
		while (!folders_remove_after.isEmpty()) {
			folders_remove_after.pop().delete();
		}
		yesAll = false;
		statusDialog.setVisible(false);
	}

	private void execute_copy(String src, String des) throws IOException {
		Stack<File> stack = new Stack<File>();
		Stack<File> filesDes = new Stack<File>();
		Stack<File> folders = new Stack<File>();
		Stack<File> filesSrc = new Stack<File>();
		statusDialog.set_value(0);
		statusDialog.load_gui_copy();
		statusDialog.setVisible(true);
		File fs = new File(src);
		File fd = new File(des, fs.getName());
		if (fs.isFile()) {
			copy_file(fs, fd);
		} else {
			stack.push(fs);
			folders.push(fd);
		}
		while (!stack.isEmpty() && statusDialog.isShowing()) {
			fs = stack.pop();
			fd = folders.pop();
			// if (!fd.exists()){
			// fd.mkdir();
			// }
			// Important !!! if put before
			// When src = C:\exam and des = C:\exam --> infinite loop
			// --> put after
			File childs[] = null;
			childs = fs.listFiles();
			if (childs != null)
				for (File child : childs) {
					if (child.isFile()) {
						filesSrc.push(child);
						filesDes.push(new File(fd, child.getName()));
					} else {
						folders.push(new File(fd, child.getName()));
						stack.push(child);
					}
				}
			// Here
			if (!fd.exists()) {
				fd.mkdir();
			}
		}
		int max = 0;
		max = filesSrc.size();
		while (!filesSrc.isEmpty() && statusDialog.isShowing()) {
			fs = filesSrc.pop();
			fd = filesDes.pop();
			if (fd.compareTo(fs) != 0) {
				copy_file(fs, fd);
			}
			if (max > 0) {
				int percent = (max - filesSrc.size()) * 100 / max;
				statusDialog.set_value(percent);
			}
		}
		yesAll = false;
		statusDialog.setVisible(false);
	}

	private void copy_file(File src, File des) throws IOException {		
		InputStream in = new FileInputStream(src);
		if (des.exists() && !yesAll) {
			int choose = JOptionPane.showConfirmDialog(null,
					des.getAbsolutePath()
							+ " is exists ! do you want overwrite ?");
			if (choose == JOptionPane.NO_OPTION)
				return;
			else if (choose == JOptionPane.CANCEL_OPTION) {
				yesAll = true;
			}
		}
		if (src.compareTo(des) == 0) {
			return;
		}
		OutputStream out = new FileOutputStream(des);
		byte[] buf = new byte[1024];
		int len = 0;
		while ((len = in.read(buf)) > 0) {
			out.write(buf, 0, len);
		}
		in.close();
		out.close();
	}

	@Override
	public void run() {
		if (copyAction) {
			try {
				execute_copy(pathSrc, pathDes);
			} catch (IOException e) {
				e.printStackTrace();
			}
			copyAction = false;
			if (new File(pathSrc).isDirectory()) {
				update_tree();
			}
			update(pathDes);
			pathSrc = null;
			pathDes = null;
		}
		if (delAction) {
			execute_del(pathDel);
			delAction = false;
			File f = new File(pathDel);
			if (f.isDirectory()) {
				update_tree();
			}
			update(f.getParentFile().getAbsolutePath());
			pathDel = null;
		}
		if (cutAction) {
			try {
				execute_cut(pathSrc, pathDes);
			} catch (IOException e) {
				e.printStackTrace();
			}
			cutAction = false;
			if (new File(pathDes).isDirectory()) {
				update_tree();
			}
			update(pathDes);
			pathSrc = null;
			pathDes = null;
		}
	}	
}
