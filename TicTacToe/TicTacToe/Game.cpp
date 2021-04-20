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
		
		if (true)
		{
			int row;
			std::cout << "enter in row" << std::endl;
			std::cin >> row;

			int col;
			std::cout << "enter in col" << std::endl;
			std::cin >> col;

			board[row][col] = {'X'};
			delete board[row];
			delete board[col];
		}



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