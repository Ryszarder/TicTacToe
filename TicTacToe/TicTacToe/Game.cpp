#include <crtdbg.h>
#include <iostream>

//These are so the code reads the functions so they can be wrote below the main function
void Print_board(char board[3][3]);
char Winner(char board[3][3], char& winner);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//creates the 2d array and initialize the value of each array
	char board[3][3];
	board[0][0] = 'A';
	board[0][1] = 'B';
	board[0][2] = 'C';
	board[1][0] = 'D';
	board[1][1] = 'E';
	board[1][2] = 'F';
	board[2][0] = 'G';
	board[2][1] = 'H';
	board[2][2] = 'I';

	//Variables to switch betwwen the player who's playing
	bool x = true;
	bool o = false;

	//While loop to keep looping through the true till someone wins
	while (true)
	{
		//Clears the console screen
		system("cls");

		//Calls the print functionS
		Print_board(board);

		//Check if 'x' = true
		if (x == true)
		{
			//Variables that will store the array data input
			int row = 0;
			int col = 0;
			//Loops through entering code 
			while (true)
			{
				while (1)
				{
					//Ask for row and then passes it into the int row to store
					std::cout << "enter in row" << std::endl;
 					std::cin >> row;
					//If number enter smaller than two break to proceed
					if (row <= 2)
						break;
					//Else write message and loop again
					else
						std::cout << "try again" << std::endl;
				}
				while (1)
				{
					//Ask for row and then passes it into the int col to store
					std::cout << "enter in col" << std::endl;
					std::cin >> col;
					//If number enter smaller than two break to proceed
					if (col <= 2)
						break;
					//Else write message and loop again
					else
						std::cout << "try again" << std::endl;
				}
				//Checks the value in the array if it doesn't equal 'X' or 'O'
				if (board[row][col] != 'X' && board[row][col] != 'O')
				{
					//If not make that value equal 'X'
					board[row][col] = { 'X' };
					break;
				}
				//If value does equal 'X'
				else if (board[row][col] == 'X')
				{
					//Write message and redo entering
					std::cout << "spot takening try again" << std::endl;
				}
				//If value does equal 'O'
				else if (board[row][col] == 'O')
				{
					//Write message and redo entering
					std::cout << "spot takening try again" << std::endl;
				}
			}
			//While loop that checks when reach
			while (true)
			{
				//Creates variable that equals 'X'
				char winner = 'X';
				//Calls the Winner function and passes the board and winner variable in
				Winner(board, winner);
				//If nothing happens break the loop
				break;
			}
			//Changes the value of the bool of x to false and o to true to swap players turns
			x = false;
			o = true;
		}

		//Check if the first if statement is false if o = true
		else if (o == true)
		{
			//Variables that will store the array data input
			int row = 0;
			int col = 0;

			//While loop entering code
			while (true)
			{
				while (1)
				{
					//Ask for row and then passes it into the int row to store
					std::cout << "enter in row" << std::endl;
					std::cin >> row;
					//If number enter smaller than two break to proceed
					if (row <= 2)
						break;
					//Else write message and loop again
					else
						std::cout << "try again" << std::endl;
				}
				while (1)
				{
					//Ask for row and then passes it into the int col to store
					std::cout << "enter in col" << std::endl;
					std::cin >> col;
					//If number enter smaller than two break to proceed
					if (col <= 2)
						break;
					//Else write message and loop again
					else
						std::cout << "try again" << std::endl;
				}

				//Checks the value in the array if it doesn't equal 'O' or 'x'
				if (board[row][col] != 'O' && board[row][col] != 'X')
				{
					//If not make that value equal 'X'
					board[row][col] = { 'O' };
					break;
				}
				//If value does equal 'O'
				else if (board[row][col] == 'O')
				{
					//Write message and redo entering
					std::cout << "spot takening try again" << std::endl;
				}
				//If value does equal 'X'
				else if (board[row][col] == 'X')
				{
					//Write message and redo entering
					std::cout << "spot takening try again" << std::endl;
				}
			}
			//While loop that checks when reach
			while (true)
			{
				//Creates variable that equals 'X'
				char winner = 'O';
				//Calls the Winner function and passes the board and winner variable in
				Winner(board, winner);
				//If nothing happens break the loop
				break;
			}
			//Changes the value of the bool of x to false and o to true to swap players turns
			x = true;
			o = false;
		}
	}

	return 0;
}

//Function that prints out the array in the console
void Print_board(char board[3][3])
{
	std::cout << "\n------------------\n";
	std::cout << "\n  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2];
	std::cout << "\n------------------\n";
	std::cout << "\n  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2];
	std::cout << "\n------------------\n";
	std::cout << "\n  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2];
	std::cout << "\n------------------\n";
}

//Function that Check to see if the won
char Winner(char board[3][3], char& winner)
{
	//Checks for horizontal:
	for (int i = 0; i < 2; i++)
		//Checks that the first value eqauls the second and the second equals the thrid
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			//If it does winner now equals the value in [i][0]
			winner = board[i][0];
			//Prints out the winner
			std::cout << "Winner is " << winner << std::endl;
			//Quits the program
			exit(0);
		}

	//Checks for vertical:
	for (int i = 0; i < 2; i++)
		//Checks that the first value eqauls the second and the second equals the thrid
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{	
			//If it does winner now equals the value in [i][0]
			winner = board[0][1];
			//Prints out the winner
			std::cout << "Winner is " << winner << std::endl;
			//Quits the program
			exit(0);
		}

	//Checks for diagnol:
	//Checks that the first value eqauls the second and the second equals the thrid
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
		(board[0][2] == board[1][1] && board[1][1] == board[2][0]))
	{
		//If it does winner now equals the value in [i][0]
		winner = board[1][1];
		//Prints out the winner
		std::cout << "Winner is " << winner << std::endl;
		//Quits the program
		exit(0);
	}

	return 0;
}
