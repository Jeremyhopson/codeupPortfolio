//Programmer:Jeremy Hopson
//Last update: December 8, 2014
//Assignment: Design of Tic Tac Toe game
#include<iostream> 
#include<iomanip>
#include<string>
#include <cstdlib>

using namespace std;
const int row=3,column=3;
int First_Player=0, Second_Player=0, Game_total=1;
void Game_Board(char [][column]);
bool Winner(char[][column],bool& );
void scoreBoard(int&, int& , int& );
using namespace std;

int main(){




	
	int player=1;
	char coordinate;
	
	 int x=0;
	 char r, col;
	 int R,Col;
     bool Game_ON=true;
  	 bool draw;	
	 char Continue='y';
    
	  player = (player%2) ? 1:2;
	     while(Continue=='y'||Continue=='Y'){// reset game while Continue is y or Y 
				  char board[row][column]={};
	 do{
			  
		 // if player is 
		 if(player%2)
			 player=1;
		 else player=2;
         if(player==1)
			 coordinate ='X';
		 else
			 coordinate='O';
		  
	      Game_Board(board);
		  cout<<"\n\n Enter co-ordinate (ROW , COlUMN)\n\n "
	          <<"GO player "<<player<<"\n\n";      
		     
		                              
			              cin>>(r)>>(col);
							  

                       if(r=='1'||r=='2'||r=='3'||col=='1'||col=='2'||col=='3'){
						   R=static_cast<int>(r); 
						   Col=static_cast<int>(col);
						    --R,--Col;
							if(R==48)
							  R=R-48;
							 if(Col==48)
								 Col=Col-48;
							 if(R==49)
                                R=R-48;
							 if(Col==49)
								 Col=Col-48;
							 if(R==50)
								 R=R-48;
							 if(Col==50)
								 Col=Col-48;

							 
		                   
					   }
					   
					     
						 
					   
					   
		  
			 //conditionals assign values to indexes    

		   if(!board[0][0]&&R==0&&Col==0)
                board[0][0]=coordinate;
		   else if(!board[0][1]&&R==0&&Col==1)
			   board[0][1]=coordinate;
		   else if(!board[0][2]&&R==0&&Col==2)
			   board[0][2]=coordinate;
		   else if(!board[1][0]&&R==1&&Col==0)
			       board[1][0]=coordinate; 
		   else if(!board[1][1]&&R==1&&Col==1)
			   board[1][1]=coordinate;
		   else if(!board[1][2]&&R==1&Col==2)
			   board[1][2]=coordinate;
		   else if(!board[2][0]&&R==2&&Col==0)
			   board[2][0]=coordinate;
		    else if(!board[2][1]&&R==2&&Col==1)
			   board[2][1]=coordinate;
		    else if(!board[2][2]&&R==2&&Col==2)
			   board[2][2]=coordinate;
			
		   else{
			     
			   //if not proper entry return to top of loop and try again;
			   player--;
			    cout<<"\n\nINVAILD ENTRY!"
							  <<"\n\nPRESS ENTER TO TRY AGAIN\n\n";
			 
			  
			      cin.ignore();
			      cin.get();
			  }

		      Game_ON=Winner(board,draw);
		      player++;
		        
      //do loop while Game_ON is true and draw is true	       
	 }while(Game_ON&&draw);
          if(!Game_ON&&draw){//if Game_On is false but draw is true print winner
	    Game_Board(board);
            cout<<"Match goes to player "<<--player<<endl;
			if(player%2)
             First_Player++;
			else
			  Second_Player++;
		  }else if(!draw&&Game_ON){//if draw is false and Game_ON is true print cat game  
		      
		       Game_Board(board);
		       cout<<"CAT GAME\n";
		  
		  }

		  
			  
		       cout<<"Play again? (Y/N)";

			   cin>>Continue;

			    Game_total++;//increment number of games
				  

				         draw=true;//reset draw
						 Game_ON=true;//reset Game_ON
				   
			           
			      if(First_Player>Second_Player&&Continue!='y'&&Continue!='Y'){
					  system("CLS");
					  cout<<"Programmer:Jeremy Hopson\n"
                          <<"Last update: December 8, 2014\n"
                          <<"Assignment: Design of Tic Tac Toe game\n\n\n\n\n\n\n";
					    --Game_total;
					  scoreBoard(First_Player, Game_total, Second_Player);
                           cout<<"\n\n\t\t\t\tPlayer 1 is the Winner!\n\n";

				  }
				  else if(Second_Player>First_Player&&Continue!='y'&&Continue!='Y'){
					 
					  system("CLS");
					  cout<<"Programmer:Jeremy Hopson\n"
                          <<"Last update: December 8, 2014\n"
                          <<"Assignment: Design of Tic Tac Toe game\n\n\n\n\n\n\n";
					  --Game_total;
					  scoreBoard(First_Player, Game_total, Second_Player);
					  cout<<"\n\n\t\t\t\tPlayer 2 is the Winner!\n\n";
				  }

				  else if(Continue!='y'&&Continue!='Y')
				  {
				    system("CLS");
					cout<<"Programmer:Jeremy Hopson\n"
                        <<"Last update: December 8, 2014\n"
                        <<"Assignment: Design of Tic Tac Toe game\n\n\n\n\n\n\n";
					--Game_total;
					 scoreBoard(First_Player, Game_total, Second_Player);
					 cout<<"\n\n\t\t\t\tCAT GAME\n\n";

				  }

				  
				  
			  }
return 0;


}
        //prints scoreboard and keeps track of number of 
        // games played and each player score
