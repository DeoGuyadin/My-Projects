package game;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.TextArea;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;

/**
 * A Simple GUI Tic-Tac-Toe game using JFrame
 * 
 * @author Deo Guyadin
 */
public class GameGUI extends JFrame {
	
	
	/**
	 * Default serialVersionUID
	 */
	private static final long serialVersionUID = 1L;
	
	private JMenuBar menuBar = new JMenuBar();
	private Container contentPane;
	
	private JPanel gamePanel = new JPanel();
	private JPanel textPanel = new JPanel();
	
	private static JButton[][] gameButtons = new JButton[3][3];
	
	private static GridLayout gameArea = new GridLayout(3, 3);
	private static TextArea textArea = new TextArea("", 1, 30, 3);
	
	private static char gameBoard[][] = new char[3][3];
	private static char currentPlayer = 'X';
	private static char winner = '\0';
	
	/**
	 * Instantiates game GUI.
	 * 
	 * @param title Title of GUI window.
	 */
	private GameGUI(String title) {
		setLocation(320, 240);
		setTitle(title);
		setSize(320, 380);
		setVisible(true);
		
		contentPane = getContentPane();
		contentPane.setBackground(Color.BLACK);
		
		createFileMenu();
		
		gamePanel.setLayout(gameArea);
		gamePanel.setBackground(Color.WHITE);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				gameButtons[i][j] = new JButton();
				gameButtons[i][j].setBackground(Color.WHITE);
				gamePanel.add(gameButtons[i][j]);
				gameButtons[i][j].addActionListener(new ButtonAction(this, i, j));
			}
		}
		
		textPanel.add(textArea);
		textArea.setEditable(false);
		textArea.setFont(new Font("Arial Black", Font.BOLD, 16));
		textArea.setText("\t             X's Turn");
		
		contentPane.add(gamePanel, BorderLayout.CENTER);
		contentPane.add(textPanel, BorderLayout.SOUTH);
		
		setResizable(false);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	} // CONSTRUCTOR
	
	/**
	 * Create's GUI File Menu.
	 */
	private void createFileMenu() {
		JMenuItem menuItem;
		JMenu fileMenu = new JMenu("File");
		FileMenuHandler fmh = new FileMenuHandler(this);
		
		menuItem = new JMenuItem("Reset Game");
		menuItem.addActionListener(fmh);
		fileMenu.add(menuItem);
		
		fileMenu.addSeparator();
		
		menuItem = new JMenuItem("Quit");
		menuItem.addActionListener(fmh);
		fileMenu.add(menuItem);
		
		setJMenuBar(menuBar);
		menuBar.add(fileMenu);
	} // createFileMenu
	
	/**
	 * Sets selected section of the game area to the player's icon and signals next player of their
	 * turn.
	 * 
	 * @param i Game board row.
	 * @param j Game board column.
	 */
	public static void setGameButton(int i, int j) {
		gameButtons[i][j].setText(Character.toString(currentPlayer));
		gameBoard[i][j] = currentPlayer;
		if (GameGUI.currentPlayer == 'X') {
			currentPlayer = 'O';
			textArea.setText("\t             O's Turn");
		} else if (GameGUI.currentPlayer == 'O') {
			currentPlayer = 'X';
			textArea.setText("\t             X's Turn");
		}
	} // setGameButton
	
	/**
	 * Determines if there is a winning player.
	 * 
	 * @return Indication of the existance of a winner.
	 */
	public static boolean winnerExists() {
		if (winner != '\0') {
			return true;
		}
		return false;
	} // winnerExists
	
	/**
	 * Check's if the designated player has won the game.
	 * 
	 * @param player designated player.
	 * @return Indication of whether or not the play has won.
	 */
	public static boolean checkForWinner(char player) {
		if (!((gameBoard[0][0] == player && gameBoard[0][1] == player && gameBoard[0][2] == player)
		        || (gameBoard[1][0] == player && gameBoard[1][1] == player && gameBoard[1][2] == player)
		        || (gameBoard[2][0] == player && gameBoard[2][1] == player && gameBoard[2][2] == player)
		        || (gameBoard[0][0] == player && gameBoard[1][0] == player && gameBoard[2][0] == player)
		        || (gameBoard[0][1] == player && gameBoard[1][1] == player && gameBoard[2][1] == player)
		        || (gameBoard[0][2] == player && gameBoard[1][2] == player && gameBoard[2][2] == player)
		        || (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player)
		        || (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player))) {
			
			return false;
		}
		
		if (gameBoard[0][0] == player && gameBoard[0][1] == player && gameBoard[0][2] == player) {
			gameButtons[0][0].setBackground(Color.GREEN);
			gameButtons[0][1].setBackground(Color.GREEN);
			gameButtons[0][1].setBackground(Color.GREEN);
		} else if (gameBoard[1][0] == player && gameBoard[1][1] == player && gameBoard[1][2] == player) {
			gameButtons[1][0].setBackground(Color.GREEN);
			gameButtons[1][1].setBackground(Color.GREEN);
			gameButtons[1][2].setBackground(Color.GREEN);
		} else if (gameBoard[2][0] == player && gameBoard[2][1] == player && gameBoard[2][2] == player) {
			gameButtons[2][0].setBackground(Color.GREEN);
			gameButtons[2][1].setBackground(Color.GREEN);
			gameButtons[2][2].setBackground(Color.GREEN);
		} else if (gameBoard[0][0] == player && gameBoard[1][0] == player && gameBoard[2][0] == player) {
			gameButtons[0][0].setBackground(Color.GREEN);
			gameButtons[1][0].setBackground(Color.GREEN);
			gameButtons[2][0].setBackground(Color.GREEN);
		} else if (gameBoard[0][1] == player && gameBoard[1][1] == player && gameBoard[2][1] == player) {
			gameButtons[0][1].setBackground(Color.GREEN);
			gameButtons[1][1].setBackground(Color.GREEN);
			gameButtons[2][1].setBackground(Color.GREEN);
		} else if (gameBoard[0][2] == player && gameBoard[1][2] == player && gameBoard[2][2] == player) {
			gameButtons[0][2].setBackground(Color.GREEN);
			gameButtons[1][2].setBackground(Color.GREEN);
			gameButtons[2][2].setBackground(Color.GREEN);
		} else if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) {
			gameButtons[0][0].setBackground(Color.GREEN);
			gameButtons[1][1].setBackground(Color.GREEN);
			gameButtons[2][2].setBackground(Color.GREEN);
		} else if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player) {
			gameButtons[0][2].setBackground(Color.GREEN);
			gameButtons[1][1].setBackground(Color.GREEN);
			gameButtons[2][0].setBackground(Color.GREEN);
		}
		
		winner = player;
		textArea.setText("\t             " + player + " Wins!!!");
		
		return true;
	} // checkForWinner
	
	/**
	 * Checks if the games ends with no winner.
	 */
	public static void checkForDraw() {
		if (!(gameBoard[0][0] == 0 || gameBoard[0][1] == 0 || gameBoard[0][2] == 0 || gameBoard[1][0] == 0
		        || gameBoard[1][1] == 0 || gameBoard[1][2] == 0 || gameBoard[2][0] == 0 || gameBoard[2][1] == 0
		        || gameBoard[2][2] == 0) && winner == '\0') {

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					gameButtons[i][j].setBackground(Color.RED);
				}
			}
			textArea.setText("\t             " + "DRAW!!!");
		}
	} // checkForDraw
	
	/**
	 * Resets game
	 */
	public static void resetGame() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				gameButtons[i][j].setText("");
				gameButtons[i][j].setBackground(Color.WHITE);
				gameBoard[i][j] = '\0';
			}
		}
		winner = '\0';
		currentPlayer = 'X';
		textArea.setText("\t             X's Turn");
	} // resetGame
	

	public static void main(String argv[]) {
		new GameGUI("Tic-Tac-Toe");
	} // main
	
} // GameGUI
