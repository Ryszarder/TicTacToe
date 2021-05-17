#include <crtdbg.h>
#include <iostream>

void Print_board(char board[3][3]);
char Winner(char board[3][3], char& winner);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
	char restart;
	bool x = true;
	bool y = false;

	while (true)
	{
		system("cls");
		Print_board(board);

		if (x == true)
		{
			
			int row = 0;
			int col = 0;
			while (true)
			{
				while (1)
				{
					std::cout << "enter in row" << std::endl;
 					std::cin >> row;
					if (row <= 2)
						break;
					else
						std::cout << "try again" << std::endl;
				}
				while (1)
				{
					std::cout << "enter in col" << std::endl;
					std::cin >> col;
					if (col <= 2)
						break;
					else
						std::cout << "try again" << std::endl;
				}
				if (board[row][col] != 'X' && board[row][col] != 'O')
				{
					board[row][col] = { 'X' };
					break;
				}
				else if (board[row][col] == 'X')
				{
					std::cout << "spot takening try again" << std::endl;
				}
				else if (board[row][col] == 'O')
				{
					std::cout << "spot takening try again" << std::endl;
				}
			}
			while (true)
			{
				char winner = 'X';
				Winner(board, winner);
				break;
			}
			x = false;
			y = true;
		}

		else if (y == true)
		{
			int row = 0;
			int col = 0;

			while (true)
			{
				while (1)
				{
					std::cout << "enter in row" << std::endl;
					std::cin >> row;
					if (row <= 2)
						break;
					else
						std::cout << "try again" << std::endl;
				}
				while (1)
				{
					std::cout << "enter in col" << std::endl;
					std::cin >> col;
					if (col <= 2)
						break;
					else
						std::cout << "try again" << std::endl;
				}
				if (board[row][col] != 'O' && board[row][col] != 'X')
				{
					board[row][col] = { 'O' };
					break;
				}
				else if (board[row][col] == 'O')
				{
					std::cout << "spot takening try again" << std::endl;
				}
				else if (board[row][col] == 'X')
				{
					std::cout << "spot takening try again" << std::endl;
				}
			}

			while (true)
			{
				char winner = 'O';
				Winner(board, winner);
				break;
			}
			x = true;
			y = false;
		}
	}

	return 0;
}


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

char Winner(char board[3][3], char& winner)
{
	// Checks for horizontal:
	for (int i = 0; i < 2; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			winner = board[i][0];
			std::cout << "Winner is " << winner << std::endl;
			exit(0);
		}

	// Checks for vertical:
	for (int i = 0; i < 2; i++)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{	
			winner = board[0][1];
			std::cout << "Winner is " << winner << std::endl;
			exit(0);
		}

	// Checks for diagnol:
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
		(board[0][2] == board[1][1] && board[1][1] == board[2][0]))
	{
		winner = board[1][1];
		std::cout << "Winner is " << winner << std::endl;
		exit(0);
	}

	return 0;
}
