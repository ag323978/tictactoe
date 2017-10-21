/*
  Author: Aryan Gupta
  Date: 10/20/17
  This program allows two users to play Tic Tac Toe against each other and keeps track of how many 
  times they have won until they don't want to play anymore
 */

#include <iostream>

using namespace std;

// method prototypes
void drawBoard();
void resetBoard();
void playerTurn(char & player);
bool gameFinish(bool & tie);

// game board array
char board[3][3] = {{'1','2','3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// main method
int main() {

  // used to keep track of turns
  char turn;
  // used to check for ties
  bool draw = false;

  // used to see if users want to keep playing
  bool stillPlaying = true;
  char answer = 'y';

  // keeps track of score
  int xWins = 0;
  int oWins = 0;
  
  cout << "Tic Tac Toe \n";
  cout << "Player 1 [X] == Player 2 [O]\n";
  turn = 'X';

  // keep playing while users still want to play
  while (stillPlaying == true) {
    // keep playing while game hasn't reached a draw
    while (!gameFinish(draw))
    {
      drawBoard();
      playerTurn(turn);
      gameFinish(draw);   
    }

    // if it's O's turn and the game isn't in a draw
    if (turn == 'O' && !draw) {
      drawBoard();
      xWins++;
      // X has won
      cout << endl << endl << "Player 1 [X] Wins! Game Over.\n";
      cout << "[X] has won " << xWins << " times and [O] has won " << oWins << " times." << endl;
      // ask users if they want to play again
      cout << endl << "Would you like to play again? Answer with y/n ";
      cin >> answer;
      // if so reset board and start a new game
      if (answer == 'y') {
	stillPlaying = true;
	cout << "New game" << endl;
	resetBoard();
	turn = 'X';
      } // otherwise terminate
      else if (answer == 'n') {
	cout << "Goodbye" << endl;
	stillPlaying == false;
	break;
      } // if none are true than the user didn't type y or n
      else {
	// keep doing till they type y or n
	while (answer != 'y' && answer != 'n') {
	  cout << "Please type either y/n ";
	  cin >> answer;
	}
	// if they finally type y then reset board
	if (answer == 'y') {
	  resetBoard();
	  turn = 'X';
	} // otherwise exit loop and terminate program
	else {
	  cout << "Goodbye" << endl;
	  break;
	}
      }
    } // same logic as above but for X
    else if (turn == 'X' && !draw) {
        drawBoard();
	oWins++;
	cout << endl << endl << "Player 2 [O] Wins! Game Over.\n";
	cout << "[X] has won " << xWins << " times and [O] has won " << oWins << " times." << endl;
	cout << endl << "Would you like to play again? Answer with y/n ";
	cin >> answer;
	if (answer == 'y') {
	  stillPlaying = true;
	  cout << "New game" << endl;
	  resetBoard();
	  turn = 'X';
	} else if (answer == 'n') {
	  cout << "Goodbye" << endl;
	  stillPlaying = false;
	  break;
	} else {
	  while (answer != 'y' && answer != 'n') {
	    cout << "Please type either y/n ";
	    cin >> answer;
	  }
	  if (answer == 'y') {
	    resetBoard();
	    turn = 'X';
	  } else {
	    cout << "Goodbye" << endl;
	    break;
	  }
	}
    } // if neither X or O has won then its a tie
    else {
        drawBoard();
	cout << endl << endl << "It's a tie! Game Over.\n";
	cout << "[X] has won " << xWins << " times and [O] has won " << oWins << " times." << endl;
	cout << endl << "Would you like to play again> Answer with y/n ";
	cin >> answer;
	if (answer == 'y') {
	  stillPlaying = true;
	  cout << "New game" << endl;
	  resetBoard();
	  turn = 'X';
	} else if (answer == 'n') {
	  cout << "Goodbye" << endl;
	  stillPlaying = false;
	  break;
	} else {
	  while (answer != 'y' && answer != 'n') {
	    cout << "Please type either y/n ";
	    cin >> answer;
	  }
	  if (answer == 'y') {
	    resetBoard();
	    turn = 'X';
	  } else {
	    cout << "Goodbye" << endl;
	    break;
	  }
	}
    }
  }
}

// draws the game board
void drawBoard() {

  cout << "------------------------" << endl << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
  cout << "     |     |     " << endl;
  
}

// clears the game board
void resetBoard() {

  board[0][0] = '1';
  board[0][1] = '2';
  board[0][2] = '3';
  board[1][0] = '4';
  board[1][1] = '5';
  board[1][2] = '6';
  board[2][0] = '7';
  board[2][1] = '8';
  board[2][2] = '9';
  
}

// plays a move for X or O depending on what turn equals
void playerTurn(char & player) {

  int move;
  int row = 0, column = 0;

  if (player == 'X') {
    cout << "Player 1 turn [X]: ";
  } else if (player == 'O') {
    cout << "Player 2 turn [O]: ";
  }

  cin >> move;

  // check for illegal moves
  switch (move) {

    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
      cout << "Illegal move. Try again\n";
      playerTurn(player);
  }

  // if the spot the user chose is empty
  // play whoever's turn it is and change the player
  if (player == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
    board[row][column] = 'X';
    player = 'O';
  } else if (player == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
    board[row][column] = 'O';
    player = 'X';
  } // if its not empty tell the user the spot is taken
  else {
    cout << "The cell you chose was already played on! Try again\n";
    playerTurn(player);
  }
}

// checks for wins and ties
bool gameFinish(bool & tie) {

  // check for a win
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
      return true;
    }
  }

  // check for a tie
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
	return false;
      }
    }
  }
  tie = true;
  return true;
}
  
  
  












