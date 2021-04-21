#include <crtdbg.h>
#include <iostream>

void Print_board(char board[3][3]);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



	char board[3][3];
	/*Print_board(board);*/

	while (true)
	{
		system("cls");
		Print_board(board);

		int row = 0;
		while (1)
		{
			std::cout << "enter in row" << std::endl;
			std::cin >> row;
			if (row <= 2)
				break;
			else
				std::cout << "try again" << std::endl;
		}

		int col = 0;
		while (1)
		{

			std::cout << "enter in col" << std::endl;
			std::cin >> col;
			if (col <= 2)
				break;
			else
				std::cout << "try again" << std::endl;
		}

		if (board[row][col] != 'X')
		{
			board[row][col] = { 'X' };
		}
		if (board[row][col] == 'X')
		{
			std::cout << "spot takening try again" << std::endl;
		}

		//std::cin.ignore();
		//std::cin.clear();

		getchar();
	}

	getchar();

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