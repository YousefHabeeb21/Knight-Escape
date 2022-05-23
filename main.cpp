 /*
   The objective of this game is to get the white knight to the empty
	square in the upper right-hand corner of the board.
	
	The knight can only move in the way that it does during a traditional
	chess game. This means that a knight can only move in a valid L-shape
	(two squares in a horizontal direction, then one in a vertical direction OR 
	two squares in a vertical direction, then one in a horizontal direction).
		       
  
    
 ---------------------------------------------*/

#include <iostream>		// for input and output
#include <cctype>		   // for toupper()
using namespace std;

// Global variables for the pieces are allowed for this program,
// but will generally not be allowed in the future.
// You will likely want to declare global variables at least for the 25 board positions.
// ...

// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = "\u2658";		// White knight character
const string BlackKnight = "\u265E";		// Black knight character
const string BlankPosition = " ";			// Blank position character
string p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25;
int startingPos;
int endingPos;
int x = 0;
int score = 500;
char menuOption;
int moveNumber = 1;
//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage()
{
    cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n"
         << " \n"
         << "The objective of this puzzle is to get the white knight "
		 << "up to the empty square in the top right corner of the board. "
		 << "Use standard knight moves from a traditional chess game, "
		 << "where a knight moves in an L-shape. \n"
		 << "This means that a knight can only move either "
		 << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
		 << "2) two squares in a vertical direction, then one in a horizontal direction."
		 << " \n"
		 << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
		 << "Try to complete the puzzle with the smallest number of valid moves!"
    	 << endl;
}//end displayWelcomeMessage()

// checks if the position has a knight 
bool fromCheck(int s){
  bool b;
  switch(s){
    case 1: {(p1 == BlackKnight || p1 == WhiteKnight)? b = 1 : b = 0; break;}
    case 2: {(p2 == BlackKnight || p3 == WhiteKnight)? b = 1 : b = 0; break;}
    case 3: {(p3 == BlackKnight || p3 == WhiteKnight)? b = 1 : b = 0; break;}
    case 4: {(p4 == BlackKnight || p4 == WhiteKnight)? b = 1 : b = 0; break;}
    case 5: {(p5 == BlackKnight || p5 == WhiteKnight)? b = 1 : b = 0; break;} 
    case 6: {(p6 == BlackKnight || p6 == WhiteKnight)? b = 1 : b = 0; break;}
    case 7: {(p7 == BlackKnight || p7 == WhiteKnight)? b = 1 : b = 0; break;}
    case 8: {(p8 == BlackKnight || p8 == WhiteKnight)? b = 1 : b = 0; break;}
    case 9: {(p9 == BlackKnight || p9 == WhiteKnight)? b = 1 : b = 0; break;}
    case 10:{(p10 == BlackKnight || p10 == WhiteKnight)? b = 1 : b = 0; break;}
    case 11:{(p11 == BlackKnight || p11 == WhiteKnight)? b = 1 : b = 0; break;}
    case 12:{(p12 == BlackKnight || p12 == WhiteKnight)? b = 1 : b = 0; break;}
    case 13:{(p13 == BlackKnight || p13 == WhiteKnight)? b = 1 : b = 0; break;}    
    case 14:{(p14 == BlackKnight || p14 == WhiteKnight)? b = 1 : b = 0; break;}   
    case 15:{(p15 == BlackKnight || p15 == WhiteKnight)? b = 1 : b = 0; break;}   
    case 16:{(p16 == BlackKnight || p16 == WhiteKnight)? b = 1 : b = 0; break;}
    case 17:{(p17 == BlackKnight || p17 == WhiteKnight)? b = 1 : b = 0; break;}    
    case 18:{(p18 == BlackKnight || p18 == WhiteKnight)? b = 1 : b = 0; break;}   
    case 19:{(p19 == BlackKnight || p19 == WhiteKnight)? b = 1 : b = 0; break;}
    case 20:{(p20 == BlackKnight || p20 == WhiteKnight)? b = 1 : b = 0; break;} 
    case 21:{(p21 == BlackKnight || p21 == WhiteKnight)? b = 1 : b = 0; break;}   
    case 22:{(p22 == BlackKnight || p22 == WhiteKnight)? b = 1 : b = 0; break;}
    case 23:{(p23 == BlackKnight || p23 == WhiteKnight)? b = 1 : b = 0; break;}
    case 24:{(p24 == BlackKnight || p24 == WhiteKnight)? b = 1 : b = 0; break;}
    case 25:{(p25 == BlackKnight || p25 == WhiteKnight)? b = 1 : b = 0; break;}
  } 
  return b;
}
    
