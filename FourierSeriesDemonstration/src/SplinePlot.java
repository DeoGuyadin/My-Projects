import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.renderer.xy.XYSplineRenderer;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

/**
 * Class allows for the construction of a JFrame containing two line graphs. One with a single
 * series and another with multiple series'. This class was created using the JFreeChart public
 * library (url: http://www.jfree.org/jfreechart/) with spline rendering and a chart of the data
 * displayed in the graph.
 * 
 * @author Deoburton Guyadin
 */

public class SplinePlot extends JFrame{
   
   private static final long serialVersionUID = 1L;

   /**
    * Constructor for SplinePlot.
    * 
    * @param appTitle Title of JFrame.
    * @param chartTitle Graph Title.
    * @param data Data to be graphed in upper graph.
    * @param XLabel Label for the X axis.
    * @param YLabel Label for the Y axis.
    * @param multiData Array of data sets to be graphed in lower graph.
    */
   public SplinePlot(String appTitle, String chartTitle, double[] data, String XLabel, String YLabel, double[][] multiData){
      
      /* Sets properties of JFrame. */
      super(appTitle);
      setMinimumSize(new Dimension(500, 500));
      setResizable(true);
      
      /* Plots series represented in "data" in the upper graph. */
      XYSeries series = new XYSeries(appTitle);
      for(int i = 0; i<data.length; i++)
         series.add(i, data[i]);
      XYSeriesCollection dataset = new XYSeriesCollection();
      dataset.addSeries(series);
      
      JFreeChart line = ChartFactory.createXYLineChart(chartTitle,
            XLabel, YLabel, dataset,
            PlotOrientation.VERTICAL,false,true,false);
      line.getXYPlot().setRenderer(new XYSplineRenderer());
      JPanel panel = new ChartPanel(line);
      this.add(panel, BorderLayout.NORTH);
      
      /* Plots multiple series' represented in "multidata" in the lower graph. */
      XYSeries[] multiSeries = new XYSeries[multiData[0].length];
      for(int i = 0; i<multiSeries.length; i++){
            multiSeries[i] = new XYSeries(appTitle + Integer.toString(i));
            for(int j = 0; j<multiData[i].length; j++)
               multiSeries[i].add(j, multiData[i][j]);
      }
      XYSeriesCollection multiDataset = new XYSeriesCollection();
      for(int i = 0; i<multiSeries.length; i++)
         multiDataset.addSeries(multiSeries[i]);
      
      JFreeChart multiLine = ChartFactory.createXYLineChart("Individual Waves", 
            XLabel, YLabel, multiDataset, 
            PlotOrientation.VERTICAL,false,true,false);
      multiLine.getXYPlot().setRenderer(new XYSplineRenderer());
      JPanel multiPanel = new ChartPanel(multiLine);
      this.add(multiPanel,BorderLayout.SOUTH);        
      
      this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      this.pack();
      this.setVisible(true);
      
   }
}