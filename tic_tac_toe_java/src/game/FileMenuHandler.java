package game;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;

/**
 * Determines the functions of the buttons in the file menu.
 * 
 * @author Deo Guyadin
 */
public class FileMenuHandler implements ActionListener {
	
	
	JFrame jframe;
	
	/**
	 * Gets JFrame where the file menu is located.
	 * 
	 * @param jframe
	 */
	public FileMenuHandler(JFrame jframe) {
		this.jframe = jframe;
	} // CONSTRUCTOR

	@Override
	public void actionPerformed(ActionEvent e) {
		String menuName = e.getActionCommand();
		
		if (menuName.equals("Reset Game")) {
			GameGUI.resetGame();
		}
		
		else if (menuName.equals("Quit")) {
			System.exit(0);
		}
	} // actionListnener
	
} // FileMenuHandler
