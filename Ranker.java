import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;

//package project9;

public class Ranker {
	
	    private String year;
	    private String gender;
	    private String name;
	    private int rating;
	
    	Map<String,Integer> Male;
	    Map< String,Integer> Female;
        public Ranker(String year, String gender , String name ){
        	
        	
        	
        
	      this.name =name;
	      this.year=year;
	      this.gender=gender;
		  
		
		   BufferedReader br =null;
		   String line;
		   int rows=1;
		   int row =rows;
		   String[] column= null;
		   
		   //initialize Hashmaps
		   Male = new HashMap<String,Integer>();
		   Female = new HashMap<String,Integer>();

		 
		  
		  try{
			  
			   //try to open file  
			   
			  br = new BufferedReader(new FileReader("C:\\Users\\Germi\\Desktop\\" + "Babynamesranking"+year+".txt"));//change to your path
		  }catch(FileNotFoundException fnfe ){
			  System.out.println(fnfe.getMessage() + "FILE NOT FOUND!" );
			
			  // exit if not found   
			System.exit(0);
			  
		  }
		  try {
			       //Read rows from the file, one at 
			  	  // a time, as a single string.
			  
			 while ((line = br.readLine()) != null){
				   
				   //split each row into a column 
				   //(wherever there's a whitespace)
				   // and load them into an array
				   column = line.split("\\s+");
				 
				   
				   
				   do{  
					    //use name and rating  respectively as key and value
					   //separate the male and female name and values into Hashmaps; 
					    Male.put(column[1],Integer.parseInt(column[0]) );
					    Female.put(column[3],Integer.parseInt(column[0]) );
	                	
	  				     row--;
	                	
	                }while(row >0);
				     rows++;
				  
			  }
			
					  
				  
				  
			
		     	
		} catch (IOException ioe) {
			// TODO Auto-generated catch block
		System.out.println(ioe.getMessage() + "ERROR READING FILE!");
		}
	   
	    
	  
	  
	  
        }
       //Getter and setters for Object 
       
		public String getYear() {
			return year;
		}

		public void setYear(String year) {
			this.year = year;
		}

		public String getGender() {
			return gender;
		}

		public void setGender(String gender) {
			this.gender = gender;
		}

		public String getName() {
			return name;
		}

		public void setName(String name) {
			this.name = name;
		}

		public int getRating() {
			
			 if(Male.get(name) != null && gender == "Male"){
    					return Male.get(name);
			 }if(Female.get(name) != null && gender == "Female")
    		   return Female.get(name);
			 
		
			  return 0;
		}     
		     
}
