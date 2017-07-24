import javax.swing.JOptionPane;

/**
 * Program demonstrates different examples of Fourier series and the many 
 * sine waves that are summed to create the demonstrated Fourier series.
 * Adding a number of sine waves with specific amplitudes and frequencies
 * should create identifiable patterns in the Fourier waveform.
 * 
 * @author Deoburton Guyadin
 */

public class Driver {
   
   public static void main(String args[]){
      
      /*
       * Data representation in array form of the multiple series making up
       * the Fourier series. Each separate wave is represented the rows of
       * the array while the columns represent the shared x-axis of the
       * multiple series'.
       */
		double[][] data = new double[10000][25];
      
      /*
       * Data representation in array form of the Fourier series to be
       * graphed.
       */
      double[] fourier = new double[25];
      
      /*
       * Prompts user to select which example of a Fourier series they
       * want to see and then displays a graph of the selected series
       * as well as a graph of the multiple series making up the
       * Fourier series.
       */
      Object[] options = {"Square", "Triangle", "Sawtooth"};
      int selection = JOptionPane.showOptionDialog(
            null,
            "What fourier waveform do you want to be see?",
            "Fourier",
            JOptionPane.YES_NO_CANCEL_OPTION,
            JOptionPane.QUESTION_MESSAGE,
            null,
            options,
            options[2]);
      
      
      //Square Wave
      if(selection==0) {
			for (int k = 1; k <= 10000; k++)
            for(int t = 0; t < 25; t++)
               data[k-1][t] = 
                  (4/Math.PI)*Math.sin((((2*(double)k)-1)*t)/2)/((2*(double)k)-1);
      
         for(int t = 0; t < 25; t++){
				for (int k = 0; k < 10000; k++)
               fourier[t]+=data[k][t];
         }
      
         SplinePlot Series = new SplinePlot("Fourier", "Square Wave", fourier, "\n", "Amplitude", data);
         Series.setVisible(true);
      }
      
      
      //Triangle Wave
      if(selection == 1) {
			for (int k = 1; k <= 10000; k++)
            for(int t = 0; t < 25; t++)
               data[k-1][t] = 
                  (8/Math.pow(Math.PI,2))*(Math.pow(-1,((2*(double)k)-2)/2)/Math.pow(((2*(double)k)-1),2))*Math.sin((((2*(double)k)-1)*t)/2);
      
         for(int t = 0; t < 25; t++){
				for (int k = 0; k < 10000; k++)
               fourier[t]+=data[k][t];
         }
      
         SplinePlot Series = new SplinePlot("Fourier", "Triangle Wave", fourier, "\n", "Amplitude", data);
         Series.setVisible(true);
      }
      
      
      //Sawtooth Wave
      if(selection == 2) {
			for (int k = 1; k <= 10000; k++)
            for(int t = 0; t < 25; t++)
               data[k-1][t] = (3*Math.PI/4)*((1/2)-((1/Math.PI)*(1/(double)k)*Math.sin((k*Math.PI*t)/6)));
      
         for(int t = 0; t < 25; t++){
				for (int k = 0; k < 10000; k++)
               fourier[t]+=data[k][t];
         }
      
         SplinePlot Series = new SplinePlot("Fourier", "Sawtooth Wave", fourier, "\n", "Amplitude", data);
         Series.setVisible(true);
      }
   }
}