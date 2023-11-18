#include <bits/stdc++.h>
using namespace std;

char board[3][3];

// setting up the game board
void initBoard(){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
//        initially, all places are empty
            board[i][j] = ' ';
}

// function to display the game board
void displayBoard(){
    cout << "  1  2  3 \n" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
            {
                cout << " |";
            }
        }
        cout << "\n";
        if (i < 2){
            cout << "  --+--+-- " << endl;
        }
    }
    cout << endl;
}

// function to get the input from the current player
void getPlayerInput(char symbol){
    int row, col;
    bool valid;
    do
    {
        cout << "Player " << symbol << ", enter your move (row and column): ";
        cin >> row >> col;
        valid = (row >= 1 && row <= 3) && (col >= 1 && col <= 3) && (board[row - 1][col - 1] == ' ');
        if (!valid){
            cout << "Invalid move. Try again." << endl;
        }
    } while (!valid);
    board[row - 1][col - 1] = symbol;
}

// function to check if a player has won the game
bool isWinning(char symbol){
    // Check rows
    for (int i = 0; i < 3; i++){
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol){
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++){
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol){
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol){
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol){
        return true;
    }
    // No win
    return false;
}

// function to check if the game is a draw
bool isDraw(){
    // Check if the board is full
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == ' '){
                return false;
            }
        }
    }
    // The board is full and no one has won
    return true;
}

// function to switch the player symbol
char switchPlayer(char symbol){
    if (symbol == 'X'){
        return 'O';
    }
    else{
        return 'X';
    }
}

// function to play the game
void playGame(){
    // Initialize the game board
    initBoard();

    // Declare a variable to store the current player symbol
    char currentPlayer = 'X';

    // Declare a variable to store the game status
    bool gameOver = false;

    // Print a welcome message
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    // Repeat until the game is over
    while (!gameOver){
        // Display the game board
        displayBoard();

        // Get the input from the current player
        getPlayerInput(currentPlayer);

        // Check if the current player has won the game
        if (isWinning(currentPlayer)){
            // Display the game board
            displayBoard();

            // Print a congratulatory message
            cout << "Player " << currentPlayer << " has won the game!\n";

            // End the game
            gameOver = true;
        }
        // Check if the game is a draw
        else if (isDraw()){
            // Display the game board
            displayBoard();

            // Print a draw message
            cout << "The game is a draw.\n";

            // End the game
            gameOver = true;
        }
        // Switch the player
        else{
            currentPlayer = switchPlayer(currentPlayer);
        }
    }
}

// function to ask if the players want to play again
bool playAgain(){
    char choice;

    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;

    // Return true if the choice is Y or y, false otherwise
    return (choice == 'Y' || choice == 'y');
}

int main(){
    bool keepPlaying = true;

    while(keepPlaying){
        playGame();

        // Ask if the user wants to play again
        keepPlaying = playAgain();
    }
	cout << endl;
    cout << "Thank you for playing Tic-Tac-Toe. The Game is over!!" << endl;

    return 0;
}