//checks if the ending position is empty 
bool toCheck(int e){
  bool a;
  switch(e){
  case 1: {p1 == BlankPosition ? a = 1 : a = 0; break;}
  case 2: {p2 == BlankPosition ? a = 1 : a = 0; break;}
  case 3: {p3 == BlankPosition ? a = 1 : a = 0; break;}
  case 4: {p4 == BlankPosition ? a = 1 : a = 0; break;}
  case 5: {p5 == BlankPosition ? a = 1 : a = 0; break;}
  case 6: {p6 == BlankPosition ? a = 1 : a = 0; break;}
  case 7: {p7 == BlankPosition ? a = 1 : a = 0; break;}
  case 8: {p8 == BlankPosition ? a = 1 : a = 0; break;}
  case 9: {p9 == BlankPosition ? a = 1 : a = 0; break;}
  case 10: {p10 == BlankPosition ? a = 1 : a = 0; break;}
  case 11: {p11 == BlankPosition ? a = 1 : a = 0; break;}
  case 12: {p12 == BlankPosition ? a = 1 : a = 0; break;}
  case 13: {p13 == BlankPosition ? a = 1 : a = 0; break;}
  case 14: {p14 == BlankPosition ? a = 1 : a = 0; break;}
  case 15: {p15 == BlankPosition ? a = 1 : a = 0; break;}
  case 16: {p16 == BlankPosition ? a = 1 : a = 0; break;}
  case 17: {p17 == BlankPosition ? a = 1 : a = 0; break;}
  case 18: {p18 == BlankPosition ? a = 1 : a = 0; break;}
  case 19: {p19 == BlankPosition ? a = 1 : a = 0; break;}
  case 20: {p20 == BlankPosition ? a = 1 : a = 0; break;}
  case 21: {p21 == BlankPosition ? a = 1 : a = 0; break;}
  case 22: {p22 == BlankPosition ? a = 1 : a = 0; break;}
  case 23: {p23 == BlankPosition ? a = 1 : a = 0; break;}
  case 24: {p24 == BlankPosition ? a = 1 : a = 0; break;}
  case 25: {p25 == BlankPosition ? a = 1 : a = 0; break;}
  } return a;
}
//moves the white knight to a specific location
void moveWhite (int w){
    switch (w){
      case 1: { p1 = WhiteKnight; break;}
      case 2: { p2 = WhiteKnight; break;}
      case 3: { p3 = WhiteKnight; break;}
      case 4: { p4 = WhiteKnight; break;}
      case 5: { p5 = WhiteKnight; break;}
      case 6: { p6 = WhiteKnight; break;}
      case 7: { p7 = WhiteKnight; break;}
      case 8: { p8 = WhiteKnight; break;}
      case 9: { p9 = WhiteKnight; break;}
      case 10: { p10 = WhiteKnight; break;}
      case 11: { p11 = WhiteKnight; break;}
      case 12: { p12 = WhiteKnight; break;}
      case 13: { p13 = WhiteKnight; break;}
      case 14: { p14 = WhiteKnight; break;}
      case 15: { p15 = WhiteKnight; break;}
      case 16: { p16 = WhiteKnight; break;}
      case 17: { p17 = WhiteKnight; break;}
      case 18: { p18 = WhiteKnight; break;}
      case 19: { p19 = WhiteKnight; break;}
      case 20: { p20 = WhiteKnight; break;}
      case 21: { p21 = WhiteKnight; break;}
      case 22: { p22 = WhiteKnight; break;}
      case 23: { p23 = WhiteKnight; break;}
      case 24: { p24 = WhiteKnight; break;}
      case 25: { p25 = WhiteKnight; break;}
  }
}
// moves the black knight to a specific location
void moveBlack (int b){
    switch (b){
      case 1: { p1 = BlackKnight; break;}
      case 2: { p2 = BlackKnight; break;}
      case 3: { p3 = BlackKnight; break;}
      case 4: { p4 = BlackKnight; break;}
      case 5: { p5 = BlackKnight; break;}
      case 6: { p6 = BlackKnight; break;}
      case 7: { p7 = BlackKnight; break;}
      case 8: { p8 = BlackKnight; break;}
      case 9: { p9 = BlackKnight; break;}
      case 10: { p10 = BlackKnight; break;}
      case 11: { p11 = BlackKnight; break;}
      case 12: { p12 = BlackKnight; break;}
      case 13: { p13 = BlackKnight; break;}
      case 14: { p14 = BlackKnight; break;}
      case 15: { p15 = BlackKnight; break;}
      case 16: { p16 = BlackKnight; break;}
      case 17: { p17 = BlackKnight; break;}
      case 18: { p18 = BlackKnight; break;}
      case 19: { p19 = BlackKnight; break;}
      case 20: { p20 = BlackKnight; break;}
      case 21: { p21 = BlackKnight; break;}
      case 22: { p22 = BlackKnight; break;}
      case 23: { p23 = BlackKnight; break;}
      case 24: { p24 = BlackKnight; break;}
      case 25: { p25 = BlackKnight; break;}
  }
}