void scoreBoard(int& First_player, int& Game_total, int& Second_player){
	
	cout<<"\t\t\t\t  Tic Tac Toe\n\n";
    cout<<"    \t\t\t    PLAYER 1  VS.  PLAYER 2\n" 
		<<"    \t\t\t  _____________________________\n"
		<<"    \t\t\t |         |          |        |\n"
		<<"    \t\t\t |  Score  |   Game   |  Score |\n"
        <<"    \t\t\t |         |          |        |\n"
		<<"    \t\t\t |    "<<First_player<<"    |     "<<Game_total<<"    |    "<<Second_player<<"   |\n"
		<<"    \t\t\t |_________|__________|________|\n\n\n\n";

	          
} 



bool Winner(char array[][column],bool& draw){
	int count=0,count1=0,count2=0,count3=0;
	 int h=0;
			   //chicking for up cross win
			   for(int j=2;j>=1;j--){

				  if(array[j][h]==array[j-1][h+1]&& array[j][h])
					  count2++;
				        h++;
				    if(count2==2)
					 return false;
					
              }      

	  for(int i=0;i <=2;i++){//checks rows for win
		  count=0;  
		  for(int j=0;j<=1;j++){
		       

			  if(array[j][i]==array[j+1][i]&& array[j][i]!='\0')
                     	count++;
			            
		             if(count==2)
					 return false;    
	  
		  }
		 
	  }

	        count=0;
	   for(int i=0;i <=2;i++){//checks columns for win
		  count=0;	
		  for(int j=0;j<=1;j++){
		       

			  if(array[i][j]==array[i][j+1]&& array[i][j]!='\0')
                     	count++;
			        
		  }
                         if(count==2)
							 return false;
					      
						  
	  }                       
	                   
	      
         
	           //accounting for draw
		    for (int i=0;i<3;i++)  {    
                 for(int j=0;j<3;j++){
		               if (array[j][i]!='\0')
                            count1++;
				 }
			}
			   if(count1==9)
		         draw=false;
			
			   //check for down cross win
		     int k=0;
		   count =0;
		  for(int j=0;j<=1;j++){
		       
			        
			  if(array[j][k]==array[j+1][k+1]&& array[j][k]!='\0')
                     	count++;	  
		                k++;
                   if(count==2)
					   return false;
		       }
		     
		        
			         
}

 //Prints  tic tac toe game board
void Game_Board(char board[][column]){

	system("CLS");
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\tThe object of Tic Tac Toe is to get three in a row.\n" 
	    <<"\t\tYou play on a three by three game board. The first player\n"
	    <<"\t\tis known as X and the second is O. Players alternate placing\n" 
	    <<"\t\tXs and Os on the game board until either oppent has three in\n"
	    <<"\t\ta row or all nine squares are filled.\n\n\n\n\n\n\n\n";
	//calls scoreBoard function
	scoreBoard(First_Player, Game_total, Second_Player);
	
	
	

	cout<<"\t\t\t       1          2          3\n\n\n";
    cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t1      "<<board[0][0]<<"     |     "<<board[0][1]<<"    |   "<<board[0][2]<<"\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t   __________|__________|__________\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t2      "<<board[1][0]<<"     |    "<<board[1][1]<<"     |   "<<board[1][2]<<"\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t   __________|__________|__________\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t3      "<<board[2][0]<<"     |    "<<board[2][1]<<"     |   "<<board[2][2]<<"\n";
	cout<<"\t\t\t             |          |\n";
	cout<<"\t\t\t             |          |\n";
	



} 