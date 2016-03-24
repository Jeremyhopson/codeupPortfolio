
import java.awt.*;
import java.awt.Button;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import java.awt.BorderLayout;


public class RankingPane extends JFrame{


public RankingPane() {
	
	//create GUI when RankingPane Object is made
   initUI();
}

// This function creates GUI 
private void initUI() {
	 setTitle("Baby Name Popularity");
	 setSize(350, 200);
	 setLocationRelativeTo(null);
    
	 // Set layout manager
	setLayout(new BorderLayout());
	
	
	
	
   
    //Add container
    Container c = getContentPane();
    
   
  // create listDetails Object
   listDetails detailsPanel = new listDetails();
   
   //add to listDetails Object to container
    c.add(detailsPanel,BorderLayout.CENTER);
      
     }

public static void main(String[] args) {

    EventQueue.invokeLater(new Runnable() {
    
        @Override
        public void run() {
        	
        	//create RankingPane
            RankingPane rp = new RankingPane();
            
            //make panel visible
              rp.setVisible(true);
            
        }

    });

    }
}