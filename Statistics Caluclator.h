//Programmer: Jeremy Hopson
//Last up date: December 1, 2014
//Assignment: Read in and process data from multiple files, 
//sort the data, and determine statistical information about the 
//data, such as, the mean, median and mode.


#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

// function prototypes
void order(double [],int, int);
void print(double [],int, int);
void average(double[],int, int);
void median(double [],int,int);
void mode(double [],int,int );

int main(){
	  
 
  const double Sentinel=-999;
  const int Size=300;
 
  double num[Size];
  double num1[Size];
  double value=0.0;
  int startValue=0;
  int numIndex =0;
  int setNum;
  string fileName;
  string phrase;
 
  ifstream infile;
  





 cout<<"Programmer: Jeremy Hopson\n"
     <<"Last up date: December 1, 2014\n"
     <<"Assignment: Read in and process data from multiple files,\n" 
     <<"sort the data, and determine statistical information about the\n" 
     <<"data, such as, the mean, median and mode.\n\n\n\n";

    
     
    cout<<"How many data set files would you like to use? ";

	cin>>setNum;
  
  
   //The inner while-loop read in values from a file until a sentinel
   // is incountered and stores them in the num array
   //each time a number is read in to the array its index is increamented by 1
   //The outer for-loop prompts user for a file name,
   // opens the file and reads the phrase from the file.
   // After the while loop is done the file is closed
   //  and the functions order, print, average,median and mode are called
   //   when the outer loop reinitializes the (value) variable is reinitialized to zero.
   //  The outer loop continues until i = setNum (number of data sets)
   
   for(int i=0;i<setNum;i++){
	   
	   cout<<"\n\nEnter data file name: ";

	   cin>>fileName;

       infile.open(fileName);

       getline(infile,phrase);
  
	   cout<<endl<<phrase<<endl<<endl;
   
    value=0.0;
      
   while(value!=Sentinel){
	   infile>>value;
	    if(value!=Sentinel){
	      
          num[numIndex]=value;
		   numIndex++;
           }
	   }
       
       infile.close();
	  cout<<"\n\nUNSORTED DATA \n\n"; 
	  print(num,numIndex,startValue);
	  order(num,numIndex,startValue);
	  cout<<"\n\nSORTED FROM SMALLEST TO LARGEST\n\n";
	  print(num,numIndex,startValue);
	  average(num,numIndex,startValue);
	  median(num,numIndex,startValue);
	  mode(num,numIndex,startValue);
	  
	  
	   startValue=numIndex;
	  
	 
   }     
   cout<<"\n\n----------------------------------------------\n\n";
     
     //imports values from num array into num1 array
     //sorts values does statistical calculations (mean, median and mode)
     // and then prints them
     for(int i=0;i<numIndex;i++)
     num1[i]=num[i];
	 cout<<"COMBINDED DATA UNSORTED \n\n";
	 print(num1,numIndex,0);
	 order(num1,numIndex,0);
	 cout<<"\n\nCOMBINDED DATA SORTED FROM SMALLEST TO LARGEST\n\n";
     print(num1,numIndex,0);
	 cout<<endl<<endl;
	 average(num1,numIndex,0);
	 median(num1,numIndex,0);
	 mode(num1,numIndex,0);
	  
     
	return 0;
}
 
 
	  //uses a selection sort algorithm to order values in num array 
      // from smallest to largest
void order(double num[],int Size2, int startValue){
         
	double minValue;
		int minIndex,startScan;
	  
	for(startScan=startValue;startScan<Size2 ;startScan++){
            
		    minIndex=startScan;	
	        minValue=num[startScan];
			for(int index=startScan+1;index<Size2;index++){
			
				if(num[index]<minValue){
				    minValue=num[index];
					minIndex=index;
				
				}
			          
			}
	
	                
	                     num[minIndex]=num[startScan];
					      num[startScan]=minValue;
	
	
	}

}

//prints values in num array
void print(double array[], int Size,int startValue){
	
		  for(int i=startValue; i<Size;i++)
           cout<<array[i]<<endl;

	  }
// find the mean of value  in num array
void average(double array[], int Size, int startValue){

                      double mean=0;
	         for(int j=startValue; j<Size;j++)
                mean+=array[j];
			 cout<<"\nMean: "<<mean/(Size-startValue)<<endl<<endl;
}

//finds the median of values in num array
void median(double array[],int size,int startValue){
	int k=0;
	int  Size=size-startValue;
	if(Size%2!=0){

		    k=(Size+1)/2;
		  cout<<"Median: "<<array[startValue+k-1]<<endl<<endl;
		
		   }else{
		      k=Size/2;
			  
			  cout<<"Median: "<<((array[(startValue+k)-1]+array[startValue+k])/2.0)<<endl<<endl;
			 
		   
		   }
	
	 
	 

	 }  


// find the mode of values from num array	         
void mode(double num[],int size,int startValue){
	int modCount=0;
	int count =0;
	double ray[100];
	int index=0;
	for(int i=startValue;i<size-1;i++){
	        
			   count=0;
	        
		for(int j=i+1;j<size;j++){
			
			
			if(num[i+modCount]==num[modCount+j])
			      count++;
				
				}
		  
		 if(count>=modCount)
			 modCount=count;
		 
		  
	}  
	  if(modCount>=1){
	     modCount+=1;
		 cout<<"Mode: ";
		 
	  }
	  else
		  cout<<"No mode for set\n";

		 
			 
	           
	 int mod=0;
	   int h;
		for(int f=mod+startValue;f<size-1;f++){
	        
			   count=0;
	        
		for( h=f+1;h<size;h++){
			if(num[f]==num[h])
			      count++;
               
		  }   
		      if(count>=mod)
		       mod=count;

		  if(count+1==modCount){
			  
				ray[index]=num[f];
			   index++;
			     
			}
		   
		}            
		    
		for(int k=0;k<index;k++)
			cout<<ray[k]<<", ";
		
}
