#include "board.hpp"

int nQueen(Board board, int j, int queens, int *res)
{
    if (queens == board.getSize())
    {
        (*res)++;
        std::cout << std::endl;
        board.display();
        return (0);
    }
    for (int i = 0 ; i < board.getSize() ; i++)
    {
        if (board.getCell(j, i) == 0 && board.isSafe(j, i))
        {
            board.setCell(j, i, 'N');
            if (nQueen(board, j+1, queens + 1, res))
                return (1);
            board.setCell(j, i, 0);
        }
    }
    return (0);
}

int main()
{
    int n = 10;
    int res = 0;
    Board board(n);

    nQueen(board, 0, 0, &res);
    std::cout << res << std::endl;
}