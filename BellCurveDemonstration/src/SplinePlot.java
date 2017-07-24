import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.renderer.xy.XYSplineRenderer;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

/**
 * Class allows for the construction of a JFrame containing both a line graph created using the 
 * JFreeChart public library (url: http://www.jfree.org/jfreechart/) with spline rendering and 
 * a chart of the data displayed in the graph.
 * 
 * @author Deoburton Guyadin
 *
 */

public class SplinePlot extends JFrame{
   
   private static final long serialVersionUID = 1L;

   /**
    * Constructor for SplinePlot.
    * 
    * @param appTitle Title of the JFrame
    * @param chartTitle Title of the graph and chart.
    * @param data Data to graphed.
    * @param XLabel Label for the X axis.
    * @param YLabel Label for the Y axis.
    */
   public SplinePlot(String appTitle, String chartTitle, int[] data, String XLabel, String YLabel){
      
      /* Sets properties of Jframe. */
      super(appTitle);
      setMinimumSize(new Dimension(800,800));
      setResizable(false);
      
      /* Creates graph using the data provided and places it in the upper half of the JFrame. */
      XYSeries series = new XYSeries(appTitle);
      for(int i = 0; i<data.length; i++)
         series.add(i, data[i]);
      XYSeriesCollection dataset = new XYSeriesCollection();
      dataset.addSeries(series);
      
      JFreeChart line = ChartFactory.createXYLineChart(chartTitle,
            XLabel, YLabel , dataset,
            PlotOrientation.VERTICAL,false,true,false);
      line.getXYPlot().setRenderer(new XYSplineRenderer());
      JPanel panel = new ChartPanel(line);
      this.add(panel, BorderLayout.NORTH);
      
      /* Creates a chart using the data provided and places it on the lower half of the JFrame. */
      String[] columns = new String[]{XLabel, YLabel};
      Object[][] info = new Object[data.length+1][2];
      for(int i = 0; i<data.length; i++){
         info[i][0] = i;
         info[i][1] = data[i];
      }
      JTable table = new JTable(info, columns);
      this.add(new JScrollPane(table), BorderLayout.SOUTH);
      this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      this.pack();
   }
}