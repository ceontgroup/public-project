/**
 * 
 */
package org.kem.KExplorer;

/**
 * @author KEM
 * 
 */
public class FileAction {
	private FileActionType actionType = FileActionType.ACT_NONE;
	private String actionPath = null;

	public FileAction(FileActionType type, String s) {
		actionType = type;
		actionPath = s;
	}
	public FileActionType get_type(){
		return actionType;
	}
	public String get_action_path(){
		return actionPath;
	}
}

enum FileActionType{
	ACT_NONE, ACT_UPDATE, ACT_NEW_FOLDER, ACT_NEW_FILE, ACT_OPEN 
}