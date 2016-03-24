import java.awt.Dimension;
import javax.swing.BorderFactory;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.*;
import java.awt.GridBagLayout; 
import java.awt.GridBagConstraints;
import java.awt.event.*;
public class listDetails extends JPanel {

	public listDetails() {
		// TODO Auto-generated constructor stub
		
		String[] yearArray = { "2006", "2007","2008","2009","2010"};
		String[] genderArray = { "Male", "Female"};
		
           //create components   
	       JLabel yearLabel =new JLabel("Select Year ");
	       JLabel genderLabel =new JLabel("Gender ");
	       JLabel nameLabel =new JLabel("Enter Name ");

	       JComboBox yearCB = new JComboBox(yearArray);
	       JComboBox genderCB = new JComboBox(genderArray);
	      
	       
	       JTextField tfName = new JTextField(10);
	       JTextField tfNameRating = new JTextField(10);
	       
	       JButton Btn = new JButton("Find Rating");
	       
	       //add action listener 
	          Btn.addActionListener(new ActionListener(){
	          
	            public void actionPerformed(ActionEvent e){
	            	//get user input from GUI
	                  String year = yearCB.getSelectedItem().toString();
	                  String gender = genderCB.getSelectedItem().toString();
	                  String name = tfName.getText();
	                  
	                  
	                  
	                  name = name.capitalize();
	                  //create Rank Object 
	                  //put user input into constructor 
	                  Ranker rk = new Ranker(year,gender,name);
	                  
	                  //get rank
	                  int rt= rk.getRating();
	                  String empty= " is not ranked ";
	                  
	                  //display  name and rank in tfNameRating field
                      if (rt !=0)
                       tfNameRating.setText(rk.getName() + " was #" + rk.getRating() + " in " + rk.getYear());
                      else
                    	tfNameRating.setText(rk.getName() + empty + " in " + rk.getYear());
	            }
	          
	          
	          });
	         
	       //format Components
	       setLayout( new GridBagLayout());
	       GridBagConstraints gc = new GridBagConstraints();
	       gc.weightx= 0.5;
	       gc.weighty= 0.5;
	       
	       
	       gc.anchor =GridBagConstraints.ABOVE_BASELINE_TRAILING; 
	       gc.gridx =0;
	       gc.gridy = 2;
	       add(yearLabel,gc);
	       
	       gc.gridx =0;
	       gc.gridy =3;
	       add(genderLabel,gc);
	       
	       gc.gridx =0;
	       gc.gridy=4;
	       add(nameLabel ,gc);
	       
	       
	       
	       //second column
	  gc.anchor =GridBagConstraints.ABOVE_BASELINE_LEADING; 
	       
	       gc.gridx =3;
	       gc.gridy =2;
	       add(yearCB,gc);
	       
	        
	       gc.gridx =3;
	       gc.gridy =3;
	       add(genderCB,gc);
	       
	       gc.gridx =3;
	       gc.gridy =4;
	       add(tfName,gc);
         
	       gc.gridx =3;
	       gc.gridy =5;
	       add(Btn,gc);
	       
	       gc.gridx =3;
	       gc.gridy =6;
	       add(tfNameRating,gc);
	     
	}

}
