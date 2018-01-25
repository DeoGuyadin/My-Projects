package game;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;

/**
 * Determines what occurs when a button in the game area is selected.
 * 
 * @author Deo Guyadin
 */
public class ButtonAction implements ActionListener {
	JFrame jframe;
	int i, j;
	
	/**
	 * Gets JFrame where the game area is located and the row and column of the selected button.
	 * 
	 * @param jframe JFrame of game area.
	 * @param i Button row.
	 * @param j Button column.
	 */
	public ButtonAction(JFrame jframe, int i, int j) {
		this.jframe = jframe;
		this.i = i;
		this.j = j;
	} // CONSTRUCTOR

	
	@Override
	public void actionPerformed(ActionEvent e) {
		String button = e.getActionCommand();
		
		if (!GameGUI.winnerExists()) {
			if (button.equals("")) {
				GameGUI.setGameButton(i, j);
				GameGUI.checkForWinner('X');
				GameGUI.checkForWinner('O');
				GameGUI.checkForDraw();
			}
		}
	} // actionPerformed
	
} // ButtonAction
