import java.security.SecureRandom;

import javax.swing.JOptionPane;

/**
 * Program demonstrates a Bell Curve through the simulation of coin flips in sets 
 * of a size designated by the user and repeating the coin flips through a series 
 * of trials also designated by the user. The program displays a line graph of 
 * the number of times the various possible number of heads occur after all 
 * trials are done. In theory since coin flips are small, independent, and random 
 * events the line graph should demonstrate a bell curve. 
 * 
 * @author Deoburton Guyadin
 *
 */

public class Driver {
   
   public static void main(String[] args){
      
		int coinCount = 0;
		int trialCount = 0;
         
		/* Prompt user for number of coins to be in a set. Fixed to low numbers to 
		 * increase likeliness of smooth line to more accurately demonstrate bell
		 * curve.
		 */
		coinCount = Integer
		        .parseInt(JOptionPane.showInputDialog(null, "Input Number " + "of Coins (between 10 and 50) per Trial."));
		if ((coinCount < 10) || (coinCount > 50)) {
			JOptionPane.showMessageDialog(null, "ERROR: Must be between 10 and 50.");
			System.exit(1);
		}
         
		/* Prompt user for number of trials to conduct. Fixed to high number to allow
		 * for enough trials to demonstrate accurate shape of the typical bell curve.
		 */
		trialCount = Integer.parseInt(
		    JOptionPane.showInputDialog(null, "Input Number " + "of Trials (between 2000 and 6000) to conduct."));
		if ((trialCount < 2000) || (trialCount > 6000)) {
			JOptionPane.showMessageDialog(null, "ERROR: Must be between 2000 and 6000.");
			System.exit(1);
		}
         
		/* Set of coins is represented by an array of boolean variables with
		 * 'true' being heads and 'false' being tails.
		 */
		boolean[] coinSet = new boolean[coinCount];
		int[] results = new int[coinCount + 1];
         
		SecureRandom randombool = new SecureRandom();
         
		/* Simulates coin flips by assigning random boolean values to each
		 * variable in coinSet array. The number of heads in each trial is
		 * stored in the results array.
		 */
		for (int i = 0; i < trialCount; i++) {
			int numTrue = 0;
			for (int j = 0; j < coinCount; j++) {
				coinSet[j] = randombool.nextBoolean();
				if (coinSet[j] == true)
					numTrue++;
         }
			results[numTrue]++;
		}
      
		/* Displays the graph and chart representing the data. */
		SplinePlot CoinToss = new SplinePlot("Bell Curve Demonstration", "Coin Flip", results, "# of Possible Heads",
		        "# of Trials with 'X' Heads Occuring");
		CoinToss.setVisible(true);
         
		/* Prompts the user to determine if they want to repeat the simulation
		 * or not.
		 */
   }
}