//moves the black or white knight to an empty position
void moveBlackandWhite (int m){
  switch (m){
    case 1: {p1 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p1 = BlankPosition; break;}
    case 2: {p2 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p2 = BlankPosition; break;}
    case 3: {p3 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p3 = BlankPosition; break;}
    case 4: {p4 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p4 = BlankPosition; break;}
    case 5: {p5 != WhiteKnight ? moveBlack(endingPos):moveWhite(endingPos); p5 = BlankPosition; break;}
    case 6: {p6 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p6 = BlankPosition; break;}
    case 7: {p7 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p7 = BlankPosition; break;}
    case 8: {p8 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p8 = BlankPosition; break;}
    case 9: {p9 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p9 = BlankPosition; break;}
    case 10: {p10 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p10 = BlankPosition; break;}
    case 11: {p11 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p11 = BlankPosition; break;}
    case 12: {p12 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p12 = BlankPosition; break;}
    case 13: {p13 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p13 = BlankPosition; break;}
    case 14: {p14 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p14 = BlankPosition; break;}
    case 15: {p15 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p15 = BlankPosition; break;}
    case 16: {p16 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p16 = BlankPosition; break;}
    case 17: {p17 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p17 = BlankPosition; break;}
    case 18: {p18 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p18 = BlankPosition; break;}
    case 19: {p19 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p19 = BlankPosition; break;}
    case 20: {p20 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p20 = BlankPosition; break;}
    case 21: {p21 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p21 = BlankPosition; break;}
    case 22: {p22 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p22 = BlankPosition; break;}
    case 23: {p23 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p23 = BlankPosition; break;}
    case 24: {p24 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p24 = BlankPosition; break;}
    case 25: {p25 != WhiteKnight ? moveBlack(endingPos): moveWhite(endingPos); p25 = BlankPosition; break;}
  }
}
// checks if the move is a valid L shape 
void validMove(int first, int second, bool &valid){
  //direction of movements based on integers locations on the board
  int s = first - 11;
  int t = first - 7;        
  int u = first - 9;
  int v = first - 3;
  int w = first + 11;
  int x = first + 7;
  int y = first + 9;
  int z = first + 3;
  valid = 0;

  if (first == 21||first == 16||first == 11||first == 10||first == 9||first == 8||first == 7||first == 6||first == 5||first == 4||first == 3||first == 2||first == 1){ 
    s = 0;
  }
  if (first == 22||first == 21||first == 17||first == 16||first == 12||first == 11||first == 7||first == 6||first == 5||first == 4||first == 3||first == 2||first == 1){
    t = 0;
  }
  if (first == 25||first == 20||first == 15||first == 10||first == 9||first == 8||first == 7||first == 6||first == 5||first == 4||first == 3||first == 2||first == 1){
    u = 0;
  }
  if(first == 25||first == 24||first == 20||first == 19||first == 15||first == 14||first == 10||first == 9||first == 5||first == 4||first == 3||first == 2||first == 1){
    v = 0;
  }
  if(first == 25||first == 24||first == 23||first == 22||first == 21||first == 20||first == 19||first == 18||first == 17||first == 16||first == 15||first == 10||first == 5){
    w = 0;
  }
  if(first == 25||first == 24||first == 23||first == 22||first == 21||first == 20||first == 19||first == 15||first == 14||first == 10||first == 9||first == 5||first == 4){
    x = 0;
  }
  if(first == 25||first == 24||first == 23||first == 22||first == 21||first == 20||first == 19||first == 18||first == 17||first == 16||first == 11||first == 6||first == 1){
    y = 0;
  }
  if(first == 25||first == 24||first == 23||first == 22||first == 21||first == 17||first == 16||first == 12||first == 11||first == 7||first == 6||first == 2||first == 1){
    z = 0;
  } 
  if (second == s || second == t || second == u || second == v || second == w || second == x || second == y || second == z){
    valid = true;
  }
}

// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
// This function makes use of global variables p1..p25, which represent
// each of the positions on the board
void displayBoard(){
    cout <<"\n"
         <<               "    Board   " <<                               "      Position \n"
         << " " <<  p1 << " " <<  p2 << " " <<  p3 << " " <<  p4 << " " <<  p5 << "     1  2  3  4  5 \n"
         << " " <<  p6 << " " <<  p7 << " " <<  p8 << " " <<  p9 << " " << p10 << "     6  7  8  9 10 \n"
         << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n"
         << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20<<"    16 17 18 19 20 \n"
         << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n"
         << endl;
} //end displayBoard()


// ----------------------------------------------------------------------


// Main() function of the program, containing the loop that controls
// game play

// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {




   
  displayWelcomeMessage();
	
	// Set board values to the default starting position
   // ...


  p21 = WhiteKnight; // sets whiteknight position to p21
  p5 = BlankPosition; //sets p5 to a blank position
  p1 = BlackKnight, p2 = p1,p3 = p1,p4 = p1,p6 = p1,p7 = p1,p8 = p1,p9 = p1,p10 = p1,p11 = p1,p12 = p1,p13 = p1,p14 = p1,p15 = p1,p16 = p1,p17 = p1,p18 = p1,p19 = p1,p20 = p1,p22 = p1,p23 = p1,p24 = p1,p25 = p1;
	// sets blackknight to positions to all positions other than p21 and p5

  displayBoard();
  cout << "Current score: " << score << endl;
   
   // Loop that controls game play
  while(x!=1) {
    cout << moveNumber << ". "
             << "Enter one of the following: \n"
			 << "  - M to move a knight from one position to another, \n"
			 << "  - R to reset the board back to the beginning, or \n"
			 << "  - X to exit the game. \n"
			 << "Your choice -> ";
		cin >> menuOption;
		menuOption = toupper(menuOption);
     // convert user input to uppercase
		
		// If the user entered 'X' to exit,
		// break out of this loop that controls game play
		// ...
    if (menuOption == 'X'){
      cout << "Exiting..."<<endl;
      break;
    }
		
		// If the user entered 'R' to reset,
		// reset the board back to the beginning
		// ...
		if (menuOption == 'R'){ 

      p1 = BlackKnight, p2 = p1,p3 = p1,p4 = p1,p6 = p1,p7 = p1,p8 = p1,p9 = p1,p10 = p1,p11 = p1,p12 = p1,p13 = p1,p14 = p1,p15 = p1,p16 = p1,p17 = p1,p18 = p1,p19 = p1,p20 = p1,p22 = p1,p23 = p1,p24 = p1,p25 = p1;
      p21 = WhiteKnight;
      p5 = BlankPosition;
      
      // resets all the positions of the pieces 
      cout <<  "   *** Restarting" ;
      score = 500;//resets the score
      moveNumber = 1;
      displayBoard();
      cout << "Current score: " << score << endl;


    }
		// If the user entered 'M' to move a knight,
		// ask for the position of the knight to be moved
		// ...
    if (menuOption == 'M'){
      cout << "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5): ";
      cin >> startingPos >> endingPos;

      cout << "You have chosen to move a knight from position " << startingPos << " to position " << endingPos<<"." << endl;
      
      //checks if the given input is within the range of 1-25
      if ((startingPos >= 1 && startingPos <= 25) && (endingPos >= 1 && endingPos <= 25)){


        bool valid;
        
        // checks if the starting position is valid
        if (fromCheck(startingPos)) {
          
          //checks if the ending position is valid 
          if (toCheck(endingPos)) {
            
            //checks if the move is an L shape
            validMove (startingPos, endingPos, valid);
            if (valid) {
              
              //moves the peice
              moveBlackandWhite (startingPos);
              displayBoard();
            
            //winning condition
              if (p5 == WhiteKnight){
               cout <<"Congratulations, you did it!" << endl;
               break;
              }
              //score decreases evry move: if invalid then it decreases by 10
              moveNumber += 1;
              score-=5;
              cout<<"Current score: "<<score<<endl;
            } else {
             // if the move isnt an L shape then it is invalid
              cout << "Invalid move. Knights can only move in an L-shape. Try again.";
              score-=10;
              cout<<endl <<"Current score: "<<score<<endl;

            }
          } 
          else {
            // if the destination isnt empty then it is invalid
            cout << "The destination position should be empty. Try again.";
            score-=10;
            cout<<endl <<"Current score: "<<score<<endl;

          }
        } else {
          // if the start position doesnt have a knight it is invalid 
          cout << "The source position should have a knight. Try again.";
          score-=10;
          cout<<endl <<"Current score: "<<score<<endl;

        }

      } 
          //invalid positioning reaction
      else if (startingPos < 1 || startingPos > 25) {
        
        cout << "The source position should be a valid position on the board (1-25). Try again.";
        score-=10;
        cout<<endl <<"Current score: "<<score<<endl;

      } else if (endingPos < 1 || endingPos > 25){
       
        cout << "The destination position should be a valid position on the board (1-25). Try again.";
        score-=10;
        cout<<endl <<"Current score: "<<score<<endl;

      }
      
      if (score <=0){
       x += 1;
       break;
    }
    }
  } // end loop for game play
  if(score<=0){
    cout<<endl<<endl<<"You have run out of moves. Try to do better next time!"<<endl;
  }
  cout << "Thank you for playing!" << endl; // 
  //stops the loop
  x = x+1;
	return 0;
}
