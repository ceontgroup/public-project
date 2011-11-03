/**
 * 
 */
package org.kem.PuzzleGame;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JTextField;
import javax.swing.Timer;
import javax.swing.filechooser.FileNameExtensionFilter;



/**
 * @author KEM
 *
 */

public class MainFrame extends JFrame implements ActionListener{
	
	public enum DestState {
		ODD, EVEN
	};
	private static final long serialVersionUID = 1L;
	CustomButton btnStart;
	JProgressBar progressBar;
	JTextField txtGameStatus;
	Color fColor, bColor;
	MenuBar menu;
	boolean newGame, gameStarted, gamePause;
	ArrayList<JButton> listGameButton;
	String[] destEVEN = {".", "1", "2", "3", "4", "5", "6", "7", "8"};
	String[] destODD = {"1", "2", "3", "8", ".", "4", "7", "6", "5"};
	String[] dest;
	private JButton selected;
	Timer gameTimer;
	private int limitSecond, remainSecond;	
	/**
	 * @param args
	 */	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MainFrame("Puzzle Game @Kem");		
	}
	
	public MainFrame(String title){
		super(title);		
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		limitSecond = 60;
		remainSecond = 60;
		gameTimer = new Timer(1000, new ActionListener() {
						
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				if (!gamePause && gameStarted){
					remainSecond--;
					updateGame();
				}				
			}
		});
		gameTimer.start();
		loadGui();
		initGame();
		this.pack();		
		//this.setModalExclusionType(ModalExclusionType.TOOLKIT_EXCLUDE);
		this.setLocation(100, 100);
		this.setResizable(false);
		this.setVisible(true);
	}

	protected void updateGame() {
		// TODO Auto-generated method stub
		txtGameStatus.setText(" "+String.valueOf(remainSecond)+"s");
		if (remainSecond == 0){
			JOptionPane.showMessageDialog(this, "Time over !!");
			stopGame();
		}
		int count = 0;		
		if (listGameButton != null){			
			for (int i = 0; i < listGameButton.size(); i++)
			{
				if (listGameButton.get(i).getText().equals(dest[i]))
				{
					count++;
				}
			}
			int perCent = (int) (100 * count / 9.0f);
			progressBar.setValue(perCent);
			progressBar.setString(String.valueOf(perCent)+ " %");			
		}
		if ((count == 9) && gameStarted)
		{
			gameTimer.stop();				
			stopGame();		
			JOptionPane.showMessageDialog(this, "You won !!!");
			System.out.println("You won !");														
		}
	}

	private void initGame() {
		// TODO Auto-generated method stub
		remainSecond = limitSecond;
		newGame = false;
		gameStarted = false;		
		gamePause = false;
	}

	private void loadGui() {
		// TODO Auto-generated method stub
		menu = new MenuBar(this);		
		this.setJMenuBar(menu);		
		
		Container contenPanel = this.getContentPane();
		contenPanel.setLayout(new BorderLayout());
		//Color		
		fColor = new Color(102, 102, 102); //TextColor		
		//List Button
		listGameButton = new ArrayList<JButton>();
		//Button area
		JPanel gamePanel = new JPanel(new GridLayout(3, 3, 2, 2));
		//Dest default
		dest = destODD;
		for (String s : dest){
			JButton jButton = new JButton(s);
			jButton.setBackground(new Color(255, 204, 102));
			jButton.setForeground(fColor);
			jButton.setFont(new Font(null, Font.BOLD, 60));
			jButton.addActionListener(this);
			listGameButton.add(jButton);
			gamePanel.add(jButton);
		}
		//Status game area
		JPanel statusPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
		statusPanel.setPreferredSize(new Dimension(260, 40));
		//Custom button start
		btnStart = new CustomButton(Color.YELLOW, Color.RED);
		btnStart.addActionListener(this);
		progressBar = new JProgressBar(0, 100);
		progressBar.setToolTipText("Percent complete");
		progressBar.setStringPainted(true);
		txtGameStatus = new JTextField(3);
		txtGameStatus.setText(" "+String.valueOf(remainSecond)+"s");
		statusPanel.add(btnStart);
		statusPanel.add(progressBar);
		statusPanel.add(txtGameStatus);
		//Add contentPanel
		contenPanel.add(gamePanel, BorderLayout.CENTER);
		contenPanel.add(statusPanel, BorderLayout.PAGE_END);
	}
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub			
		System.out.println("Debug: " + arg0);
		ArrayList<JMenuItem> listMenuItems = menu.getMenuItems();
		//StartButton
		if (arg0.getSource() == btnStart){
			if (btnStart.getTitle().equals("Start"))
				startGame();
			else
				stopGame();			
		}
		//Menu action
		for(JMenuItem menuItem : listMenuItems){
			if (arg0.getSource() == menuItem){
				pauseGame();
				if (menuItem.getActionCommand().equals("About game")){
					ImageIcon icon = new ImageIcon(this.getClass().getResource("/res/owner.jpg"));					
					String msg = "Puzzle Game \n";
					msg +="Version 2.0\n";
					msg +="Copyright @2011 written by Kem\n";
					JOptionPane.showMessageDialog(this, msg, "About game", 1, icon);					
				}
				if (menuItem.getActionCommand().equals("Save game")){
					saveGame();
				}
				if (menuItem.getActionCommand().equals("Load game")){
					loadGame();
				}
				if (menuItem.getActionCommand().equals("Change color")){
					Color color = JColorChooser.showDialog(this, "Color board", bColor);
					System.out.println(color);
					if (color != null)
					{
						bColor = color;
						updateColor(bColor, fColor);
					}
				}
				if (menuItem.getActionCommand().equals("Exit game")){
					System.exit(0);
				}
				if (menuItem.getActionCommand().equals("How to play")){																									 				
					if (getCurrentShow(Help.class)){
						new Help(this);
					}
				}
				if (menuItem.getActionCommand().equals("New game")){
					makeNewGame();
				}		
				pauseGame();
				break;				
			}
		}
		// Button game action
		for (JButton current : listGameButton) {
			if (arg0.getSource() == current) {
				if (gameStarted == false)
				{
					JOptionPane.showMessageDialog(this, "Please click start button");
					return;
				}
				if (selected == null) {
					selected = current;
					selected.setBackground(new Color(bColor.getBlue() / 2,
							bColor.getRed() / 2, bColor.getGreen() / 2));
				} else {
					System.out.println("Current: " + current.getText()
							+ " - Selected: " + selected.getText());
					if (moveAvailable(selected, current)) {
						String tem = selected.getText();
						selected.setText(current.getText());
						current.setText(tem);
						updateGame();
					}
					selected.setBackground(bColor);
					selected = null;
				}
				break;
			}
		}

	}

	private void pauseGame() {
		// TODO Auto-generated method stub
		if (gamePause == false){
			System.out.println("Game Pause") ;
			gamePause = true;
		}
		else{
			gamePause = false;
			System.out.println("Game Resume") ;
		}
	}

	private void loadGame() {
		// TODO Auto-generated method stub		
		System.out.println("Load game");		
		JFileChooser openFile = new JFileChooser();
		FileNameExtensionFilter filter = new FileNameExtensionFilter(
				"Puzzle game", "puzz");
		openFile.setFileFilter(filter);
		int reVal = openFile.showOpenDialog(this);			
		if (reVal == JFileChooser.APPROVE_OPTION) {		
			stopGame();
			newGame = true;
			BufferedReader fin;
			try {
				fin = new BufferedReader(new FileReader(openFile.getSelectedFile().getPath()));
				remainSecond = Integer.valueOf(fin.readLine());
				if (listGameButton != null) {
					for (int i = 0; i < listGameButton.size(); i++) {
						listGameButton.get(i).setText(fin.readLine());
						listGameButton.get(i).setBackground(bColor);
						listGameButton.get(i).setForeground(fColor);
					}
				}
				fin.close();
			} catch (FileNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e3) {
				// TODO Auto-generated catch block
				e3.printStackTrace();
			}
		}
	}

	private void saveGame() {
		// TODO Auto-generated method stub
		System.out.println("Save game");	
		if (!gameStarted)
			return;
		JFileChooser saveFile = new JFileChooser();			
		FileNameExtensionFilter filter = new FileNameExtensionFilter(
		        "Puzzle game (*.puzz)", "puzz");
		saveFile.setFileFilter(filter);				
		if (saveFile.showSaveDialog(this) == JFileChooser.APPROVE_OPTION)
		{
			File f = saveFile.getSelectedFile();		
			String fileName = f.getPath();
			if (!fileName.endsWith(".puzz")){
				fileName += ".puzz";
			}
			boolean exits = (new File(fileName)).exists();
			if (exits)
			{
				JOptionPane.showMessageDialog(null, "File "+ f.getPath()+ " is exist !");
			}
			else
			{
				try {
					BufferedWriter fout = new BufferedWriter(new FileWriter(fileName));						
					fout.write(String.valueOf(remainSecond));
					if (listGameButton != null)
					{
						for (int i = 0; i < listGameButton.size(); i++)
						{
							fout.newLine();
							fout.write(listGameButton.get(i).getText());
						}
					}
					fout.close();
					System.out.println("File saved !\n" + fileName);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
					System.out.println("File not saved !\n");
				} 					
			}
		}		
	}

	private void stopGame() {
		// TODO Auto-generated method stub
		initGame();
		fColor = new Color(102, 102, 102);
		updateColor(bColor, fColor);
		btnStart.setTitle("Start");
		btnStart.setToolTipText("Click here to begin play game.");
	}

	private void startGame() {
		// TODO Auto-generated method stub
		if (newGame == false) {
			makeNewGame();
		}
		gameStarted = true;
		gamePause = false;
		btnStart.setTitle("Stop");
		btnStart.setToolTipText("Click here to end game.");
		gameTimer.restart();
		System.out.println("Start game");		
	}

	private void makeNewGame() {
		// TODO Auto-generated method stub
		System.out.println("New game");
		stopGame();
		newGame = true;
		ArrayList<String> list = new ArrayList<String>();
		for (int i = 1; i < 9; i++){			
				list.add(String.valueOf(i));
		}
		list.add(".");		
		int max = 10;
		Random rand = new Random();
		for (int i = 0; i < 9; i++)
		{
			max--;
			int tem = rand.nextInt(max);
			try {
			listGameButton.get(i).setText(list.get(tem));
			list.remove(tem);
			}
			catch (Exception e) {
				System.out.println("Exception "+ tem);
			}						
		}	
		DestState destState = DetermineDestState(listGameButton);
		if (destState == DestState.EVEN) {
			dest = destEVEN;
			System.out.println("DEST EVEN");
		}
		else{
			dest = destODD;
			System.out.println("DEST ODD");
		}
		
		if (destState == DestState.EVEN){
			//JOptionPane.showMessageDialog(this, "With current state, you never complete task !");
			makeNewGame();
		}
		if (bColor == null){
			bColor = new Color(255, 153, 0);
		}
		fColor = new Color(0, 0, 0);
		updateColor(bColor, fColor);
	}
	//Determine dest state
	private DestState DetermineDestState(ArrayList<JButton> list){
		int sum=0;            
		int [][]val = new int[3][3];
		int count = 0;
		for(int i = 0; i < val.length; i++)
			for (int j = 0; j < val[i].length; j++){
				try{
					val[i][j] = Integer.parseInt(list.get(count).getText());
				}
				catch (Exception e) {
					val[i][j] = 0;
				}
				count++;
			}
        for (int i = 0; i < 9; i++)
            for (int j = i + 1; j < 9; j++)
                if (val[j / 3][j % 3]!=0&&val[j / 3][j % 3] < val[i / 3][i % 3])
                    sum++;
        if (sum % 2 == 0)
        	return DestState.EVEN;
        else
        	return DestState.ODD;
	}

	@SuppressWarnings("rawtypes")
	private boolean getCurrentShow(Class class1) {
		// TODO Auto-generated method stub		
		Component [] list = getWindows();					
		for (Component o: list){			
			if (o.getClass() == class1){				
				o.setVisible(true);
				return false;
			}					
		}
		return true;
	}

	private void updateColor(Color bColor2, Color fColor2) {
		// TODO Auto-generated method stub
		for (JButton jButton : listGameButton){
			jButton.setBackground(bColor2);
			jButton.setForeground(fColor2);
		}
	}

	private boolean moveAvailable(JButton selected, JButton current) {
		// TODO Auto-generated method stub
		if (!(gameStarted || gamePause))
			return false;
		if (current == selected)
			return false;
		if (!(selected.getText().equals(".") || current.getText().equals(".")))
			return false;
		int selectedIndex = listGameButton.indexOf(selected);
		int currentIndex = listGameButton.indexOf(current);
		int tem = Math.abs(selectedIndex - currentIndex);
		if ( tem == 3 || tem == 1)
			return true;
		return false;
	}
}
